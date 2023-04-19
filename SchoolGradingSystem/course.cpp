#include "course.h"
#include "student.h"


Course::Course(string name_, int classID_)
{
    name = name_;
    classID = classID_;

}

//int Class::getStudentGrade(Student s) {



//}
int Course::getClassID() {

    return classID;
}
string Course::getClassName() {

    return name;
}
//    Teacher getTeacher() const;
vector<Student> Course::getStudents() {

    return students;
}
void Course::addStudent(Student s) {

    students.push_back(s);

}
void Course::removeStudent(Student s) {

    for (int i = 0; i < students.size(); i++) {

        if (students[i].getUserID() == s.getUserID()) {

            students.erase(students.begin()+i);
        }
    }
}
void Course::printGrades() {

    for (pair<Assignment, Student> assignment: assignments) {

        // cout << student.getName() << " | " << assignment.name << " | " << assignment.score << endl;
    }

}
int Course::getStudentGrade(Student s) {

    for (pair<Assignment, Student> assignment: assignments) {

        if (s.getUserID() == assignment.second.getUserID()) {return assignment.first.score;}
    }

    return NULL;

}
void Course::addAssignment(string name_, int score_, Student s) {

    Assignment a;
    a.name = name_;
    a.score = score_;
    assignments.push_back(pair<Assignment,Student> {a,s});
}

