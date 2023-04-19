#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
#include <vector>



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
    void printGrades();
    void addAssignment(string name_, int score, Student s);
    int getStudentGrade(Student s);

private:
    struct Assignment {

        string name;
        int score;

    };
    int classID;
    string name;
    // Teacher teacher;
    vector<Student> students;
    vector<pair<Assignment, Student>> assignments;

};

#endif // COURSE_H
