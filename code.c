#include <stdio.h>
#include <string.h>

struct SinhVien;
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();
int isSorted = 0;

struct HoTen {
	char ho[20];
	char ten[20];
};
struct NgaySinh{
	int ngay;
	int thang;
	int nam;
};
struct SinhVien {
    char lop[10];
    int MSSV;
	struct HoTen hoVaTen;
	struct NgaySinh ngaySinh ;
	char gioiTinh[10];
	char diaChi[30];

};
struct SinhVien nhapSV() {

        isSorted = 0;

		struct SinhVien sv;

        printf("Lop: ");
        scanf("%s", sv.lop);

		nhapHoTen(&sv.hoVaTen);
		nhapNgaySinh(&sv.ngaySinh);
		printf("Gioi tinh: ");
		scanf("%s", sv.gioiTinh);
		printf("Nhap dia chi:");
		getchar();
		gets(sv.diaChi);
		return sv;
}

void nhapHoTen(struct HoTen* ten) {
    char HoVaTen[100];
    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(HoVaTen);

    int i = strlen(HoVaTen) - 1, j = 0;
    while (i >= 0 && HoVaTen[i] != ' ') {
        ten->ten[j] = HoVaTen[i];
        i--;
        j++;
    }
    ten->ten[j] = '\0';
    HoVaTen[i] = '\0';
    strrev(ten->ten);
    strcpy(ten->ho, HoVaTen);
}

void nhapNgaySinh(struct NgaySinh* ngaySinh) {
	printf("Nhap ngay sinh\n");
	printf("Ngay: ");
	scanf("%d", &ngaySinh->ngay);
	printf("Thang: ");
	scanf("%d", &ngaySinh->thang);
	printf("Nam: ");
	scanf("%d", &ngaySinh->nam);
}

void hienThiTTSV(struct SinhVien sv) {
    printf("%-16s", sv.lop);
    hienThiMSSVvaEmail(sv, 0);
    printf("%-20s %-11s", sv.hoVaTen.ho, sv.hoVaTen.ten);
    hienThiNgaySinh(sv);
    printf("%-10s %-31s", sv.gioiTinh, sv.diaChi);
    hienThiMSSVvaEmail(sv, 1);
    printf("\n");
}

void hienThiNgaySinh(struct SinhVien sv) {
    if (sv.ngaySinh.ngay < 10) {
        printf("0%d/", sv.ngaySinh.ngay);
    } else {
        printf("%d/", sv.ngaySinh.ngay);
    }
    if (sv.ngaySinh.thang < 10) {
        printf("0%d/", sv.ngaySinh.thang);
    } else {
        printf("%d/", sv.ngaySinh.thang);
    }
    printf("%-10d", sv.ngaySinh.nam);
}

void hienThiMSSVvaEmail(struct SinhVien sv, int theLoai) {
    if (isSorted == 0) {
        printf("%-16s", "chua cap");
    } else {
        if (theLoai == 0) {
            printf("%-16d", sv.MSSV);
        } else {
            printf("%d@dut.udn.vn", sv.MSSV);
        }
    }
}

void capMSSV(struct SinhVien* ds, int slsv) {
    isSorted = 1;

    for (int i = 0; i < slsv; i++) {
        ds[i].MSSV = i + 1;
    }
}

void sapXepTheoTen(struct SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ten, ds[j-1].hoVaTen.ten) < 0) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
	capMSSV(ds, slsv);
}

void xoaSinhVien(struct SinhVien* ds, int slsv){
    char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			for(int j = i;j <slsv -1; j++){
                ds[j] = ds[j+1];
            }
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
	isSorted = 0;
}

void timTheoTen(struct SinhVien* ds, int slsv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

// void ghiFile(struct SinhVien* ds, int slsv) {
// 	getchar();
// 	char fName[26];
// 	printf("Nhap ten file: ");
// 	gets(fName);
// 	FILE* fOut = fopen(fName, "a");
// 	int i;
// 	for(i = 0; i < slsv; i++) {
// 		struct SinhVien sv = ds[i];
// 		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s\n",
// 		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.gioiTinh);
// 	}
// 	fclose(fOut);
// }

// void docFile(struct SinhVien* ds, int* slsv) {
// 	FILE* fOut = fopen("SV.txt", "r");
// 	int i = 0;
// 	if(fOut) {
// 		while(1) {
// 			struct SinhVien sv;
// 			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s \n",
// 			&sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten,, sv.gioiTinh);

// 			ds[i++] = sv;
// 			if(feof(fOut)) { // thoat chuong trinh
// 				break;
// 			}
// 		}
// 	}

// 	fclose(fOut);
// 	*slsv = i;
// }

void hienThiTenCot() {
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-15s %-15s %-20s %-10s %-15s %-10s %-30s %-30s\n",
		"Lop", "MSSV", "Ho", "Ten", "Ngay Sinh", "Gioi Tinh", "Dia Chi", "Email");
}

void hienThiDSSV(struct SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;

	// docFile(dssv, &slsv);
//	printf("DANH SACH SINH VIEN HIEN THOI:\n");
//	hienThiDSSV(dssv, slsv);
//	int i;

	do {
		printf("=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep theo ten.");
		printf("\n4. Xoa sinh vien theo ten.");
		printf("\n5. Tim sinh vien theo ten.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");

		scanf("%d", &luaChon);
		struct SinhVien sv;

		switch(luaChon) {
			case 0:
				break;

			case 1:


				sv = nhapSV();
				dssv[slsv++] = sv;
				break;

			case 2:
				hienThiDSSV(dssv, slsv);
				break;

			case 3:
				sapXepTheoTen(dssv, slsv);
				printf("\nDanh sach sinh vien sau khi sap xep theo ten a-z:\n");
				hienThiDSSV(dssv, slsv);
				break;

			case 4:
                xoaSinhVien(dssv,slsv);
                slsv--;
				break;

			case 5:
				timTheoTen(dssv, slsv);
				break;

			// case 6:
			// 	ghiFile(dssv, slsv);
			// 	break;

			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}

	} while(luaChon);

	return 0;
}
