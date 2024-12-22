#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;
void in(SinhVien sv[], int soLuong);
void deleteStudent(SinhVien sv[], int *soLuong, const char *deleteItem);
int main() {
    SinhVien sv[50] = {
        {1, "Nguyen Van A", 31, "0923676436"},
        {2, "Nguyen Van B", 21, "01469326"},
        {3, "Nguyen Van C", 17, "01240769162346"},
        {4, "Nguyen Van D", 19, "0123850"},
        {5, "Nguyen Van E", 23, "01983516"}
    };
    int soLuong = 5;
    char deleteItem[50];
    printf("danh sach ban dau:\n");
    in(sv, soLuong);
    printf("\nnhap ten sv can xoa: ");
    fgets(deleteItem, sizeof(deleteItem), stdin);
    deleteItem[strcspn(deleteItem, "\n")] = '\0'; // Lo?i b? k? t? xu?ng d?ng
    deleteStudent(sv, &soLuong, deleteItem);
    printf("\ndanh sach sau khi xoa:\n");
    in(sv, soLuong);
    return 0;
}

void in(SinhVien sv[], int soLuong) {
    printf("danh sach sv:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("ID: %d, ten: %s, tuoi: %d, sdt: %s\n",
               sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}
void deleteStudent(SinhVien sv[], int *soLuong, const char *deleteItem) {
    int viTriXoa = -1;
    for (int i = 0; i < *soLuong; i++) {
        if (strcmp(sv[i].name, deleteItem) == 0) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa == -1) {
        printf("sv ten \"%s\" ko co.\n", deleteItem);
    } else {
        for (int i = viTriXoa; i < *soLuong - 1; i++) {
            sv[i] = sv[i + 1];
        }
        (*soLuong)--;
        printf("da xoa sv\"%s\".\n", deleteItem);
    }
}
