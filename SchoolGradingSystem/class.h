#ifndef CLASS_H
#define CLASS_H
#include <string>
#include "student.h"


class Student;
class Class
{
public:
    Class(string name, int classID, vector<Student> students);
    int getStudentGrade(Student s);
    int getClassID();
    std::string getClassName();
//    Teacher getTeacher() const;
    std::vector<Student> getStudents();
    void addStudent(Student s);
    void removeStudent(Student s);
    void printGrades();
    int getStudentGrade(Student s);
    void addAssignment(string name_, int score, Student s);

private:
    int classID;
    string name;
    // Teacher teacher;
    vector<Student> students;
    vector<pair<Assignment, Student>> assignments;
};

#endif // CLASS_H
