#include "BaiTap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct HonSo {
	int nguyen;
	int tu;
	int mau;
};

struct PhanSo {
	int tu;
	int mau;
};

HonSo khoiTaoHonSo() {
	HonSo hs;
	hs.nguyen = rand()% 10;
	hs.tu = rand() % 10;
	do {
		hs.mau = rand() % 10;  // Mẫu số từ 1 đến 9
	} while (hs.mau == 0);

	return hs;
}


// Hàm khởi tạo mảng hỗn số ngẫu nhiên
void khoiTaoMangHonSoNgauNhien(HonSo* b, int n) {
	for (int i = 0; i < n; i++) {
		b[i] = khoiTaoHonSo();
	}
}

// Hàm in một hỗn số
void inHonSo(HonSo hs) {
	printf("%d %d/%d", hs.nguyen, hs.tu, hs.mau);
}

// Hàm in mảng hỗn số
void inMangHonSo(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		inHonSo(b[i]);
		printf("\n");
	}
}

// Hàm in mảng hỗn số
void inDanhSachHonSo(HonSo b[], int n) {
	printf("STT \t Hon so\n");
	for (int i = 0; i < n; i++) {
		printf("%d \t (%d %d/%d)", i, b[i].nguyen, b[i].tu, b[i].mau);
		//inHonSo(b[i]);
		printf("\n");
	}
}


void soSanhHonSo(HonSo a, HonSo b) {
	float x = (float)a.nguyen + (float)a.tu / a.mau;
	float y = (float)b.nguyen + (float)b.tu / b.mau;
	
	if (x > y) {
		printf("Hỗn số (%d %d/%d) > Hỗn số (%d %d/%d)\n",a.nguyen,a.tu,a.mau,b.nguyen,b.tu,b.mau);
		//return 1;
	}
	else if (x < y) {
		printf("Hỗn số (%d %d/%d) < Hỗn số (%d %d/%d)\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau);
		//return -1;
	}
	else {
		printf("Hai hỗn số bằng nhau: (%d %d/%d) = (%d %d/%d)\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau);
		//return 0;
	}
}

void thucHienSoSanh2HonSo(HonSo* b, int n) {
	//chọn ngẫu nhiên 2 hỗn số trong mảng b
	int i = rand() % n;
	int j = rand() % n;
	while (i == j) {
		j = rand() % n;
	}

	HonSo a = b[i];
	HonSo c = b[j];


	printf("\nCâu 3.\nHai số so sánh ngẫu nhiên trong danh sách là: %d.(%d %d/%d) và %d.(%d %d/%d)\n",i , a.nguyen, a.tu, a.mau, j, c.nguyen, c.tu, c.mau);
	soSanhHonSo(a, c);
}

//chuyển hỗn số thành phân số
PhanSo chuyenHonSoThanhPhanSo(HonSo hs) {
	int tu = hs.nguyen * hs.mau + hs.tu;
	int mau = hs.mau;
	PhanSo ps;
	ps.tu = tu;
	ps.mau = mau;
	return ps;
}

HonSo chuyenPhanSoThanhHonSo(PhanSo ps) {
	int nguyen = ps.tu / ps.mau;
	int tuHonSo = ps.tu % ps.mau;

	HonSo hs;
	hs.nguyen = nguyen;
	hs.tu = tuHonSo;
	hs.mau = ps.mau;

	return hs;
}

PhanSo khoiTaoNgauNhien1PhanSo() {
	PhanSo ps;
	ps.tu = rand() % 10;
	do {
		ps.mau = rand() % 10;  // Mẫu số từ 1 đến 9
	} while (ps.mau == 0);

	return ps;

}

void thucHienChuyenDoiPhanSoThanhHonSo() {
	PhanSo ps = khoiTaoNgauNhien1PhanSo();
	HonSo hs = chuyenPhanSoThanhHonSo(ps);
	printf("\nCâu 5.\nPhân số ngẫu nhiên là: %d/%d\n", ps.tu, ps.mau);
	printf("Hỗn số tương ứng là: %d %d/%d\n", hs.nguyen, hs.tu, hs.mau);
}




void thucHienChuyenDoiHonSoThanhPhanSo(HonSo* b, int n) {
	//chọn ngẫu nhiên 1 hỗn số trong mảng b
	int i = rand() % n;
	HonSo a = b[i];
	PhanSo ps = chuyenHonSoThanhPhanSo(a);
	printf("\nCâu 4.\nHỗn số ngẫu nhiên trong danh sách là: %d.(%d %d/%d)\n", i, a.nguyen, a.tu, a.mau);
	printf("Phân số tương ứng là: %d/%d\n", ps.tu, ps.mau);
}


//Tính tổng, hiệu, tích, thương 2 hỗn số.
void tinhTongHaiHonSo(HonSo a, HonSo b) {
	float x = (float)a.nguyen + (float)a.tu / a.mau;
	float y = (float)b.nguyen + (float)b.tu / b.mau;
	float tong = x + y;
	printf("Tổng: (%d %d/%d) + (%d %d/%d) = %.2f\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau, tong);
}
void tinhHieuHaiHonSo(HonSo a, HonSo b) {
	float x = (float)a.nguyen + (float)a.tu / a.mau;
	float y = (float)b.nguyen + (float)b.tu / b.mau;
	float hieu = x - y;
	printf("Hiệu: (%d %d/%d) - (%d %d/%d) = %.2f\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau, hieu);
}
void tinhTichHaiHonSo(HonSo a, HonSo b) {
	float x = (float)a.nguyen + (float)a.tu / a.mau;
	float y = (float)b.nguyen + (float)b.tu / b.mau;
	float tich = x * y;
	printf("Tích: (%d %d/%d) * (%d %d/%d) = %.2f\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau, tich);
}
void tinhThuongHaiHonSo(HonSo a, HonSo b) {
	float x = (float)a.nguyen + (float)a.tu / a.mau;
	float y = (float)b.nguyen + (float)b.tu / b.mau;
	float thuong = x / y;
	printf("Thương: (%d %d/%d) / (%d %d/%d) = %.2f\n", a.nguyen, a.tu, a.mau, b.nguyen, b.tu, b.mau, thuong);
}



void thucHienTinhToan2HonSo(HonSo* b, int n) {
	//chọn ngẫu nhiên 2 hỗn số trong mảng b
	int i = rand() % n;
	int j = rand() % n;
	while (i == j) {
		j = rand() % n;
	}

	HonSo a = b[i];
	HonSo c = b[j];

	printf("\nCâu 6.\nHai số tính toán ngẫu nhiên trong danh sách là: %d.(%d %d/%d) và %d.(%d %d/%d)\n", i, a.nguyen, a.tu, a.mau, j, c.nguyen, c.tu, c.mau);
	tinhTongHaiHonSo(a, c);
	tinhHieuHaiHonSo(a, c);
	tinhTichHaiHonSo(a, c);
	tinhThuongHaiHonSo(a, c);
}


void swapHonSo(HonSo &a, HonSo &b){
	HonSo temp = a;
	a = b;
	b = temp;
}
//thuat toan interchange sort
void sapXepTangDanInterchangeSort(HonSo* b, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			float x = (float)b[i].nguyen + (float)b[i].tu / b[i].mau;
			float y = (float)b[j].nguyen + (float)b[j].tu / b[j].mau;
			if (x > y) {
				swapHonSo(b[i], b[j]);
			}
		}
	}
	printf("\nDanh sách hỗn số sau khi sắp xếp tăng dần (Interchange Sort):\n");
	inDanhSachHonSo(b, n);
}

void sapXepGiamDanInterchangeSort(HonSo* b, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			float x = (float)b[i].nguyen + (float)b[i].tu / b[i].mau;
			float y = (float)b[j].nguyen + (float)b[j].tu / b[j].mau;
			if (x < y) {
				swapHonSo(b[i], b[j]);
			}
		}
	}
	printf("\nDanh sách hỗn số sau khi sắp xếp giảm dần (Interchange Sort):\n");
	inDanhSachHonSo(b, n);
}

// sap xep theo thuat toan selection sort
void sapXepTangDanSelectionSort(HonSo* b, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			float x = (float)b[min].nguyen + (float)b[min].tu / b[min].mau;
			float y = (float)b[j].nguyen + (float)b[j].tu / b[j].mau;
			if (x > y) {
				min = j;
			}
		}
		if (min != i) {
			swapHonSo(b[i], b[min]);
		}
	}
	printf("\nDanh sách hỗn số sau khi sắp xếp tăng dần (Selection Sort):\n");
	inDanhSachHonSo(b, n);
}

void sapXepGiamDanSelectionSort(HonSo* b, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			float x = (float)b[min].nguyen + (float)b[min].tu / b[min].mau;
			float y = (float)b[j].nguyen + (float)b[j].tu / b[j].mau;
			if (x < y) {
				min = j;
			}
		}
		if (min != i) {
			swapHonSo(b[i], b[min]);
		}
	}
	printf("\nDanh sách hỗn số sau khi sắp xếp giảm dần (Selection Sort):\n");
	inDanhSachHonSo(b, n);
}






void phan2Bai2() {
	srand(time(NULL));

	int n = 10 + rand() % 11;
	

	
	HonSo* b = (HonSo*)malloc(n * sizeof(HonSo));
	khoiTaoMangHonSoNgauNhien(b, n);

	// In mảng hỗn số
	printf("Danh sách hỗn số ngẫu nhiên:\n");
	//inMangHonSo(b, n);
	inDanhSachHonSo(b, n);

	//cau 3
	//thucHienSoSanh2HonSo(b, n);

	//cau 4
	//thucHienChuyenDoiHonSoThanhPhanSo(b, n);

	//cau 5
	//thucHienChuyenDoiPhanSoThanhHonSo();

	//cau 6
	//thucHienTinhToan2HonSo(b, n);

	//cau 7
	//interchange sort
	/*sapXepTangDanInterchangeSort(b, n);
	sapXepGiamDanInterchangeSort(b, n);*/

	//selection sort
	sapXepTangDanSelectionSort(b, n);
	sapXepGiamDanSelectionSort(b, n);

	

	free(b);
	return;
}