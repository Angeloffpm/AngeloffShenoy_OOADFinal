
#include "teacher.h"

Teacher::Teacher()
{
    this->name = "Rob Bob";
    this->courses = vector<Course*>();
}

string Teacher::getName() { return this->name; }
vector<Course*> Teacher::getCourses() { return this->courses; }
