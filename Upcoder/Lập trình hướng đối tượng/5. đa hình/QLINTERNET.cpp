//http://www.upcoder.xyz/'index.php/e2dbd8d2af15fd316cb1125bcc8cfba97baa8072b61a0db2332aea286ac8ce23/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'.9_'k7A-Ak79K7Lh.8khDj577.LA8g9c8ieM':Lw@IEA:1?ph$A:1?Cj$s:1?C2qi:_Zx2EAR_qC2$kRtPuBNv9/92ad2982b24ce4730ccc0cee89d1036ed1e32e41996c050953140664ccced917
#include <iostream>
using namespace std;

class KhachHang {
protected:
    string tenKhachHang;
    double thoiGianSuDung;
    int soMay;
    double donGia;

public: 
    KhachHang() {
        this->tenKhachHang = "";
        this->thoiGianSuDung = 0;
        this->soMay = 0;
        this->donGia = 0;
    }

    KhachHang(string tenKhachHang, double thoiGianSuDung, int soMay, double donGia) {
        this->tenKhachHang = tenKhachHang;
        this->thoiGianSuDung = thoiGianSuDung;
        this->soMay = soMay;
        this->donGia = donGia;
    }

    virtual double tienSuDung() = 0;

    virtual void hienThiThongTin() {
        cout << "Ho Ten: " << tenKhachHang << '\n';
        cout << "Thoi gian su dung: " << thoiGianSuDung << '\n';
        cout << "So may: " << soMay << '\n';
        cout << "So tien phai tra: " << tienSuDung() << "\n\n";
    }
};

class KhachHangVIP : public KhachHang {
private:
    double donGiaVIP;
public:
    KhachHangVIP() {
        this->donGiaVIP = 0;
    }

    KhachHangVIP(string tenKhachHang, double thoiGianSuDung, int soMay, double donGia, double donGiaVIP) :
        KhachHang(tenKhachHang, thoiGianSuDung, soMay, donGia) {
            this->donGiaVIP = donGiaVIP;
        }

    KhachHangVIP(const KhachHangVIP &other) {
        this->tenKhachHang = other.tenKhachHang;
        this->thoiGianSuDung = other.thoiGianSuDung;
        this->soMay = other.soMay;
        this->donGia = other.donGia;
        this->donGiaVIP = other.donGiaVIP;
    }

    virtual double tienSuDung() {
        if (thoiGianSuDung >= 4) return donGiaVIP * 4;
        else if (thoiGianSuDung < 4) return donGia * thoiGianSuDung; 
        return  0;
    }

    void hienThiThongTin() {
        cout << "Loai khach: VIP\n";
        KhachHang::hienThiThongTin();
        return;
    }
};

class KhachHangTX : public KhachHang {
private: 
    double heSoKhuyenMai;
public:
    KhachHangTX() {
        this->heSoKhuyenMai = 0;
    }

    KhachHangTX(string tenKhachHang, double thoiGianSuDung, int soMay, double donGia, double heSoKhuyenMai) :
        KhachHang(tenKhachHang, thoiGianSuDung, soMay, donGia) {
            this->heSoKhuyenMai = heSoKhuyenMai;
        }

    KhachHangTX(const KhachHangTX &other) {
        this->tenKhachHang = other.tenKhachHang;
        this->thoiGianSuDung = other.thoiGianSuDung;
        this->soMay = other.soMay;
        this->donGia = other.donGia;
        this->heSoKhuyenMai = other.heSoKhuyenMai;
    }

    virtual double tienSuDung() {
        return thoiGianSuDung*donGia - thoiGianSuDung*heSoKhuyenMai;
    }

    void hienThiThongTin() {
        cout << "Loai khach: TX\n";
        KhachHang::hienThiThongTin();
        return;
    }
};

class KhachHangKTX : public KhachHang {
private: 
    double dungLuongDownload;
    double donGiaDownload;
public:
    KhachHangKTX() {
        this->dungLuongDownload = 0;
        this->donGiaDownload = 0;
    }

    KhachHangKTX(string tenKhachHang, double thoiGianSuDung, int soMay, double donGia, double dungLuongDownload, double donGiaDownload) : 
        KhachHang(tenKhachHang, thoiGianSuDung, soMay, donGia) {
            this->dungLuongDownload = dungLuongDownload;
            this->donGiaDownload = donGiaDownload;
        }

    KhachHangKTX(const KhachHangKTX &other) {
        this->tenKhachHang = other.tenKhachHang;
        this->thoiGianSuDung = other.thoiGianSuDung;
        this->soMay = other.soMay;
        this->donGia = other.donGia;
        this->dungLuongDownload = other.dungLuongDownload;
        this->donGiaDownload = other.donGiaDownload;
    }

    virtual double tienSuDung() {
        return thoiGianSuDung*donGia + dungLuongDownload*donGiaDownload;
    }

    void hienThiThongTin() {
        cout << "Loai khach: KTX\n";
        KhachHang::hienThiThongTin();
        return;
    }
};

int main() {
   
    cin.tie(0);

    int n, donGia, donGiaVIP, donGiaDownload;
    cin >> n >> donGia >> donGiaVIP >> donGiaDownload;

    KhachHang* danhSachKhachHang[n];
    int index = 0; string kiHieu;

    while (cin >> kiHieu) {
        cin.ignore();
        string tenKhachHang; 
        double thoiGianSuDung;
        int soMay;

        getline(cin, tenKhachHang);
        cin >> thoiGianSuDung >> soMay;

        if (kiHieu == "VIP") {
            danhSachKhachHang[index++] = new KhachHangVIP(tenKhachHang, thoiGianSuDung, soMay, donGia, donGiaVIP);
        
        } else if (kiHieu == "TX") {
            double heSoKhuyenMai; cin >> heSoKhuyenMai;
            danhSachKhachHang[index++] = new KhachHangTX(tenKhachHang, thoiGianSuDung, soMay, donGia, heSoKhuyenMai);
        
        } else if (kiHieu == "KTX") {
            double dungLuongDownload; cin >> dungLuongDownload;
            danhSachKhachHang[index++] = new KhachHangKTX(tenKhachHang, thoiGianSuDung, soMay, donGia, dungLuongDownload, donGiaDownload);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << ". ";
        danhSachKhachHang[i]->hienThiThongTin();
        delete danhSachKhachHang[i];
    }

    return 0;
}