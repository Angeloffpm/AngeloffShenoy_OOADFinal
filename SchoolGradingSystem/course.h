#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include "assignment.h"


class Student;
class Course
{
public:
    Course(string name, int classID);
    int getClassID();
    string getClassName();
//    Teacher getTeacher() const;

    vector<Student> getStudents();
    void addStudent(Student s);
    void removeStudent(Student s);
    void printGradesHelper(QWidget* parent);
    void addAssignment(Student* s, Assignment* a);
    int getStudentGrade(Student s);
    map<Student*, Assignment*> assignments;

private:
    int classID;
    string name;
    // Teacher teacher;
    vector<Student> students;


};

#endif // COURSE_H
