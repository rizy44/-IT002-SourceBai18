#include "DeTai.h"

DeTai::DeTai() : MaDeTai(""), TenDeTai(""), NgayDangKi(""), ThoiGianThucThi(0), NgayNghiemThu(""), RegisteredTapChi(0), RegisteredHoiNghi(0) {}

DeTai::~DeTai() {}

void DeTai::Nhap() {
    cout << "Nhap Ma De Tai: ";
    getline(cin, MaDeTai);
    cout << "Nhap Ten De Tai: ";
    getline(cin, TenDeTai);
    cout << "Nhap Ngay Dang Ki: ";
    getline(cin, NgayDangKi);
    cout << "Nhap Thoi Gian Thuc Thi: ";
    cin >> ThoiGianThucThi;
    cin.ignore();
    cout << "Nhap Ngay Nghiem Thu: ";
    getline(cin, NgayNghiemThu);
    cout << "Nhap so luong Tap Chi da dang ky: ";
    cin >> RegisteredTapChi;
    cout << "Nhap so luong Hoi Nghi da dang ky: ";
    cin >> RegisteredHoiNghi;
    cin.ignore();
}

void DeTai::Xuat() {
    cout << "Ma De Tai: " << MaDeTai << endl;
    cout << "Ten De Tai: " << TenDeTai << endl;
    cout << "Ngay Dang Ki: " << NgayDangKi << endl;
    cout << "Thoi Gian Thuc Thi: " << ThoiGianThucThi << " thang" << endl;
    cout << "Ngay Nghiem Thu: " << NgayNghiemThu << endl;
    cout << "So luong Tap Chi da dang ky: " << RegisteredTapChi << endl;
    cout << "So luong Hoi Nghi da dang ky: " << RegisteredHoiNghi << endl;
}

string DeTai::GetMa() {
    return MaDeTai;
}

string DeTai::GetTen()
{
    return TenDeTai;
}



bool DeTai::KiemTraNghiemThu(const vector<BaiBao*>& listBaiBao) const {
    int demTapChi = 0;
    for (const auto& bb : listBaiBao) {
        if (bb->GetMaDeTai() == MaDeTai && bb->GetDanhMuc() == TAPCHI) {
            demTapChi++;
            break; 
        }
    }


    int demHoiNghi = 0;
    for (const auto& bb : listBaiBao) {
        if (bb->CoDeTai() && bb->GetMaDeTai() == MaDeTai && bb->GetDanhMuc() == HOINGHI) {
            demHoiNghi++;
            break;
        }
    }

    return (demTapChi >= RegisteredTapChi) && (demHoiNghi >= RegisteredHoiNghi);
}
