#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    string grade;
};

bool compareByName(const Student& s1, const Student& s2) {
    return s1.name < s2.name;
}

int main() {
    ifstream file1("File1.txt");
    ifstream file2("File2.txt");
    ofstream outputFile("New.txt");

    vector<Student> students;

    string line;
    while (getline(file1, line)) {
        Student student;
        student.name = line.substr(0, line.find(' '));
        student.grade = line.substr(line.find(' ') + 1);
        students.push_back(student);
    }

    while (getline(file2, line)) {
        Student student;
        student.name = line.substr(0, line.find(' '));
        student.grade = line.substr(line.find(' ') + 1);
        students.push_back(student);
    }

    sort(students.begin(), students.end(), compareByName);

    for (const auto& student : students) {
        outputFile << student.name << " " << student.grade << "\n";
    }

    cout << "Done! file is named New.txt" << endl;

    file1.close();
    file2.close();
    outputFile.close();
}