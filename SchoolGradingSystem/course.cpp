#include "course.h"
#include "student.h"

// Constructors
Course::Course(string name_, int classID_)
{
    name = name_;
    classID = classID_;
}

Course::Course(string name, int classID, Teacher *t)
{
    this->name = name;
    this->classID = classID;
    this->teacher = t;
}

//int Class::getStudentGrade(Student s) {



//}

// Getters
int Course::getClassID() { return classID; }
string Course::getClassName() { return name; }
//    Teacher getTeacher() const;
vector<Student> Course::getStudents() { return students; }

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

void Course::assignTeacher(Teacher *t) { this->teacher = t; }

void Course::printGradesHelper(QWidget* parent) {
    QVBoxLayout* layout = new QVBoxLayout;
    QWidget* widget = new QWidget(parent); // Define widget before using it

    for (auto [student, assignment] : assignments) {
        QString text = QString::fromStdString(student->getName()) +
                       " | " +
                       QString::fromStdString(assignment->getTitle()) +
                       ": " +
                       QString::number(assignment->getScore(student));
        QLabel* label = new QLabel(text, widget);
        layout->addWidget(label);
    }

    widget->setLayout(layout);
    layout->addStretch();
    widget->show();
}


int Course::getStudentGrade(Student s) {

//    for (pair<Assignment, Student> assignment: assignments) {

    // need to calculate grade before returning

//    }

    return NULL;

}
void Course::addAssignment(Student* s, Assignment* a) {

    assignments.insert(make_pair(s,a));

}

