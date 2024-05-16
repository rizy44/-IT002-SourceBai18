#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaiBao.h"


using namespace std;

class GiangVien {
protected:
    string MaGiangVien;
    string TenGiangVien;
    string ChuyenNganh;
    string SoDienThoai;
    double SoTietNghienCuu;
public:
    GiangVien();
    ~GiangVien();
    void Nhap();
    void Xuat();
    void TimBaiBao(BaiBao* bb);
    void TinhSoTiet(BaiBao* bb);
    double GetSoTietNghienCuu();
};
