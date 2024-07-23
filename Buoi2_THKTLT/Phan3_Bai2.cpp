#include "BaiTap.h"
#include<stdio.h>
#include<stdlib.h>

struct HonSo {
	int nguyen;
	int tuSo;
	int mauSo;
};

struct PhanSo {
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

//Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
void sapXepMangCoNguyenChanDauLeCuoi(HonSo* a, int n) {
	/*for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i].nguyen % 2 == 0 && a[j].nguyen % 2 != 0) {
				HonSo temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}*/

	int left = 0, right = n - 1;
	while(left < right) {
		while(a[left].nguyen % 2 == 0 && left < right) {
			left++;
		}
		while(a[right].nguyen % 2 != 0 && left < right) {
			right--;
		}
		if(left < right) {
			HonSo temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
	}
}

//Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tang/giảm
void sapXepMangTang(HonSo* a, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i].nguyen > a[j].nguyen) {
				HonSo temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void timXBinarySeach(HonSo* a, int n, HonSo x) {
	int left = 0, right = n - 1;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(a[mid].nguyen == x.nguyen && a[mid].tuSo == x.tuSo && a[mid].mauSo == x.mauSo) {
			printf("Tim thay gia tri can tim tai vi tri %d\n", mid);
			return;
		}
		if(a[mid].nguyen < x.nguyen) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("Khong tim thay gia tri can tim trong mang\n");
}

void thucThiTimHonSoSapXepTangBinarySeach(HonSo* b, int n) {
	HonSo x;
	printf("Nhap gia tri can tim: ");
	scanf_s("%d %d/%d", &x.nguyen, &x.tuSo, &x.mauSo);
	sapXepMangTang(b, n);
	printf("Mang Hon So sau khi sap xep (tang) la: \n");
	inMangHonSo(b, n);
	timXBinarySeach(b, n, x);
}

//Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số.

//Xóa phần tử thứ k trong mảng b
void xoaPhanTuK(HonSo* &a, int &n, int k) {
	for(int i = k; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

//Thêm hỗn số x vào mảng b tại vị trí k.
void themPhanTuK(HonSo* &a, int &n, HonSo x, int k) {
	a = (HonSo*)realloc(a, (n + 1) * sizeof(HonSo));
	for(int i = n; i > k; i--) {
		a[i] = a[i - 1];
	}
	a[k] = x;
	n++;
}

//Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b.
void taoMangPhanSoTuMangHonSo(HonSo* a, int n, PhanSo* &c, int &m) {
	m = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].nguyen != 0) {
			m++;
		}
	}
	c = (PhanSo*)malloc(m * sizeof(PhanSo));
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].nguyen != 0) {
			c[j].tuSo = a[i].nguyen * a[i].mauSo + a[i].tuSo;
			c[j].mauSo = a[i].mauSo;
			j++;
		}
	}
}

//Tính tổng các phần tử của mảng b in ra ket qua.
void tinhTongMangHonSo(HonSo* a, int n) {
	int tongNguyen = 0, tongTuSo = 0, tongMauSo = 1;
	for (int i = 0; i < n; i++) {
		tongNguyen += a[i].nguyen;
		tongTuSo += a[i].tuSo;
		tongMauSo *= a[i].mauSo;
	}
	tongTuSo += tongNguyen * tongMauSo;
	printf("Tong cua mang Hon So la: %d %d/%d\n", tongTuSo / tongMauSo, tongTuSo % tongMauSo, tongMauSo);
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

	//thucThiTimX(b, n);

	/*sapXepMangCoNguyenChanDauLeCuoi(b, n);
	printf("Mang Hon So sau khi sap xep la: \n");
	inMangHonSo(b, n);*/

	//thucThiTimHonSoSapXepTangBinarySeach(b, n);

	/*xoaPhanTuK(b, n, 2);
	printf("Mang Hon So sau khi xoa phan tu thu 2 la: \n");
	inMangHonSo(b, n);*/

	/*themPhanTuK(b, n, {1, 2, 3}, 2);
	printf("Mang Hon So sau khi them phan tu (1 2/3) tai vi tri 2 la: \n");
	inMangHonSo(b, n);*/

	/*PhanSo* c;
	int m;
	taoMangPhanSoTuMangHonSo(b, n, c, m);
	printf("Mang Phan So tu mang Hon So la: \n");
	printf("STT\tTuSo/MauSo\n");
	for(int i = 0; i < m; i++) {
		
		printf("%d\t%d/%d\n",i, c[i].tuSo, c[i].mauSo);
	}
	free(c);*/

	tinhTongMangHonSo(b, n);
	free(b);

}