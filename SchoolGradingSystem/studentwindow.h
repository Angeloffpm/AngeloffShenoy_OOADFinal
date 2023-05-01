#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "course.h"
#include "datatest.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include <QTimer>



namespace Ui {
class StudentWindow;
}
class DataTest;
class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void showMenu();
    void setCourses(vector<Course*> c);
    void openCourseGrades(Course* s);
    void addClassDialog();
    void updateMenu();


private:
    Ui::StudentWindow *ui;
    vector<Course*> courses;
    vector<Student*> students;
    QPushButton* addNewClass;
    QDialog* courseGradesWindow;
    QDialog* menu;
    DataTest* ds;

};

#endif // STUDENTWINDOW_H
