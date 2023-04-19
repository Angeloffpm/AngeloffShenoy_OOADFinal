
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
private:
    string name;
    vector<Course*> courses;
};

#endif // TEACHER_H
