#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien;
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();
//int isSorted = 0;

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
    int khoa;
    int khoi;
    int lop;
    int MSSV;
	char email[30];
	struct HoTen hoVaTen;
	struct NgaySinh ngaySinh ;
	char gioiTinh[10];
	char diaChi[30];

};

int MSSV_database[101];
int MSSV_database_index = 0;

void addMSSVtoDatabase(struct SinhVien* sv) {
    MSSV_database[MSSV_database_index++] = sv->MSSV;
//    printf("\n\n\n%d\n\n\n", MSSV_database[0]);
}

int checkMSSVinDatabase(struct SinhVien* sv) {
    for (int i = 0; i <= MSSV_database_index; i++) {
        if (sv->MSSV == MSSV_database[i]) return 0;
    }
    return 1;
}

struct SinhVien nhapSV() {

//        isSorted = 0;

		struct SinhVien sv;

        printf("Khoa: ");
        scanf("%d", &sv.khoa);
        printf("Khoi: ");
        scanf("%d", &sv.khoi);
        printf("Lop: ");
        scanf("%d", &sv.lop);

        nhapMSSV(&sv);
        addMSSVtoDatabase(&sv);
		nhapHoTen(&sv.hoVaTen);
//		            printf("\n\n\n%s\n\n\n\n", sv.hoVaTen.ten);
		nhapNgaySinh(&sv.ngaySinh);
		printf("Gioi tinh: ");
		scanf("%s", sv.gioiTinh);
		printf("Nhap dia chi:");
		getchar();
		gets(sv.diaChi);
		return sv;
}

void nhapMSSV(struct SinhVien* sv) {
        int choice;
        printf("Ban co muon nhap MSSV khong? (1/0): ");
        scanf("%d", &choice);
        if (choice == 1) {
            int checking = 1;
            while(checking) {
                printf("Nhap MSSV: ");
                scanf("%d", &sv->MSSV);
                itoa(sv->MSSV,sv->email,10);
                strcat(sv->email,"@sv1.dut.udn.vn");
                if (checkMSSVinDatabase(sv)) {
                    addMSSVtoDatabase(sv);
                    checking = 0;
                } else {
                    printf("MSSV da duoc su dung, xin hay nhap lai.\n");
                }
            }
        } else {
            sv->MSSV = -1;
            strcpy(sv->email, "chua cap");
        }
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


void hienThiTenCot() {
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-15s %-15s %-15s %-15s %-20s %-10s %-15s %-10s %-30s %-30s\n",
		"Khoa", "Khoi", "Lop", "MSSV", "Ho", "Ten", "Ngay Sinh", "Gioi Tinh", "Dia Chi", "Email");
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

void hienThiTTSV(struct SinhVien sv) {
    printf("%-16d%-16d%-16d", sv.khoa, sv.khoi, sv.lop);
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
//    if (isSorted == 0) {
//        printf("%-16s", "chua cap");
//    } else {
        if (theLoai == 0) {
            printf("%-16d", sv.MSSV);
        } else {
            printf("%-30s", sv.email);
        }
//    }
}

void capMSSV(struct SinhVien* ds, int slsv) {
////    isSorted = 1;
//
//    for (int i = 0; i < slsv; i++) {
//        if (ds[i].MSSV != -1) {
//            i--;
//            continue;
//        }
//        int temp
//        ds[i].MSSV = ds[i].khoa * 1000000 + ds[i].khoi * 10000 + i + 1;
//        checkMSSVinDatabase(sv.MSSV)
//        itoa(ds[i].MSSV,ds[i].email,10);
//		strcat(ds[i].email,"@sv1.dut.udn.vn");
//    }
    int i = 0, j = 1;
    while (i < slsv) {
        if (ds[i].MSSV == -1) {
            int checking = 1;
            while (checking) {
                ds[i].MSSV = ds[i].khoa * 1000000 + ds[i].khoi * 10000 + j++;
                itoa(ds[i].MSSV,ds[i].email,10);
                strcat(ds[i].email,"@sv1.dut.udn.vn");
                if (checkMSSVinDatabase(&ds[i])) {
                    addMSSVtoDatabase(&ds[i]);
                    checking = 0;
                }
            }
        }
        i++;
    }
}

void sapXepTheoTen(struct SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(strcmp(ds[i].hoVaTen.ten, ds[j].hoVaTen.ten) > 0) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[i];
				ds[i] = sv;
			}
		}
	}
	capMSSV(ds, slsv);
}

void sapXep(struct SinhVien* ds, int slsv) {
	sapXepTheoTen(ds, slsv);
	int i, j, k;

	// Sap xep khoa
	for(i = 0; i < slsv; i++) {
		for(j = i + 1; j < slsv; j++) {
			if(ds[i].khoa > ds[j].khoa || ((ds[i].khoa == ds[j].khoa) && strcmp(ds[i].hoVaTen.ten, ds[j].hoVaTen.ten) > 0 )){
				struct SinhVien sv = ds[j];
				ds[j] = ds[i];
				ds[i] = sv;
			}
		}
	}

	// Sap xep khoi
	int dauKhoa = 0;
	int cuoiKhoa = slsv;
	for(i = 0; i < slsv; i++){
		if(ds[i].khoa != ds[i+1].khoa || (i == slsv -1)){
			cuoiKhoa = i;
			for(j = dauKhoa; j <= cuoiKhoa ; j++) {
				for(k = j + 1; k <= cuoiKhoa; k++) {
					if(ds[j].khoi > ds[k].khoi || ((ds[j].khoi == ds[k].khoi) && strcmp(ds[j].hoVaTen.ten, ds[k].hoVaTen.ten) > 0 )) {
						struct SinhVien sv = ds[j];
						ds[j] = ds[k];
						ds[k] = sv;
					}
				}
			}
			

			// Sap xep lop
			int n,m,p;
			int dauKhoi = dauKhoa;
			int cuoiKhoi = cuoiKhoa;
			printf("%d %d %d %d %d\n" ,m,n,p,dauKhoi,cuoiKhoi);
			for(m = dauKhoa; m <= cuoiKhoa; m++){
				if(ds[m].khoi != ds[m+1].khoi || (m == cuoiKhoa)){
					cuoiKhoi = m;
					for(n = dauKhoi; n < cuoiKhoi; n++) {
						for(p = n + 1; p <= cuoiKhoi; p++) {
							if(ds[n].lop > ds[p].lop || ((ds[n].lop == ds[p].lop) && strcmp(ds[n].hoVaTen.ten, ds[p].hoVaTen.ten) > 0 )) {
								struct SinhVien sv = ds[n];
								ds[n] = ds[p];
								ds[p] = sv;
								hienThiDSSV(ds,slsv);
							}
						}
					}
					dauKhoi = m + 1;
					
				}
			}

			dauKhoa = i + 1;
		}
	}
	
	capMSSV(ds, slsv);
}

void hienThiTheoKhoa(struct SinhVien* ds, int slsv){
	sapXepTheoTen(ds, slsv);
	int khoa;
	printf("Nhap khoa: \n");
	scanf("%d",&khoa);
	hienThiTenCot();
	for(int i = 0; i < slsv; i++){
		if(ds[i].khoa == khoa){
			hienThiTTSV(ds[i]);
		}
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
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
//	isSorted = 0;
}

void timTheoTen(struct SinhVien* ds, int slsv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(int i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

 void ghiFile(struct SinhVien* ds, int slsv) {
 	FILE* fOut = fopen("dssv", "w");
 	int i;
// 	fprintf(fOut, "%d\n%d\n", slsv, isSorted);
 	fprintf(fOut, "%d\n", slsv);

 	for(int i = 0; i < slsv; i++) {
        fprintf(fOut, "%d\n%d\n%d\n", ds[i].khoa, ds[i].khoi, ds[i].lop);

//        if (isSorted == 0) {
//            fprintf(fOut,"%d\n", -1);
//        } else {
            fprintf(fOut,"%d\n", ds[i].MSSV);
//        }
        fprintf(fOut, "%s\n%s\n%d\n%d\n%d\n%s\n%s\n",
        ds[i].hoVaTen.ho, ds[i].hoVaTen.ten, ds[i].ngaySinh.ngay, ds[i].ngaySinh.thang, ds[i].ngaySinh.nam, ds[i].gioiTinh, ds[i].diaChi);

//        if (isSorted == 0) {
//            fprintf(fOut,"%s\n", "chua-cap");
//        } else {
            fprintf(fOut,"%s\n", ds[i].email);
//        }
 	}
 	fclose(fOut);
 }

 void docFile(struct SinhVien* ds, int *slsv) {
     int a;
    FILE* fIn = fopen("dssv", "r");
    fscanf(fIn, "%d", &a);
    *slsv = a;
//    fscanf(fIn, "%d", &isSorted);
    for (int i = 0; i < *slsv; i++) {
        fscanf(fIn, "%d%d%d", &ds[i].khoa, &ds[i].khoi, &ds[i].lop);
        fscanf(fIn, "%d ", &ds[i].MSSV);
        fflush(stdin);
		fgets(ds[i].hoVaTen.ho, 20, fIn);
		ds[i].hoVaTen.ho[strlen(ds[i].hoVaTen.ho) - 1] = '\0';
        fscanf(fIn, "%s", &ds[i].hoVaTen.ten);
        fscanf(fIn, "%d%d%d", &ds[i].ngaySinh.ngay, &ds[i].ngaySinh.thang, &ds[i].ngaySinh.nam);
		fscanf(fIn, "%s ", &ds[i].gioiTinh);
        fflush(stdin);
		fgets(ds[i].diaChi, 30, fIn);
		ds[i].diaChi[strlen(ds[i].diaChi) - 1] = '\0';
        fscanf(fIn, "%s", &ds[i].email);
    }

 }

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;

    docFile(dssv, &slsv);

	do {
		printf("=============== MENU ===============");
printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep theo ten.");
		printf("\n4. Hien Thi theo khoa.");
		printf("\n5. Sap xep theo .");
		printf("\n6. Xoa sinh vien theo ten.");
		printf("\n7. Tim sinh vien theo ten.");
		printf("\n8. Ghi file");
		printf("\n9. Sap xep theo khoa.");
		printf("\n10. Sap xep theo khoi.");
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
				hienThiTheoKhoa(dssv, slsv);
				printf("\nDanh sach sinh vien hien thi theo khoa:\n");
				
				break;

			case 5:
				sapXep(dssv, slsv);
				printf("\nDanh sach sinh vien sau khi sap xep theo khoa:\n");
				hienThiDSSV(dssv, slsv);
				break;

			case 6:
                xoaSinhVien(dssv,slsv);
                slsv--;
				break;

			case 7:
				timTheoTen(dssv, slsv);
				break;

			case 8:
				ghiFile(dssv, slsv);
				break;
			
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}

	} while(luaChon);

	return 0;
}
