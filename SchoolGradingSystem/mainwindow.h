#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "course.h"
#include "studentwindow.h"

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
    StudentWindow* studentwindow;
    bool submitReady;
    void hideLogin();
    void showLogin();
    vector<Course> c = {Course("Calculus 1", 1000), Course("Calculus 2", 1100), Course("Calculus 3", 1200)};
    vector<Student> students = {Student(157235, c, 3.4, "password123", "James Green"), Student(149484, c, 3.4, "iloveschool", "Jair Galindo Flores"), Student(174938, c, 3.4, "outofcountrystudent123", "Rayner Susanto")};





};
#endif // MAINWINDOW_H
