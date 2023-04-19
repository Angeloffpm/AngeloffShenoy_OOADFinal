#include "class.h"

Class::Class(string name_, int classID_, vector<Student> students_)
{
    name = name_;
    classID = classID_;
    students = students_;

}

int Class::getStudentGrade(Student s) {



}
int Class::getClassID() {

    return classID;
}
string Class::getClassName() {

    return name;
}
//    Teacher getTeacher() const;
vector<Student> Class::getStudents() {

    return students;
}
void Class::addStudent(Student s) {

    students.push_back(s);

}
void Class::removeStudent(Student s) {

    students.erase(remove(students.begin(), students.end(), s), students.end());
}
void Class::printGrades() {

    for (pair<Assignment, Student> assingment: assignments) {

        // cout << student.getName() << " | " << assignment.name << " | " << assignment.score << endl;
    }

}
int Class::getStudentGrade(Student s) {

    for (pair<Assignment, Student> assingment: assignments) {

        if (s == assingment.second) {return assingment.score;}
    }

}
void Class::addAssignment(string name_, int score_, Student s) {

    Assignment a;
    a.name = name_;
    a.score = score_;
    assignments.push_back(pair<Assignment,Student> {a,s});
}

