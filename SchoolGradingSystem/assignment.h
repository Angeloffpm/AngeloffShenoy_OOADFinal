
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <map>

class Student;

#include <string>
class Assignment
{
    public:
        Assignment();

        void inputScore(Student* student, int score);
        int getScore(Student* student);
        std::map<Student*, int> getAllScores();
        int updateScore(Student* student, int score); // <-- This may not be necessary. Maybe just make inputScore also able to update already existing scores. Your call.
        int getWeight();

    private:
        std::string title;
        std::map<Student*, int> scores;
        int weight;

};

class Homework : public Assignment {

    public:
        Homework();

};

class Quiz : public Assignment {

    public:
        Quiz();

};

class Exam : public Assignment {

    public:
        Exam();

};

#endif // ASSIGNMENT_H
