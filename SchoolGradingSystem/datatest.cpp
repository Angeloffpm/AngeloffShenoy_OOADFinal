
#include "datatest.h"

DataTest::DataTest()
{
    this->teachers.push_back(new Teacher("John Doe", "jdoe", "test123"));
    this->teachers.push_back(new Teacher("Jeff Hoefs", "jhoefs", "hoefs123"));
}

Teacher* DataTest::findTeacherUser(string user_) {
    for (auto t : this->teachers)
    {
        if (t->getUsername() == user_) return t;
    }
    return nullptr;
}
