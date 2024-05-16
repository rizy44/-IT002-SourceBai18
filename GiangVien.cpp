#include "GiangVien.h"

GiangVien::GiangVien() : MaGiangVien(""), TenGiangVien(""), ChuyenNganh(""), SoDienThoai(""), SoTietNghienCuu(0) {}

GiangVien::~GiangVien() {}

void GiangVien::Nhap() {
    cout << "Nhap Ma Giang Vien: ";
    getline(cin, MaGiangVien);
    cout << "Nhap Ten Giang Vien: ";
    getline(cin, TenGiangVien);
    cout << "Nhap Chuyen Nganh: ";
    getline(cin, ChuyenNganh);
    cout << "Nhap So Dien Thoai: ";
    getline(cin, SoDienThoai);
}

void GiangVien::Xuat() {
    cout << "Ma Giang Vien: " << MaGiangVien << endl;
    cout << "Ten Giang Vien: " << TenGiangVien << endl;
    cout << "Chuyen Nganh: " << ChuyenNganh << endl;
    cout << "So Dien Thoai: " << SoDienThoai << endl;
    cout << "So Tiet Nghien Cuu: " << SoTietNghienCuu << endl;
}

void GiangVien::TimBaiBao(BaiBao* bb) {
    string temp = MaGiangVien;
    if (bb->TimMaGiangVien(temp)) {
        TinhSoTiet(bb);
    }
}

void GiangVien::TinhSoTiet(BaiBao* bb) {
    double soTiet = 0;
    switch (bb->GetDanhMuc()) {
    case TAPCHI: {
        TapChi* tapChi = dynamic_cast<TapChi*>(bb);
        if (tapChi) {
            switch (tapChi->GetLoai()) {
            case ISI: soTiet = 5000; break;
            case Scopus: soTiet = 2500; break;
            case Non_Index: soTiet = 1000; break;
            }
        }
        break;
    }
    case HOINGHI: {
        HoiNghi* hoiNghi = dynamic_cast<HoiNghi*>(bb);
        if (hoiNghi) {
            switch (hoiNghi->GetLoai()) {
            case CoreRanking: soTiet = 1000; break;
            case Non_CoreRanking: soTiet = 500; break;
            }
        }
        break;
    }
    }
    if (bb->CoDeTai()) {
        soTiet *= 0.65; // Nếu bài báo thuộc đề tài, số tiết chỉ tính 65%
    }

    if (bb->GetTacGiaChinh() == MaGiangVien) {
        SoTietNghienCuu += soTiet * 0.5; // Tác giả chính được hưởng 50%
    }
    else {
        SoTietNghienCuu += soTiet * 0.5 / bb->GetNumDongTacGia(); // Đồng tác giả chia đều 50%
    }
}

double GiangVien::GetSoTietNghienCuu() {
    return SoTietNghienCuu;
}
