#include <iostream>
#include <cstring>
#include <fstream>

/* 
    if (in) -> in.good()
    if (!in) -> in.bad() || in.fail() || in.eof()
*/

struct Student {
    int facNum; // -> 4 bytes
    char name[64]; // -> 64 bytes

    void print() {
        std::cout << facNum << " " << name << std::endl;
    }
};

void writeStudents(const Student students[], const char* path) {
    std::ofstream out(path, std::ios::binary);

    if (!out) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        out.write((char*) &students[i], sizeof(Student));
    }

    out.close();
}

void readStudents(const Student students[], const char* path) {
    std::ifstream in(path, std::ios::binary);

    if (!in.is_open() && !in) {
        std::cout << "Cannot read from file" << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        in.read((char*) &students[i], sizeof(Student));
        std::cout << students[i].facNum << std::endl;
        std::cout << students[i].name << std::endl;
    }

    in.close();
}

int main() {
    Student students[3];
    students[0].facNum = 71935;
    strcpy(students[0].name, "Mitko");
    students[1].facNum = 70461;
    strcpy(students[1].name, "Atanas");
    students[2].facNum = 72005;
    strcpy(students[2].name, "Ivo");

    writeStudents(students, "students.bin");
    readStudents(students, "students.bin");
}