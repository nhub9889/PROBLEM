class Singleton
{
    private:
    static Singleton*_instance;// đối tượng duy nhất


    Singleton();// phương thức tạo lập

    public:
    //phương thức lấy đối tượng duy nhất
    static Singleton*getInstance();
};

//khởi tạo biến Singleton::_instance = NULL;
Singleton*Singleton::_instance = nullptr;
Singleton::Singleton()
{
    //định nghĩa phương thức tạo lập


}

Singleton*Singleton::getInstance()
{
    if(_instance == nullptr)
    _instance = new Singleton();
    return _instance;
}

int main()
{
    Singleton*object = Singleton::getInstance();
    //sử dụng object ...
    return 0;
}