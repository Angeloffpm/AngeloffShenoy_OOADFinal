#include "teacherwindow.h"
#include "ui_teacherwindow.h"

TeacherWindow::TeacherWindow(QWidget *parent, Teacher *t) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow),
    teacher(t)
{
    ui->setupUi(this);
    QString qstrName = QString::fromStdString(this->teacher->getName());
    ui->teacherName->setText(qstrName);
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}
