#include "BaiTap.h"
#include<stdio.h>
#include<stdlib.h>

struct HonSo {
	int nguyen;
	int tuSo;
	int mauSo;
};

void khoiTaoMangHonSo(HonSo* &a, int n) {
	a = (HonSo*)malloc(n * sizeof(HonSo));
}

void khoiTaoGiaTriNgauNhien(HonSo* a, int n) {
	for(int i = 0; i < n; i++) {
		a[i].nguyen = rand() % 10;
		a[i].tuSo = rand() % 10;
		a[i].mauSo = rand() % 10 + 1;
	}
}

void inMangHonSo(HonSo* a, int n) {
	printf("Vi tri\tGiaTri\n");
	for(int i = 0; i < n; i++) {
		
		printf("%d\t%d %d/%d\n",i, a[i].nguyen, a[i].tuSo, a[i].mauSo);
	}
}

//Tìm hỗn số x trong mảng b theo giải thuật Linear Search
int timHonSo(HonSo* a, int n, HonSo x) {
	for(int i = 0; i < n; i++) {
		if(a[i].nguyen == x.nguyen && a[i].tuSo == x.tuSo && a[i].mauSo == x.mauSo) {
			return i;
		}
	}
	return -1;
}

void thucThiTimX(HonSo* b, int n) {
	HonSo x;
	printf("Nhap gia tri can tim: ");
	scanf_s("%d %d/%d", &x.nguyen, &x.tuSo, &x.mauSo);
	int kq = timHonSo(b, n, x);
	if (kq == -1) {
		printf("Khong tim thay gia tri can tim trong mang\n");
	}
	else {
		printf("Tim thay gia tri can tim tai vi tri %d\n", kq);
	}
}

void phan3Bai2() {
	HonSo* b;
	int n;
	printf("Nhap so luong phan tu cua mang: ");
	scanf_s("%d", &n);
	khoiTaoMangHonSo(b, n);
	khoiTaoGiaTriNgauNhien(b, n);
	printf("Mang Hon So vua khoi tao la: \n");
	inMangHonSo(b, n);

	thucThiTimX(b, n);


}