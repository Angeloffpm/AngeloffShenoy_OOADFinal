
#include "assignmentfactory.h"

AssignmentFactory::AssignmentFactory()
{

}

Homework* AssignmentFactory::createHomework(string name) {
    return new Homework(name, 100);
}

Exam* AssignmentFactory::createExam(string name) {
    return new Exam(name, 150);
}

Quiz* AssignmentFactory::createQuiz(string name) {
    return new Quiz(name, 20);
}
