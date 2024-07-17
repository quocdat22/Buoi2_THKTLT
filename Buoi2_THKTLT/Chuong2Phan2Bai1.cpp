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

//Tìm kiếm x trong a theo giải thuật tìm kiếm tuyến tính Linear Search.
void timKiemTuyenTinh(int* a, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			printf("X(%d) ton tai trong mang tai vi tri %d\n", x,  i);
			return;
		}
	}
	printf("X khong ton tai trong mang\n");
	
}

//Sắp xếp a tăng dần/giảm dần theo giải thuật Interchange Sort
void interchangeSort(int*& a, int n, bool tang) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tang) {
				if (a[i] > a[j]) {
					int x = a[i];
					a[i] = a[j];
					a[j] = x;
				}
			}
			else {
				if (a[i] < a[j]) {
					int x = a[i];
					a[i] = a[j];
					a[j] = x;
				}
			}
		}
	}
}

//Tìm kiếm x trong a  theo giải thuật tìm kiế Binary Search với mảng a đã được sắp tăng
void timKiemNhiPhan(int* a, int n, int x) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			printf("X(%d) ton tai trong mang tai vi tri %d\n",x , mid);
			return;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("X khong ton tai trong mang\n");
}

//Sắp xếp a tăng dần theo giải thuật Selection Sort.
void selectionSort(int*& a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		int x = a[i];
		a[i] = a[min];
		a[min] = x;
	}
}





void bai1() {

	srand(time(NULL));
	int* a;
	int n;

	//Cau 1
	khoiTaoMangNgauNhien(a, n);
	//printf("Mang khoi tao: \n");
	//xuatMang(a, n);

	//Cau 2
	//taoMangChan(a, n);

	//Cau 3
	//timKiemTuyenTinh(a, n, 36);

	//Cau 4
	/*interchangeSort(a, n, true);
	printf("Mang sau khi sap xep tang dan (InterchangeSort)\n");
	xuatMang(a, n);
	interchangeSort(a, n, false);
	printf("Mang sau khi sap xep giam dan (InterchangeSort)\n");
	xuatMang(a, n);*/


	
	//Cau 5
	interchangeSort(a, n, true);
	printf("Mang sau khi sap xep tang dan (InterchangeSort)\n");
	xuatMang(a, n);
	timKiemNhiPhan(a, n, 36);


	//Cau 6
	/*selectionSort(a, n);
	printf("Mang sau khi sap xep tang dan (SelectionSort)\n");
	xuatMang(a, n);*/



	free(a);

	return;
}