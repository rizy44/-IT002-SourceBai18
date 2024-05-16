#include "BaiBao.h"
BaiBao::BaiBao():MaBaiBao(""), TenBaiBao(""), LienKetThamChieu(""), NamXuatBan(0), TacGiaChinh(""), NumDongTacGia(0),ThuocDeTai(false),MaDeTaiCuaBaiBao("") {}
BaiBao::~BaiBao() {}
BaiBao::BaiBao(const BaiBao& other) {
    MaBaiBao = other.MaBaiBao;
    TenBaiBao = other.TenBaiBao;
    LienKetThamChieu = other.LienKetThamChieu;
    TacGiaChinh = other.TacGiaChinh;
    NamXuatBan = other.NamXuatBan;
    NumDongTacGia = other.NumDongTacGia;
    DanhMucBaiBao = other.DanhMucBaiBao;
    ThuocDeTai = other.ThuocDeTai;
    MaDeTaiCuaBaiBao = other.MaDeTaiCuaBaiBao;
    SoTietNghienCuu = other.SoTietNghienCuu;
}

void BaiBao::Nhap()
{
    cout << "Nhap ma bai bao: ";
    cin >> MaBaiBao;
    cout << "Nhap ten bai bao: ";
    cin.ignore();
    getline(cin, TenBaiBao);
    cout << "Nhap lien ket tham chieu: ";
    getline(cin, LienKetThamChieu);
    cout << "Nhap nam xuat ban: ";
    cin >> NamXuatBan;
    cin.ignore();
    cout << "Nhap tac gia chinh: ";
    getline(std::cin, TacGiaChinh);
    cout << "Nhap so luong dong tac gia: ";
    cin >> NumDongTacGia;
    cin.ignore();
    DongTacGia.resize(NumDongTacGia);
    for (int i = 0; i < NumDongTacGia; ++i) {
        cout << "Nhap Dong Tac Gia thu " << i + 1 << ": ";
        getline(cin, DongTacGia[i]);
    }
    cout << "Bai bao nay co thuoc de tai nao khong (0: Khong, 1: Co): ";
    cin >> ThuocDeTai;
    if (ThuocDeTai)
    {
        cout << "Nhap ma de tai: ";
        cin >> MaDeTaiCuaBaiBao;
    }
}
void BaiBao::Xuat() {
    cout << "Ma Bai Bao: " << MaBaiBao << endl;
    cout << "Ten Bai Bao: " << TenBaiBao << endl;
    cout << "Lien Ket Tham Chieu: " << LienKetThamChieu << endl;
    cout << "Nam Xuat Ban: " << NamXuatBan << endl;
    cout << "Tac Gia Chinh: " << TacGiaChinh << endl;
    cout << "So luong Dong Tac Gia: " << NumDongTacGia << endl;
    for (int i = 0; i < NumDongTacGia; ++i) {
        cout << "Dong Tac Gia thu " << i + 1 << ": " << DongTacGia[i] << endl;
    }
    cout << "Danh Muc Bai Bao: " << (DanhMucBaiBao == TAPCHI ? "Tap Chi" : "Hoi Nghi") << endl;
    if (ThuocDeTai) {
        cout << "Ma De Tai: " << MaDeTaiCuaBaiBao << endl;
    }
    cout << "So Tiet Nghien Cuu: " << SoTietNghienCuu << endl;
}

DanhMuc BaiBao::GetDanhMuc()
{
    return DanhMucBaiBao;
}

bool BaiBao::CoDeTai() const
{
    return ThuocDeTai;
}
string BaiBao::GetMaBaiBao()
{
    return MaBaiBao;
}
string BaiBao::GetMaDeTai()
{
    return MaDeTaiCuaBaiBao;
}

int BaiBao::GetNumDongTacGia()
{
    return NumDongTacGia;
}

string BaiBao::GetTacGiaChinh()
{
    return TacGiaChinh;
}

bool BaiBao::TimMaGiangVien(const string& temp)
{
    if (TacGiaChinh == temp) {
        return true;
    }
    for (const auto& tacGia : DongTacGia) {
        if (tacGia == temp) {
            return true;
        }
    }
    return false;
}
//-----------------------TapChi-----------------------
TapChi::TapChi(){}
TapChi::TapChi(const TapChi& other) : BaiBao(other) {}
TapChi::~TapChi() {}
void TapChi::Nhap()
{
    BaiBao::Nhap();
    int loai;
    cout << "Nhap Loai Tap Chi (0: ISI, 1: Scopus, 2: Non_Index): ";
    cin >> loai;
    Loai = static_cast<LoaiTapChi>(loai);
    cout << endl;

}
void TapChi::Xuat()
{
    BaiBao::Xuat();
    cout << "Loai Tap Chi: ";
    switch (Loai) {
    case ISI: cout << "ISI"; break;
    case Scopus: cout << "Scopus"; break;
    case Non_Index: cout << "Non_Index"; break;
    }
    cout << endl;
}
LoaiTapChi TapChi::GetLoai() const {
    return Loai;
}
//-----------------HoiNghi--------------
HoiNghi::HoiNghi() : BaiBao() {}
HoiNghi::HoiNghi(const HoiNghi& other) : BaiBao(other) {}
HoiNghi::~HoiNghi() {}
void HoiNghi::Nhap() 
{
    BaiBao::Nhap();
    int loai;
    cout << "Nhap Loai Hoi Nghi (0: CoreRanking, 1: Non_CoreRanking): ";
    cin >> loai;
    Loai = static_cast<LoaiHoiNghi>(loai);
    cin.ignore();
    cout << endl;
}

void HoiNghi::Xuat() 
{
    BaiBao::Xuat();
    cout << "Loai Hoi Nghi: ";
    switch (Loai) 
    {
    case CoreRanking: cout << "CoreRanking"; break;
    case Non_CoreRanking: cout << "Non_CoreRanking"; break;
    }
    cout << endl;
}
LoaiHoiNghi HoiNghi::GetLoai() const
{
    return  Loai;
}


