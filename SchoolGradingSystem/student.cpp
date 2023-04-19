#include "student.h"
#include "ui_student.h"

Student::Student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
}

Student::Student(int studentID_, vector<Class> classes_, double gpa_, string password_, string name_) {

    studentID = studentID_;
    classes = classes_;
    gpa = gpa_;
    password = password_;
    name = name_;

}

Student::~Student()
{
    delete ui;
}

void Student::addClass(Class c) {

    classes.push_back(c);

}
void Student::removeClass(Class c) {

    classes.erase(remove(classes.begin(), classes.end(), c), classes.end());

}
vector<Class> Student::getClasses() {

    return classes;

}
int Student::getGrade(Class c) {

    return c.getStudentGrade(this);
}
bool Student::verifyLogin(string id, string pass) {

    if (id == studentID && pass == password) {return true;}
    else {return false;}

}
int Student::getUserID() {
    return studentID;
}
string Student::getPassword() {
    return password;
}
