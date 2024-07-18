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
		printf("%d \t %d %d/%d", i, b[i].nguyen, b[i].tu, b[i].mau);
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
	thucHienChuyenDoiPhanSoThanhHonSo();
	return;
}