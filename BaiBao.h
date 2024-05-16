#pragma once
#include <bits/stdc++.h>
using namespace std;
enum DanhMuc { TAPCHI, HOINGHI };
class BaiBao
{
protected:
    string MaBaiBao;
    string TenBaiBao;
    string LienKetThamChieu;
    string TacGiaChinh;
    int NamXuatBan;
    int NumDongTacGia;
    vector<string> DongTacGia; 
    DanhMuc DanhMucBaiBao;
    bool ThuocDeTai;
    string MaDeTaiCuaBaiBao;
    int SoTietNghienCuu;

public:
    BaiBao();
    virtual ~BaiBao();
    BaiBao(const BaiBao& other);
    virtual void Nhap();
    virtual void Xuat();
    void SetDanhMuc(int a);
    DanhMuc GetDanhMuc();
    bool CoDeTai() const;
    string GetMaBaiBao();
    string GetMaDeTai();
    int GetNumDongTacGia();
    string GetTacGiaChinh(); 
    bool TimMaGiangVien(const string& temp);
};
enum LoaiTapChi { ISI, Scopus, Non_Index };
class TapChi : public BaiBao
{
protected:
    LoaiTapChi Loai;

public:
    TapChi();
    TapChi(const TapChi& other); 
    virtual ~TapChi();
    void Nhap() override;
    void Xuat() override;
    LoaiTapChi GetLoai() const;
};
enum LoaiHoiNghi { CoreRanking, Non_CoreRanking };
class HoiNghi : public BaiBao
{
protected:
    LoaiHoiNghi Loai;

public:
    HoiNghi();
    HoiNghi(const HoiNghi& other); 
    virtual ~HoiNghi();
    void Nhap() override;
    void Xuat() override;
    LoaiHoiNghi GetLoai() const;
};
