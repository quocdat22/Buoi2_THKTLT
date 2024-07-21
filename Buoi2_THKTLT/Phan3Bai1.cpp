#include<stdio.h>
#include "BaiTap.h"
#include <stdlib.h>
#include <time.h>


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

void khoiTaoMangDong(int* &a, int n) {
	a = (int*)malloc(n * sizeof(int));
}

void khoiTaoGiaTriNgauNhien(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
void inMang(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void demSoLanXuatHienMoiPhanTu(int* a, int n) {
	int* b;
	int count = 0;
	b = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			count = 1;
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j]) {
					count++;
					b[j] = 1;
				}
			}
			printf("So %d xuat hien %d lan\n", a[i], count);
		}
	}
	free(b);

}

//Sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần.
void sapXepMangChanTangLeGiam(int* a, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] % 2 == 0 && a[j] % 2 == 0) {
				if (a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			else if (a[i] % 2 != 0 && a[j] % 2 != 0) {
				if (a[i] < a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	printf("Mang sau khi sap xep (Chan tang dan, le gian dan): ");
	inMang(a, n);
}

//Tìm dãy con giảm dài nhất trong a.
int max(int a, int b) {
	return (a > b) ? a : b;
}

void inDayConGiamDaiNhat(int* a, int n) {
	int* dp = (int*)malloc(n * sizeof(int));
	int* prev = (int*)malloc(n * sizeof(int));
	int maxLength = 1;
	int endIndex = 0;

	// Khởi tạo giá trị ban đầu cho dp và prev
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		prev[i] = -1;
	}

	// Tính toán giá trị của dp[] và prev[]
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > maxLength) {
			maxLength = dp[i];
			endIndex = i;
		}
	}

	// In dãy con giảm dài nhất
	printf("Do dai day con giam dai nhat la: %d\n", maxLength);
	printf("Day con giam dai nhat la: ");

	// Truy ngược lại để tìm dãy con giảm dài nhất
	int* lis = (int*)malloc(maxLength * sizeof(int));
	int k = maxLength - 1;
	for (int i = endIndex; i >= 0; i = prev[i]) {
		lis[k--] = a[i];
		if (prev[i] == -1) {
			break;
		}
	}

	for (int i = 0; i < maxLength; i++) {
		printf("%d ", lis[i]);
	}
	printf("\n");

	// Giải phóng bộ nhớ
	free(dp);
	free(prev);
	free(lis);
}

void timPhanTuNhoThuHai(int* a, int n) {
	if (n < 2) {
		printf("Mang phai co it nhat 2 phan tu\n");
		return;
	}
	int minFirst = INT_MAX;
	int minSecond = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (a[i] < minFirst) {
			minSecond = minFirst;
			minFirst = a[i];
		}
		else if (a[i] > minFirst && a[i] < minSecond) {
			minSecond = a[i];
		}
	}

	if (minSecond == INT_MAX) {
		printf("Khong co phan tu nho thu hai trong mang\n");
	}
	else {
		printf("Phan tu nho thu hai trong mang la: %d\n", minSecond);
	}
}


bool kiemTraChuSo(int number, int digit) {
	while (number > 0) {
		if (number % 10 == digit) {
			return true;
		}
		number /= 10;
	}
	return false;
}

bool kiemTraPhanTuThoaDieuKien(int number, int digit1, int digit2) {
	return kiemTraChuSo(number, digit1) && kiemTraChuSo(number, digit2);
}

void timCacPhanTuThoaDieuKien(int* a, int n, int x) {
	int digit1 = x / 10; // Chữ số hàng chục
	int digit2 = x % 10; // Chữ số hàng đơn vị

	printf("Cac phan tu trong mang a chua cac chu so cua %d la: ", x);
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (kiemTraPhanTuThoaDieuKien(a[i], digit1, digit2)) {
			printf("%d ", a[i]);
			found = true;
		}
	}
	if (!found) {
		printf("Khong co phan tu nao thoa man\n");
	}
}





void phan3Bai1() {
	srand(time(NULL));
	int* a;
	
	int n;
	nhapN(n);
	khoiTaoMangDong(a, n);
	//printf("Cac so nguyen to nho hon %d la: ", n);
	/*inCacSoNguyenToNhoHonN(a,n);
	printf("\n");*/

	//tinhTongPhanTuDauLe(n);

	khoiTaoGiaTriNgauNhien(a, n);
	inMang(a, n);

	//demSoLanXuatHienMoiPhanTu(a, n);

	//sapXepMangChanTangLeGiam(a, n);
	
	//inDayConGiamDaiNhat(a, n);

	//timPhanTuNhoThuHai(a, n);

	timCacPhanTuThoaDieuKien(a, n, 36);


	free(a);
	return;
}