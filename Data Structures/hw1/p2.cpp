#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

struct studentData {
  string studentName;
  int homework;
  int recitation;
  int quiz;
  int exam;
  double average;
};

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);
char calcLetter(double avg);
void printList(const studentData students[], int length);

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length) {
  double examf = exam;
  double homeworkf = homework;
  double recitationf = recitation;
  double quizf = quiz;
  studentData * student = new studentData();
  student->studentName = studentName;
  student->homework = homework;
  student->recitation = recitation;
  student->quiz = quiz;
  student->exam = exam;
  student->average = ((homeworkf + recitationf + quizf + examf) / 4);
  students[length] = *student;
}

// void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length) {
//   studentData student;
//   student.studentName = studentName;
//   student.homework = homework;
//   student.recitation = recitation;
//   student.quiz = quiz;
//   student.exam = exam;
//   student.average = (homework + recitation + quiz + exam) / 4;
//   students[length] = student;
// 

char calcLetter(double avg) {
  if (avg >= 90) {
    return 'A';
  } else if (avg >= 80) {
    return 'B';
  } else if (avg >= 70) {
    return 'C';
  } else if (avg >= 60) {
    return 'D';
  } else {
    return 'F';
  }
}

void printList (const studentData students[], int length) {
  for (int i = 0; i < length; i++) {
    char letter = calcLetter(students[i].average);
    printf("%s earned %g which is a(n) %c\n", students[i].studentName.c_str(), students[i].average, letter);
  }
}

int main (int argc, char * argv[]) {
  ofstream output(argv[2]);
  ifstream input(argv[1]);

  string line;
  int count = 0;
  while(getline(input, line)) count++;
  
  for (int i = 0; i < count; i++) {
    stringstream()
  }

  return 0;
}