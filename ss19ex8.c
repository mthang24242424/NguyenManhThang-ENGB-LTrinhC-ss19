#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
    char phoneNumber[15];
};

void sortStudents(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van C", 20, "0129626236"},
        {2, "Nguyen Van A", 22, "0987654321"},
        {3, "Nguyen Van D", 21, "021682692"},
        {4, "Nguyen Van B", 23, "0128679126"},
        {5, "Nguyen Van E", 20, "089326896"}
    };

    sortStudents(students, 5);

    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}
