
#include "assignment.h"

Assignment::Assignment(string name, int totalPoints)
{
    title = name;
    this->totalPoints = totalPoints;
}

void Assignment::inputScore(Student* student, int score) {

    scores.insert(make_pair(student, score));

}

int Assignment::getScore(Student* student) const {

    auto found = scores.find(student);

    if (found != scores.end()) {return found->second;}
    else {return NULL;}

}

 map<Student*, int> Assignment::getAllScores() {

    return scores;

}

void Assignment::updateScore(Student* student, int score) {

    scores[student] = score;

}

int Assignment::getWeight() {

    return weight;

}

string Assignment::getTitle() const {

    return title;
}
Homework::Homework(string name, int totalPoints) : Assignment(name, totalPoints) {

    weight = 50;

}

Quiz::Quiz(string name, int totalPoints) : Assignment(name, totalPoints) {

   weight = 20;

}

Exam::Exam(string name, int totalPoints) : Assignment(name, totalPoints) {

    weight = 30;

}
