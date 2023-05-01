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

void StudentWindow::setCourses(vector<Course*> c) {

    courses = c;
}

void StudentWindow::openCourseGrades(Course* c) {
    courseGradesWindow = new QDialog(this);
    courseGradesWindow->setWindowTitle("Course Grades");

    QSize currentSize = this->size();
    courseGradesWindow->setFixedSize(currentSize);

    vector<Assignment> a1 = {Exam("Exam 1"), Homework("Homework 1"), Homework("Homework 2")};

    vector<Student*> s = {new Student(157235, courses, 3.4, "password123", "James Green"), new Student(237165, courses, 3.7, "jamesgreensux", "Rachel Green")};
    a1[0].inputScore(s[0], 82);
    a1[1].inputScore(s[0], 96);
    a1[2].inputScore(s[0], 100);

    c->addAssignment(s[0], &a1[0]);
    c->addAssignment(s[0], &a1[1]);
    c->addAssignment(s[0], &a1[2]);

    c->printGradesHelper(courseGradesWindow);

    // Display the window
    courseGradesWindow->exec();
}

void StudentWindow::showMenu() {

    menu = new QDialog(this);

    int temp;
    for (int i = 0; i < courses.size(); i++) {
        QPushButton* x = new QPushButton("Course: " + QString::fromStdString(courses[i]->getClassName()), this);
        x->setGeometry(30,60+(100*(i)),320,60);
        // Set the font size to 28pt
        QFont font = x->font();
        font.setPointSize(18);
        x->setFont(font);
        connect(x, &QPushButton::clicked, [this, i]() {
            openCourseGrades(courses[i]);
        });
        temp = i;
    }

    addNewClass = new QPushButton("Add a course", this);
    addNewClass->setGeometry(30,60+(100*(temp+1)),320,60);
    QFont font = addNewClass->font();
    font.setPointSize(18);
    addNewClass->setFont(font);
    connect(addNewClass, &QPushButton::clicked, this, &StudentWindow::addClassDialog);

}

void StudentWindow::addClassDialog() {
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Add a course");
    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QLabel* label = new QLabel("Enter the course name:", dialog);
    layout->addWidget(label);

    QLineEdit* courseName = new QLineEdit(dialog);
    layout->addWidget(courseName);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, dialog);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, [this, courseName]() {
        // Get the course name from the text field
        QString name = courseName->text();
        // Create a new course object and add it to the list of courses
        Course* course = new Course(name.toStdString(), 1300);
        courses.push_back(course);
        ds->addCourse(course);
        // Refresh the menu to display the new course
        menu = nullptr;
        showMenu();
    });

    dialog->exec();
}





