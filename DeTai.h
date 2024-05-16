#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaiBao.h"


using namespace std;

class DeTai {
protected:
    string MaDeTai;
    string TenDeTai;
    string NgayDangKi;
    int ThoiGianThucThi;
    string NgayNghiemThu;
    int RegisteredTapChi;
    int RegisteredHoiNghi;
    vector<TapChi> ListTC;
    vector<HoiNghi> ListHN;

public:
    DeTai();
    ~DeTai();
    void Nhap();
    void Xuat();
    string GetMa();
    string GetTen();
    bool KiemTraNghiemThu(const vector<BaiBao*>& listBaiBao) const;
};
