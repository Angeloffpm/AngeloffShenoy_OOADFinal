
#include "datatest.h"

DataTest::DataTest()
{
    this->teachers.push_back(new Teacher("John Doe", "jdoe", "test123"));
    this->teachers.push_back(new Teacher("Jeff Hoefs", "jhoefs", "hoefs123"));
    this->students.push_back(new Student(157235, courses, 3.4, "password123", "James Green"));
    this->students.push_back(new Student(237165, courses, 3.7, "jamesgreensux", "Rachel Green"));
    courses = {new Course("Calculus 1", 1000), new Course("Calculus 2", 1100), new Course("Calculus 3", 1200)};
}

Teacher* DataTest::findTeacherUser(string user_) {
    for (auto t : this->teachers)
    {
        if (t->getUsername() == user_) return t;
    }
    return nullptr;
}

Student* DataTest::findStudentUser(string user_) {

    for (auto s : this->students)
    {
        if (s->getName() == user_) return s;
    }
    return nullptr;

}

vector<Course*> DataTest::getCourses() {

    return courses;
}


vector<Student*> DataTest::getStudents() {

    return students;

}


vector<Teacher*> DataTest::getTeachers() {

    return teachers;

}

void DataTest::addCourse(Course* c) {

    courses.push_back(c);

}
