#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
    int fn;
    char name[100];
    double grade;
};

void writeStudents(Student students[], std::ofstream& out) {
    for (int i = 0; i < 3; i++) {
        out << students[i].fn << " ";
        out << students[i].name << '\n';
        out << students[i].grade << '\n';
    }    
}

void writeStudents(Student students[], const char* path) {
    std::ofstream out;
    out.open(path);

    for (int i = 0; i < 3; i++) {
        out << students[i].fn << " ";
        out << students[i].name << '\n';
        out << students[i].grade << '\n';
    }  

    out.close();
}


const int BUFFER_SIZE = 100;
void readStudents(const char* path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cout << "File is not open!" << std::endl;
        return;
    }

    while (!in.eof()) {
        char line[BUFFER_SIZE];
        in.getline(line, BUFFER_SIZE);
        std::cout << line << std::endl;
    }

    in.close();
}

/* 
    if (in) -> in.good()
    if (!in) -> in.bad() || in.fail() || in.eof()
*/

void readStudents(std::ifstream& in) {
    if (!in.is_open()) {
        std::cout << "File is not open!" << std::endl;
        return;
    }

    while (!in.eof()) {
        char line[BUFFER_SIZE];
        in.getline(line, BUFFER_SIZE);
        std::cout << line << std::endl;
    }
}

int main() {
    Student nasko;
    nasko.fn = 71937;
    nasko.grade = 5.50;
    strcpy(nasko.name, "Nasko");

    Student nasko2;
    nasko2.fn = 71607;
    nasko2.grade = 5.70;
    strcpy(nasko2.name, "Nasko2");

    Student nasko3;
    nasko3.fn = 72937;
    nasko3.grade = 5.20;
    strcpy(nasko3.name, "Nasko3");

    Student students[] = {nasko, nasko2, nasko3};
    
    // input/output
    writeStudents(students, "students.txt");
    readStudents("students.txt");
}