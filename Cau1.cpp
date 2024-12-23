#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudentById(int id, Student students[], int *currentLength) {
    int index = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Khong tim thay sinh vien voi id = %d\n", id);
        return;
    }
    for (int i = index; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }
    (*currentLength)--;
    printf("Da xoa sinh vien voi id = %d\n", id);
}

void printStudents(Student students[], int currentLength) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
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
    int currentLength = 5;
    printStudents(students, currentLength);
    deleteStudentById(3, students, &currentLength);
    printStudents(students, currentLength);
    return 0;
}

