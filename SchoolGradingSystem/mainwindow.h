#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "course.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SignInButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::MainWindow *ui;
    bool submitReady;
    void hideLogin();
    void showLogin();
    vector<Course> c = {Course("Math", 123)};
    vector<Student> students = {Student(12345, c, 3.4, "pass", "james")};
    Student s = students[0];




};
#endif // MAINWINDOW_H
