#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Vemaybay {
private:
    std::string tenchuyen;
    std::string ngaybay;
    int giave;
    
public:
    Vemaybay(const std::string& tenchuyen, const std::string& ngaybay, int giave) : tenchuyen(tenchuyen), ngaybay(ngaybay), giave(giave) {}
    
    int getgiave() const {
        return giave;
    }
    
    void Nhap() {
        std::cout << "Nhap ten chuyen: ";
        std::cin.ignore();
        std::getline(std::cin, tenchuyen);
        
        std::cout << "Nhap ngay bay: ";
        std::cin.ignore();
        std::getline(std::cin, ngaybay);
        
        std::cout << "Nhap gia ve: ";
        std::cin >> giave;
    }
    
    void Xuat() const {
        std::cout << "Ten chuyen: " << tenchuyen << std::endl;
        std::cout << "Ngay bay: " << ngaybay << std::endl;
        std::cout << "Gia ve: " << giave << std::endl;
    }
};

class Nguoi {
private:
    std::string hoten;
    std::string gioitinh;
    int tuoi;
    
public:
    Nguoi(const std::string& hoten, const std::string& gioitinh, int tuoi) : hoten(hoten), gioitinh(gioitinh), tuoi(tuoi) {}
    
    void Nhap() {
        std::cout << "Nhap ho ten: ";
        std::cin.ignore();
        std::getline(std::cin, hoten);
        
        std::cout << "Nhap gioi tinh: ";
        std::cin.ignore();
        std::getline(std::cin, gioitinh);
        
        std::cout << "Nhap tuoi: ";
        std::cin >> tuoi;
    }
    
    void Xuat() const {
        std::cout << "Ho ten: " << hoten << std::endl;
        std::cout << "Gioi tinh: " << gioitinh << std::endl;
        std::cout << "Tuoi: " << tuoi << std::endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    std::vector<Vemaybay*> ve;
    int soluong;
    
public:
    Hanhkhach(const std::string& hoten, const std::string& gioitinh, int tuoi) : Nguoi(hoten, gioitinh, tuoi), soluong(0) {}
    
    void Nhap() {
        Nguoi::Nhap();
        
        std::cout << "Nhap so luong ve: ";
        std::cin >> soluong;
        
        ve.resize(soluong);
        for (int i = 0; i < soluong; i++) {
            ve[i] = new Vemaybay("", "", 0);
            std::cout << "Nhap thong tin ve thu " << i + 1 << std::endl;
            ve[i]->Nhap();
        }
    }
    
    void Xuat() const {
        Nguoi::Xuat();
        
        std::cout << "Danh sach ve: " << std::endl;
        for (int i = 0; i < soluong; i++) {
            std::cout << "Ve thu " << i + 1 << std::endl;
            ve[i]->Xuat();
        }
    }
    
    int tongtien() const {
        int sum = 0;
        for (int i = 0; i < soluong; i++) {
            sum += ve[i]->getgiave();
        }
        return sum;
    }
    
    ~Hanhkhach() {
        for (int i = 0; i < soluong; i++) {
            delete ve[i];
        }
    }
};

bool compareTongTien(const Hanhkhach* a, const Hanhkhach* b) {
    return a->tongtien() > b->tongtien();
}

int main() {
    int n;
    std::cout << "Nhap so luong hanh khach: ";
std::cin >> n;
    
    std::vector<Hanhkhach*> danhSachHanhKhach;
    danhSachHanhKhach.reserve(n);
    
    for (int i = 0; i < n; i++) {
        std::cout << "Nhap thong tin hanh khach thu " << i + 1 << std::endl;
        
        Hanhkhach* hanhKhach = new Hanhkhach("", "", 0);
        hanhKhach->Nhap();
        
        danhSachHanhKhach.push_back(hanhKhach);
    }
    
    std::cout << "Danh sach hanh khach va tong tien phai tra:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Hanh khach thu " << i + 1 << std::endl;
        danhSachHanhKhach[i]->Xuat();
        std::cout << "Tong tien phai tra: " << danhSachHanhKhach[i]->tongtien() << std::endl;
    }
    
    std::sort(danhSachHanhKhach.begin(), danhSachHanhKhach.end(), compareTongTien);
    
    std::cout << "Danh sach hanh khach sau khi sap xep theo chieu giam dan cua tong tien:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Hanh khach thu " << i + 1 << std::endl;
        danhSachHanhKhach[i]->Xuat();
        std::cout << "Tong tien phai tra: " << danhSachHanhKhach[i]->tongtien() << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete danhSachHanhKhach[i];
    }
    
    return 0;
}