#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    submitReady = false;
    hideLogin();
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
        if (ui->studentRadio->isChecked()) {
            return;
        } else {
            return;
        }
    } else {
        showLogin();
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
}

void MainWindow::showLogin()
{
    ui->Title->setGeometry(375, 0, 850, 180);
    ui->SignInButton->setGeometry(725, 800, 150, 75);
    ui->studentRadio->show();
    ui->teacherRadio->show();
    ui->usernameLabel->show();
    ui->usernameBox->show();
    ui->passwordLabel->show();
    ui->passwordBox->show();
}
