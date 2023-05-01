
#ifndef DATATEST_H
#define DATATEST_H

#include "course.h"
#include "student.h"
#include "teacher.h"

class DataTest
{
    public:
        DataTest();
        vector<Course*> getCourses();
        vector<Student*> getStudents();
        vector<Teacher*> getTeachers();
        Teacher* findTeacherUser(string user_);

    private:
        vector<Course*> courses;
        vector<Student*> students;
        vector<Teacher*> teachers;

};

#endif // DATATEST_H