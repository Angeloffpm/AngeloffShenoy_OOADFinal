#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "student.h"
#include "course.h"
#include <QMainWindow>

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
    Student x;


};
#endif // MAINWINDOW_H
