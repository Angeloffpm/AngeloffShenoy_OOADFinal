#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teacherwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    submitReady = false;
    hideLogin();
    this->data = new DataTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * First sign in will open the sign in form,
 * second will submit the form data
*/
void MainWindow::on_SignInButton_clicked()
{
    if (submitReady) {
        if (ui->studentRadio->isChecked()) { // If student selected
            return;
        } else if (ui->teacherRadio->isChecked()) { // If teacher selected
            Teacher* userTeacher = verifyTeacherLogin(ui->usernameBox->text().toStdString(), ui->passwordBox->text().toStdString());
            if (userTeacher != nullptr)
            {
                TeacherWindow *tw = new TeacherWindow(nullptr, userTeacher);
                tw->show();
                this->hide();
            }
            else qDebug() << "Username or password incorrect.";
        }
    } else {
        showLogin();
        submitReady = true;
    }
}

void MainWindow::hideLogin()
{
    ui->studentRadio->hide();
    ui->teacherRadio->hide();
    ui->usernameLabel->hide();
    ui->usernameBox->hide();
    ui->passwordLabel->hide();
    ui->passwordBox->hide();
    ui->confirmButton->hide();
}

void MainWindow::showLogin()
{
    ui->Title->setGeometry(375, 0, 850, 180);
    ui->SignInButton->setGeometry(725, 700, 150, 75);
    ui->studentRadio->show();
    ui->teacherRadio->show();
    ui->usernameLabel->show();
    ui->usernameBox->show();
    ui->passwordLabel->show();
    ui->passwordBox->show();
    ui->confirmButton->show();
}

void MainWindow::on_confirmButton_clicked()
{
    if (ui->studentRadio->isChecked()) {
        for (Student* s: data->getStudents()) {
            if (to_string(s->getUserID()) == ui->usernameBox->text().toStdString() && s->getPassword() == ui->passwordBox->text().toStdString()) {
                studentwindow = new StudentWindow;
                studentwindow->hide();
                close();
                vector<Course*> c = data->getCourses();
                studentwindow->setCourses(c);
                studentwindow->showMenu();
                studentwindow->show();
            }
        }
    }
}

Teacher* MainWindow::verifyTeacherLogin(string user_, string pass_)
{
    Teacher* target = data->findTeacherUser(user_);
    if (target != nullptr)
    {
        if (target->verifyPassword(pass_)) return target;
        else return nullptr;
    }
    return nullptr;
}

