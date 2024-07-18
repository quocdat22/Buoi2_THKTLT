#include "BaiTap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct HonSo {
	int nguyen;
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




void phan2Bai2() {
	srand(time(NULL));

	int n = 10 + rand() % 11;
	

	
	HonSo* b = (HonSo*)malloc(n * sizeof(HonSo));
	khoiTaoMangHonSoNgauNhien(b, n);

	// In mảng hỗn số
	printf("Danh sách hỗn số ngẫu nhiên:\n");
	//inMangHonSo(b, n);
	inDanhSachHonSo(b, n);

	return;
}