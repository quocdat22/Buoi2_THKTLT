#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "BaiTap.h"



void khoiTaoMangNgauNhien(int* &a, int &n) {
	//n lon hon hoac bang 15
	n = 15 + rand() % 16;
	
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}	
}


void xuatMang(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//Tạo mảng chứa toàn số chẵn.
void taoMangChan(int* &a, int &n) {
	n = 15 + rand() % 16;
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		a[i] = (rand()%50) * 2;
	}
}
void bai1() {

	srand(time(NULL));
	int* a;
	int n;

	//Cau 1
	//khoiTaoMangNgauNhien(a, n);

	//Cau 2
	taoMangChan(a, n);

	xuatMang(a, n);


	free(a);

	return;
}