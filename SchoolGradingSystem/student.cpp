#include "course.h"
#include "student.h"

Student::Student(int studentID_, vector<Course> classes_, double gpa_, string password_, string name_) {

    studentID = studentID_;
    classes = classes_;
    gpa = gpa_;
    password = password_;
    name = name_;

}

Student::Student() {


}

void Student::addClass(Course c) {

    classes.push_back(c);

}
void Student::removeClass(Course c) {

    for (int i = 0; i < classes.size(); i++) {

        if (classes[i].getClassID() == c.getClassID()) {

            classes.erase(classes.begin()+i);
        }
    }
}
vector<Course> Student::getClasses() {

    return classes;

}
//int Student::getGrade(Course c) {


//}
bool Student::verifyLogin(int id, string pass) {

    if (id == studentID && pass == password) {return true;}
    else {return false;}

}
int Student::getUserID() {
    return studentID;
}
string Student::getName() {

    return name;
}
string Student::getPassword() {
    return password;
}
