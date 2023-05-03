#ifndef DATA_H
#define DATA_H
using namespace std;
#include "student.h"
#include "teacher.h"
#include "assignment.h"
#include "course.h"
#include <fstream>
#include <sstream>


class Data
{
public:
    Data();
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Course*> courses;
    void pullData();
    void pushData();


};

#endif // DATA_H
