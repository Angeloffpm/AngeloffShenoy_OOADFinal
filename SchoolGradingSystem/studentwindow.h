#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "course.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void showCourses();
    void getCourses(vector<Course> c);

private:
    Ui::StudentWindow *ui;
    vector<Course> courses;
    vector<Student> students;
};

#endif // STUDENTWINDOW_H
