#ifndef _SAFE_POINTERS_H
#define _SAFE_POINTERS_H
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

static int sizevoids  = sizeof(void*); //kích thước phần lưu của bản sao địa chỉ
static int headSize = sizevoids + sizeof(size_t);  //kích thước thông tin quản lý

static void markMem (void *pmem)   //đánh dấu vùng nhớ
{
    *(void**)pmem = pmem;  //pmem đã chứa một địa chỉ vung nhớ được dùng
}

static int checkMem (void*pmem)  //kiểm tra xem có phải vùng nhớ đánh dấu
{
    return (*(void**)pmem==pmem);
}


//--------mã hoá địa chỉ bộ nhớ---------//

    static unsigned long CodeWord = 0xADEADBEE;   //một giá trị địa chỉ tuỳ ý

    static void markMen (void* pmem)  //giả định cho pmem là địa chỉ vùng nhơ cần dùng
    {
        *(unsigned long*)pmem = CodeWord^(unsigned long)pmem;
    }

    static int checMem(void *pmem)
    {
        unsigned long chkValue = CodeWord^(unsigned long)pmem;
        return (*(unsigned long*)pmem == chkValue);
    }

    int checkPtr(void*pdata)  //pdata chứ địa chỉ đầu của địa chỉ dữ liệ
    {
        void*pmem = (char*)pdata - headSize;  //tính lại địa chỉ gốc từ địa chỉ dữ liệu
        if (pdata==nullptr)
            return 0;
        return checkMem(pmem);
        
    }
//------------------------------------------------------//


size_t safeSize(void* pdata)
{
    if (pdata!=nullptr)
    {
        void *pmem = (char*)pdata - headSize;
        if (checkMem(pmem))
            return*(size_t*)((char*)pmem + sizevoids);
        else return 0; 
    }
    return 0;
}

//---------------function------------------//

void* safeMalloc (size_t szmem)   // szmem: kích thước bộ nhớ cần cấp phát
{
    size_t sz = szmem + headSize;  // xin thêm headSize chứa thông tin quản lý
    void* pmem = malloc(sz);
    if (pmem!=nullptr)
    {
        memset(pmem, 0 ,sz);
        markMem(pmem);   //đánh dấu *(void**)pnew = pnew;
        *(size_t*)((char*)pmem + sizevoids) = szmem;  //địa chỉ bộ nhơ của vùng dữ liệu
        return (char*)pmem + headSize;
    }
    return nullptr;
}
//-----end of function safeMalloc()


void safeFree(void* pdata)
{
    if (pdata != nullptr)
    {
        void* pmem = (char*)pdata - headSize;  //địa chỉ bộ nhớ gốc lúc cấp phát
        if (checkMem(pmem))
        {
            size_t sz = safeSize(pdata) + headSize;
            memset (pmem, 0 ,sz); //dọn vùng nhớ trước giải phóng
            free(pmem); 
        }
    }
}
//------end of function safeFree()


void* safeRealloc (void* pdata, size_t newsize)
{
    void *pmem, *pnew;
    if (newsize <= 0)
        return nullptr;
    if (pdata == nullptr)   //cấp phát mới nếu địa chỉ cũ là nullptr
    {
        return safeMalloc(newsize);
    }
    pmem = (char*)pdata - headSize;  //địa chỉ bộ nhớ gốc lúc cấp phát;
    if (!checkMem(pmem))
    {
        return nullptr;
    }
    pnew = realloc(pmem, newsize + headSize);   //thêm headSize chứ thông tin quna rlys
    if (pnew != nullptr)
    {
        markMem(pnew);
        *(size_t*)((char*)pnew + sizevoids) = newsize;
        pnew = (char*)pnew + headSize;
    }
    return pnew;
}
//------end of function safeRealloc()


#endif