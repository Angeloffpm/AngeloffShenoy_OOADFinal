
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <map>
using namespace std;

class Student;

#include <string>
class Assignment
{


    public:
        Assignment(string name);

        void inputScore(Student* student, int score);
        int getScore(Student* student) const;
        map<Student*, int> getAllScores();
        void updateScore(Student* student, int score); // *update* i thought this was a good idea, so i kept and implemented it
        int getWeight();
        string getTitle() const;

    protected:
        int weight;

    private:
        string title;
        map<Student*, int> scores;




};

class Homework : public Assignment {

    public:
        Homework(string name);


};

class Quiz : public Assignment {

    public:
        Quiz(string name);

};

class Exam : public Assignment {

    public:
        Exam(string name);

};

#endif // ASSIGNMENT_H
