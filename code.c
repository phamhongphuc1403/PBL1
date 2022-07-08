#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien;

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

struct khoa {
    char tenKhoa[40];
    int maKhoa;
};

int soLuongKhoa;
struct khoa khoaData[20];

void gioiThieu();
void docKhoa();
void nhapKhoa(struct SinhVien *sv);
int checkKhoa(struct khoa khoaData[], char tenKhoa[]);
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();
int MSSV_database[101];
int MSSV_database_index = 0;
void addMSSVtoDatabase(struct SinhVien* sv);
int checkMSSVinDatabase(struct SinhVien* sv);
struct SinhVien nhapSV();
void nhapMSSV(struct SinhVien* sv);
void nhapHoTen(struct HoTen* ten);
void nhapNgaySinh(struct NgaySinh* ngaySinh);
void hienThiTenCot();
void hienThiDSSV(struct SinhVien* ds, int slsv);
void hienThiTTSV(struct SinhVien sv);
void hienThiNgaySinh(struct SinhVien sv);
void hienThiMSSVvaEmail(struct SinhVien sv, int theLoai);
void capMssvEmail(struct SinhVien* ds, int slsv);
void sapXepTheoTen(struct SinhVien* ds, int slsv);
void sapXep(struct SinhVien* ds, int slsv);
void hienThiTheoKhoa(struct SinhVien* ds, int slsv);
void hienThiTheoLop(struct SinhVien* ds, int slsv);
void xoaSinhVien(struct SinhVien* ds, int slsv);
int timTheoTen(struct SinhVien* ds, int slsv, char ten[]);
void ghiFile(struct SinhVien* ds, int slsv);
void ghiFileAll(struct SinhVien* ds, int slsv);
void ghiFileLop(struct SinhVien *ds, int slsv, int count, int lop);
void ghiFileKhoa(struct SinhVien *ds, int slsv, int count, int khoa);
void docFile(struct SinhVien* ds, int *slsv);


int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	int chon;

    docFile(dssv, &slsv);
    docKhoa();
    gioiThieu();
	do {
		printf("\n\n=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep danh sach sinh vien.");
		printf("\n4. Xoa sinh vien theo ten.");
		printf("\n5. Tim sinh vien theo ten.");
		printf("\n6. Ghi file");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");

		scanf("%d", &luaChon);
		struct SinhVien sv;
        system("cls");
		switch(luaChon) {
			case 0:
				break;

			case 1:
				sv = nhapSV();
				dssv[slsv++] = sv;
				break;

			case 2:
				printf("\n1. Hien thi theo toan bo.");
				printf("\n2. Hien thi theo khoa.");
				printf("\n3. Hien thi theo lop.");
				printf("\nBan chon ? ");
				scanf("%d", &chon);
				switch(chon) {
					case 1:
						hienThiDSSV(dssv, slsv);
						break;

					case 2:
						printf("\nDanh sach sinh vien hien thi theo khoa:\n");
						hienThiTheoKhoa(dssv, slsv);
						break;

					case 3:
						printf("\nDanh sach sinh vien hien thi theo lop:\n");
						hienThiTheoLop(dssv, slsv);
						break;

					default:
						printf("Sai chuc nang, vui long chon lai!\n");
						break;
				}
				break;

			case 3:
				printf("\n1. Sap xep toan bo hssv theo ten.");
				printf("\n2. Sap xep theo theo khoa, cap mssv.");
				printf("\nBan chon ? ");
				scanf("%d", &chon);
				switch(chon) {
					case 1:
						sapXepTheoTen(dssv, slsv);
						printf("\nDanh sach sinh vien sau khi sap xep theo ten a-z:\n");
						hienThiDSSV(dssv, slsv);
						break;

					case 2:
						sapXep(dssv, slsv);
						printf("\nDanh sach sinh vien sau khi sap xep theo khoa:\n");
						hienThiDSSV(dssv, slsv);
						break;
					default:
						printf("Sai chuc nang, vui long chon lai!\n");
						break;
				}
				break;

			case 4:
                xoaSinhVien(dssv,slsv);
                slsv--;

				break;

			case 5:
			    printf("nhap ten sinh vien can tim: ");
			    char ten[50];
			    scanf("%s", &ten);
				timTheoTen(dssv, slsv, ten);
				break;

			case 6:
				ghiFile(dssv, slsv);
				break;

			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}

	} while(luaChon);

	return 0;

}

void gioiThieu() {
    printf("\t ______________________________________________________________________________________________ \n");
    printf("\t|                                                                                              |\n");
    printf("\t|                                 DO AN PBL1: LAP TRINH TINH TOAN                              |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|                       DE TAI: XAY DUNG UNG DUNG QUAN LY DANH SACH SINH VIEN                  |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|                            Giao vien huong dan: Nguyen Thi Minh Hy                           |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|                        Sinh vien thuc hien:  Pham Hong Phuc - 102210271                      |\n");
    printf("\t|                                              Tran Van Duc Son - 102210275                    |\n");
    printf("\t|                                                                                              |\n");
    printf("\t|______________________________________________________________________________________________|\n");
}

void addMSSVtoDatabase(struct SinhVien* sv) {
    MSSV_database[MSSV_database_index++] = sv->MSSV;
}

int checkMSSVinDatabase(struct SinhVien* sv) {
    for (int i = 0; i <= MSSV_database_index; i++) {
        if (sv->MSSV == MSSV_database[i]) return 0;
    }
    return 1;
}

struct SinhVien nhapSV() {
		struct SinhVien sv;

        nhapKhoa(&sv);
        printf("Nam hoc: ");
        scanf("%d", &sv.khoi);
        printf("Lop: ");
        scanf("%d", &sv.lop);

        nhapMSSV(&sv);
        addMSSVtoDatabase(&sv);
		nhapHoTen(&sv.hoVaTen);
		nhapNgaySinh(&sv.ngaySinh);
		printf("Gioi tinh: ");
		scanf("%s", sv.gioiTinh);
		printf("Nhap dia chi: ");
		getchar();
		gets(sv.diaChi);
		return sv;
}

void docKhoa() {
    FILE* fIn = fopen("khoa", "r");
    fscanf(fIn, "%d ", &soLuongKhoa);
    for (int i = 0; i < soLuongKhoa; i++) {
        fflush(stdin);
        fgets(khoaData[i].tenKhoa, 40, fIn);
        khoaData[i].tenKhoa[strlen(khoaData[i].tenKhoa) - 1] = '\0';
        fscanf(fIn, "%d ", &khoaData[i].maKhoa);
    }

}

void nhapKhoa(struct SinhVien *sv) {
//       for (int i = 0; i < soLuongKhoa; i++) {
//       printf("%s\n%d\n", khoaData[i].tenKhoa, khoaData[i].maKhoa);
//   }
    int choice = 1;
    printf("Ban muon: \n1. Nhap ten khoa.\n2. Nhap ma khoa.\nBan chon: ");
    scanf("%d", &choice);
    if (choice == 1) {
        char tenKhoa[50];
        while (1) {
            printf("Nhap ten khoa: ");
            fflush(stdin);
            gets(tenKhoa);
            int pos = checkKhoa(khoaData, tenKhoa);
            if (pos != -1) {
                sv->khoa = khoaData[pos].maKhoa;
                break;
            } else {
                printf("ten khoa sai, vui long nhap lai.\n");
                continue;
            }
        }
    } else {
        printf("Nhap ma khoa: ");
        scanf("%d", &sv->khoa);
    }
}

int checkKhoa(struct khoa khoaData[], char tenKhoa[]) {
    for (int i = 0; i < soLuongKhoa; i++) {
        if (strcmp(khoaData[i].tenKhoa, tenKhoa) == 0)  return i;
    }
    return -1;
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
            strcpy(sv->email, "chua-cap");
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
		"Khoa", "Nam hoc", "Lop", "MSSV", "Ho", "Ten", "Ngay Sinh", "Gioi Tinh", "Dia Chi", "Email");
}

void hienThiDSSV(struct SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\nban co muon luu vao file khong? (1/0): ");

    int choice;
	scanf("%d", &choice);
	if (choice == 1) ghiFileAll(ds, slsv);
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
        if (theLoai == 0) {
            printf("%-16d", sv.MSSV);
        } else {
            printf("%-30s", sv.email);
        }
}

void capMssvEmail(struct SinhVien* ds, int slsv) {
    int i = 0, j = 1;
    while (i < slsv) {
        if (ds[i].MSSV == -1) {
			if (ds[i].khoa != ds[i - 1].khoa || ds[i].khoi != ds[i - 1].khoi) j = 1;
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
			for(m = dauKhoa; m <= cuoiKhoa; m++){
				if(ds[m].khoi != ds[m+1].khoi || (m == cuoiKhoa)){
					cuoiKhoi = m;
					for(n = dauKhoi; n < cuoiKhoi; n++) {
						for(p = n + 1; p <= cuoiKhoi; p++) {
							if(ds[n].lop > ds[p].lop || ((ds[n].lop == ds[p].lop) && strcmp(ds[n].hoVaTen.ten, ds[p].hoVaTen.ten) > 0 )) {
								struct SinhVien sv = ds[n];
								ds[n] = ds[p];
								ds[p] = sv;
							}
						}
					}
					dauKhoi = m + 1;

				}
			}

			dauKhoa = i + 1;
		}
	}

	capMssvEmail(ds, slsv);
}

void hienThiTheoKhoa(struct SinhVien* ds, int slsv){
	sapXepTheoTen(ds, slsv);
	int khoa, count = 0;
	printf("Nhap khoa: \n");
	scanf("%d",&khoa);
	hienThiTenCot();
	for(int i = 0; i < slsv; i++){
		if(ds[i].khoa == khoa){
			hienThiTTSV(ds[i]);
			++count;
		}
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\nban co muon luu vao file khong? (1/0): ");

    int choice;
	scanf("%d", &choice);
	if (choice == 1) ghiFileKhoa(ds, slsv, count, khoa);
}

void hienThiTheoLop(struct SinhVien* ds, int slsv){
	sapXepTheoTen(ds, slsv);
	int lop, count = 0;
	printf("Nhap lop: \n");
	scanf("%d",&lop);
	hienThiTenCot();
	for(int i = 0; i < slsv; i++){
		if(ds[i].lop == lop){
			hienThiTTSV(ds[i]);
			++count;
		}
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\nban co muon luu vao file khong? (1/0): ");

	int choice;
	scanf("%d", &choice);
	if (choice == 1) ghiFileLop(ds, slsv, count, lop);
}

void xoaSinhVien(struct SinhVien* ds, int slsv){
    char ten[20];
	printf("Nhap ten sinh vien can xoa: ");
	scanf("%s", ten);

    int total = timTheoTen(ds, slsv, ten);
    if (total != 0) {
        int pos;
        do {
            printf("\nnhap so thu tu cua sinh vien can xoa: ");
            scanf("%d", &pos);

            if (pos > total) {
                printf("so thu tu lon hon so luong sinh vien da tim thay, xin vui long thu lai.\n");
            } else {
                int count = 0;
                for(int i = 0; i < slsv; i++) {
                    if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
                        ++count;
                        if (count == pos) {
                            for(int j = i; j <slsv -1; j++){
                                ds[j] = ds[j+1];
                            }
                        }
                    }
                }
                printf("xoa thanh cong.");
                break;
            }
        } while (pos > total);
    }
}

int timTheoTen(struct SinhVien* ds, int slsv, char ten[]) {
	hienThiTenCot();
	int i, count = 0;
	for(int i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
            ++count;
		}
	}
	if(count == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}

	return count;
}

void ghiFile(struct SinhVien* ds, int slsv) {
    printf("\n1. Luu toan bo sinh vien\n2. Luu sinh vien theo khoa\n3. Luu sinh vien theo lop\nBan chon: ");
    int choice, khoa, lop, count = 0;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            ghiFileAll(ds, slsv);
            break;
        case 2:
            printf("nhap ma khoa: ");
            scanf("%d", &khoa);
            for(int i = 0; i < slsv; i++) {
                if(ds[i].khoa == khoa) count++;
            }
            ghiFileKhoa(ds, slsv, count, khoa);
            break;
        case 3:
            printf("nhap lop: ");
            scanf("%d", &lop);
            for(int i = 0; i < slsv; i++) {
                if(ds[i].lop == lop) count++;
            }
            ghiFileLop(ds, slsv, count, lop);
            break;
    }
}

void ghiFileAll(struct SinhVien* ds, int slsv) {
 	FILE* fOut = fopen("dssv", "w");
 	int i;
 	fprintf(fOut, "%d\n\n", slsv);

 	for(int i = 0; i < slsv; i++) {
        fprintf(fOut, "%d\n%d\n%d\n", ds[i].khoa, ds[i].khoi, ds[i].lop);
        fprintf(fOut,"%d\n", ds[i].MSSV);
        fprintf(fOut, "%s\n%s\n%d\n%d\n%d\n%s\n%s\n",
        ds[i].hoVaTen.ho, ds[i].hoVaTen.ten, ds[i].ngaySinh.ngay, ds[i].ngaySinh.thang, ds[i].ngaySinh.nam, ds[i].gioiTinh, ds[i].diaChi);
        fprintf(fOut,"%s\n\n", ds[i].email);
 	}
 	fclose(fOut);
 }

void ghiFileLop(struct SinhVien *ds, int slsv, int count, int lop) {
    char ten_lop[20] = {'l', 'o', 'p', ' ', '\0'}, lop_string[10];
    itoa(lop, lop_string, 10);
    strcat(ten_lop, lop_string);

    FILE* fOut = fopen(ten_lop, "w");

    fprintf(fOut, "%d\n\n", count);

    for(int i = 0; i < slsv; i++) {
        if(ds[i].lop == lop){
            fprintf(fOut, "%d\n%d\n%d\n", ds[i].khoa, ds[i].khoi, ds[i].lop);
            fprintf(fOut,"%d\n", ds[i].MSSV);
            fprintf(fOut, "%s\n%s\n%d\n%d\n%d\n%s\n%s\n",
            ds[i].hoVaTen.ho, ds[i].hoVaTen.ten, ds[i].ngaySinh.ngay, ds[i].ngaySinh.thang, ds[i].ngaySinh.nam, ds[i].gioiTinh, ds[i].diaChi);
            fprintf(fOut,"%s\n\n", ds[i].email);
        }
    }
    fclose(fOut);
}

void ghiFileKhoa(struct SinhVien *ds, int slsv, int count, int khoa) {
    char ten_khoa[20] = {'k', 'h', 'o', 'a', ' ', '\0'}, khoa_string[10];
    itoa(khoa, khoa_string, 10);
    strcat(ten_khoa, khoa_string);

    FILE* fOut = fopen(ten_khoa, "w");

    fprintf(fOut, "%d\n\n", count);

    for(int i = 0; i < slsv; i++) {
        if(ds[i].khoa == khoa){
            fprintf(fOut, "%d\n%d\n%d\n", ds[i].khoa, ds[i].khoi, ds[i].lop);
            fprintf(fOut,"%d\n", ds[i].MSSV);
            fprintf(fOut, "%s\n%s\n%d\n%d\n%d\n%s\n%s\n",
            ds[i].hoVaTen.ho, ds[i].hoVaTen.ten, ds[i].ngaySinh.ngay, ds[i].ngaySinh.thang, ds[i].ngaySinh.nam, ds[i].gioiTinh, ds[i].diaChi);
            fprintf(fOut,"%s\n\n", ds[i].email);
        }
    }
    fclose(fOut);
}

void docFile(struct SinhVien* ds, int *slsv) {
    int a;
    FILE* fIn = fopen("dssv", "r");
    fscanf(fIn, "%d", &a);
    *slsv = a;
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
