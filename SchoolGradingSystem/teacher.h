
#ifndef TEACHER_H
#define TEACHER_H

#include <vector>
#include "course.h"


class Teacher
{
public:
    Teacher();
    Teacher(string name);

    string getName();
    vector<Course*> getCourses();
private:
    string name;
    vector<Course*> courses;
};

#endif // TEACHER_H
