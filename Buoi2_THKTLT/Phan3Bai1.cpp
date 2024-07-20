#include<stdio.h>
#include "BaiTap.h"
#include <stdlib.h>


void nhapN(int &n) {
	printf("Nhap n: ");
	scanf_s("%d", &n);
}

bool kiemTraSoNguyenTo(int number) {
	if (number < 2) {
		return false;
	}
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

void inCacSoNguyenToNhoHonN(int* &a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (kiemTraSoNguyenTo(i)) {
			printf("%d ", i);
			a[count] = i;
			count++;
		}
	}
	if (count == 0) {
		printf("Khong co so nguyen to nao nho hon %d", n);
	}
}


//Tính tổng các phần tử có chữ số đầu là chữ số lẻ
bool kiemTraSoDauLe(int number) {

	while (number >= 10) {
		number /= 10;
	}
	if (number % 2 != 0) {
		return true;
	}
	return false;

	//le = true, chan = false
}

void tinhTongPhanTuDauLe(int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (kiemTraSoNguyenTo(i)) {
			if (kiemTraSoDauLe(i)) {
				sum += i;
			}
		}

	}

	printf("Tong cac phan tu co chu so dau la chu so le trong danh sach so nguyen to la: %d\n", sum);
}






void phan3Bai1() {
	int* a;
	
	int n;
	nhapN(n);
	a = (int*)malloc(n * sizeof(int));
	//printf("Cac so nguyen to nho hon %d la: ", n);
	inCacSoNguyenToNhoHonN(a,n);
	printf("\n");

	tinhTongPhanTuDauLe(n);
	
	return;
}