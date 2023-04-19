#ifndef STUDENT_H
#define STUDENT_H
#include <QMainWindow>
#include <vector>
using namespace std;


struct Assignment {

    string name;
    int score;

};

class Class;
namespace Ui {
class Student;
}

class Student : public QMainWindow
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    Student(int studentID_, vector<Class> classes_, double gpa_, string password_, string name_);
    ~Student();
    void addClass(Class c);
    void removeClass(Class c);
    vector<Class> getClasses();
    int getGrade(Class c);
    bool verifyLogin(string id, string pass);
    int getUserID();
    string getPassword();

    void exit();

private:
    Ui::Student *ui;
    int studentID;
    vector<Class> classes;
    double gpa;
    string password;
    string name;



};

#endif // STUDENT_H
