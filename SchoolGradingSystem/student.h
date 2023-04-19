#ifndef STUDENT_H
#define STUDENT_H
#include <QMainWindow>
#include <vector>
using namespace std;
//#include "course.h"




namespace Ui {
class Student;
}
class Course;
class Student
{
public:
    Student(int studentID_, vector<Course> classes_, double gpa_, string password_, string name_);
    Student();
    void addClass(Course c);
    void removeClass(Course c);
    vector<Course> getClasses();
    int getGrade(Course c);
    bool verifyLogin(int id, string pass);
    int getUserID();
    string getPassword();

    void exit();

private:

    struct Assignment {

        string name;
        int score;

    };
    int studentID;
    vector<Course> classes;
    double gpa;
    string password;
    string name;



};

#endif // STUDENT_H