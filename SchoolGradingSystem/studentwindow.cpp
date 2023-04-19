#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::getCourses(vector<Course> c) {

    courses = c;
}

void StudentWindow::showCourses() {

    for (int i = 0; i < courses.size(); i++) {
        QPushButton* x = new QPushButton("Course: " + QString::fromStdString(courses[i].getClassName()), this);
        x->setGeometry(30,60+(100*(i)),320,60);
        // Set the font size to 28pt
        QFont font = x->font();
        font.setPointSize(28);
        x->setFont(font);
    }
}

