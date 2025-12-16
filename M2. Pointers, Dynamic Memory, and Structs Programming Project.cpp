// M2. Pointers, Dynamic Memory, and Structs Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

 // Student struct holds student name, ID, pointer to test scores array,
 // average score, and letter grade
struct student {
    string name;
    int id;
    double* testScores;
    double average;
    char letterGrade;
};

student* getData(ifstream& file, int& studentCnt, int& testsCnt) {
    file >> studentCnt >> testsCnt;

    // Allocate array of students dynamically
    student* students = new student[studentCnt];

    for (int i = 0; i < studentCnt; ++i) {
        file >> students[i].name >> students[i].id;

        // Allocate test scores array dynamically
        students[i].testScores = new double[testsCnt];

        for (int j = 0; j < testsCnt; ++j) {
            file >> students[i].testScores[j];
        }
        // Initialize average and grade to default
        students[i].average = 0.0;
        students[i].letterGrade = 'F';
    }
    return students;
}

//Calculates average test score and letter grade for each student.
void calcAverage(student students[], int studentCnt, int testsCnt);

//Returns letter grade from average test score.
char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}


//Prints a formatted report showing Student name, ID, average score, and letter grade.
void printReport(const student students[], int studentCnt);

int main() {
    ifstream inputFile("student_data.txt");

    if (!inputFile) {
        cerr << "Error: could not open file student_data.txt" << endl;
        return 1;
    }

    int numStudents = 0;
    int numTests = 0;
    student* students = getData(inputFile, numStudents, numTests);
    inputFile.close();

    calcAverage(students, numStudents, numTests);

    printReport(students, numStudents);

    // Free dynamically allocated memory
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].testScores;
    }
    delete[] students;

    return 0;
}

void calcAverage(student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; ++i) {
        double sum = 0.0;
        for (int j = 0; j < testsCnt; ++j) {
            sum += students[i].testScores[j];
        }
        students[i].average = sum / testsCnt;
        students[i].letterGrade = getLetterGrade(students[i].average);
    }
}

void printReport(const student students[], int studentCnt) {
    cout << left << setw(15) << "Student"
        << setw(10) << "ID"
        << setw(10) << "Score"
        << "Grade" << endl;
    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(1);

    for (int i = 0; i < studentCnt; ++i) {
        cout << left << setw(15) << students[i].name
            << setw(10) << students[i].id
            << setw(10) << students[i].average
            << students[i].letterGrade
            << endl;
    }
}