#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void sortStudentsByName(Student students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(Student students[], int length) {
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "Ngo Quang Anh", 20, "0386878941"},
        {2, "Anh", 21, "0969510625"},
        {3, "Quang Anh", 22, "1516123132"},
        {4, "A", 23, "48526"},
        {5, "B", 24, "56138"}
    };
    int length = 5;
    printf("Danh sach sinh vien truoc khi sap xep:\n");
    printStudents(students, length);
    sortStudentsByName(students, length);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    printStudents(students, length);
    return 0;
}

