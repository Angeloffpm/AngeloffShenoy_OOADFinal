
#ifndef ASSIGNMENTFACTORY_H
#define ASSIGNMENTFACTORY_H

#include "assignment.h"

/*
 * Assignment Factory
 * uses Factory pattern
 * creates Assignment objects
*/

class AssignmentFactory
{

    public:
        AssignmentFactory();
        Homework* createHomework(string name);
        Quiz* createQuiz(string name);
        Exam* createExam(string name);


};

#endif // ASSIGNMENTFACTORY_H
