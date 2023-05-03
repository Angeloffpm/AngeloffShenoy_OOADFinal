
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <map>
using namespace std;

class Student;

#include <string>
class Assignment
{


    public:
        Assignment(string name, int totalPoints);
        
        void inputScore(Student* student, int score);
        int getScore(Student* student) const;
        map<Student*, int> getAllScores();
        void updateScore(Student* student, int score); // *update* i thought this was a good idea, so i kept and implemented it
        int getWeight();
        string getTitle() const;

    protected:
        int totalPoints;
        int weight;

    private:
        string title;
        map<Student*, int> scores;




};

class Homework : public Assignment {

    public:
        Homework(string name, int totalPoints);


};

class Quiz : public Assignment {

    public:
        Quiz(string name, int totalPoints);

};

class Exam : public Assignment {

    public:
        Exam(string name, int totalPoints);

};

#endif // ASSIGNMENT_H
