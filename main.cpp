#include "GiangVien.h"
#include "DeTai.h"

using namespace std;

int main() {
    //Nhập Danh sách giảng viên
    int numGiangVien;
    cout << "\nNhap so luong giang vien: ";
    cin >> numGiangVien;
    cin.ignore();
    vector<GiangVien> listGiangVien(numGiangVien);
    for (int i = 0; i < numGiangVien; ++i) {
        cout << "Nhap thong tin cho giang vien thu " << i + 1 << ":\n";
        listGiangVien[i].Nhap();
        cout << endl;
    }
    //Nhập danh sách bài báo
    int numBaiBao;
    cout << "\nNhap so luong bai bao: ";
    cin >> numBaiBao;
    cin.ignore();
    vector<BaiBao*> listBaiBao(numBaiBao);
    for (int i = 0; i < numBaiBao; ++i) {
        int loai;
        cout << "Nhap loai Bai Bao (0: Tap Chi, 1: Hoi Nghi) cho bai bao thu " << i + 1 << ": ";
        cin >> loai;
        cin.ignore();
        if (loai == 0) {
            listBaiBao[i] = new TapChi();
        }
        else if (loai == 1) {
            listBaiBao[i] = new HoiNghi();
        }
        listBaiBao[i]->Nhap();
    }
    //Nhap danh sách đề tài
    int numDeTai;
    cout << "\nNhap so luong de tai: ";
    cin >> numDeTai;
    cin.ignore();
    vector<DeTai> listDeTai(numDeTai);
    for (int i = 0; i < numDeTai; ++i) {
        cout << "Nhap thong tin cho de tai thu " << i + 1 << ":\n";
        listDeTai[i].Nhap();
    }

    // Tính số tiết nghiên cứu cho từng giảng viên
    for (int i = 0; i < numGiangVien; ++i) {
        for (int j = 0; j < numBaiBao; ++j) {
            listGiangVien[i].TimBaiBao(listBaiBao[j]);
        }
    }

    // Xuất thông tin giảng viên và số tiết nghiên cứu
    for (int i = 0; i < numGiangVien; ++i) {
        listGiangVien[i].Xuat();
        cout << "So tiet nghien cuu: " << listGiangVien[i].GetSoTietNghienCuu() << endl;
    }

    // Kiểm tra điều kiện nghiệm thu đề tài
    for (int i = 0; i < numDeTai; ++i) {
        if (listDeTai[i].KiemTraNghiemThu(listBaiBao)) {
            cout << "De tai " << listDeTai[i].GetTen() << " du dieu kien nghiem thu." << endl;
        }
        else {
            cout << "De tai " << listDeTai[i].GetTen() << " khong du dieu kien nghiem thu." << endl;
        }
    }

    // Giải phóng bộ nhớ cho các bài báo
    for (int i = 0; i < numBaiBao; ++i) {
        delete listBaiBao[i];
    }

    return 0;
}