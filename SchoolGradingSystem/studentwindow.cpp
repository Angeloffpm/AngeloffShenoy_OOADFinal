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

void StudentWindow::openCourseGrades(Course c) {
    QDialog* courseGradesWindow = new QDialog(this);
    courseGradesWindow->setWindowTitle("Course Grades");

    QSize currentSize = this->size();
    courseGradesWindow->setFixedSize(currentSize);

    vector<Assignment> a1 = {Exam("Exam 1"), Homework("Homework 1"), Homework("Homework 2")};
    vector<Course> x = {Course("Calculus 1", 1000), Course("Calculus 2", 1100), Course("Calculus 3", 1200)};
    Student* d = new Student(157235, x, 3.4, "password123", "James Green");
    a1[0].inputScore(d, 82);
    a1[1].inputScore(d, 96);
    a1[2].inputScore(d, 100);

    c.addAssignment(d, &a1[0]);
    c.addAssignment(d, &a1[1]);
    c.addAssignment(d, &a1[2]);

    c.printGradesHelper(courseGradesWindow);

    // Display the window
    courseGradesWindow->exec();
}

void StudentWindow::showCourses() {

    for (int i = 0; i < courses.size(); i++) {
        QPushButton* x = new QPushButton("Course: " + QString::fromStdString(courses[i].getClassName()), this);
        x->setGeometry(30,60+(100*(i)),320,60);
        // Set the font size to 28pt
        QFont font = x->font();
        font.setPointSize(28);
        x->setFont(font);
        connect(x, &QPushButton::clicked, [this, i]() {
            openCourseGrades(courses[i]);
        });
    }
}



