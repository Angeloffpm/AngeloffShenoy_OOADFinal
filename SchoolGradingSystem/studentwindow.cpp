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

    vector<Assignment*> a1 = {new Exam("Exam 1"), new Homework("Homework 1"), new Homework("Homework 2")};

    vector<Student*> s = {new Student(157235, courses, 3.4, "password123", "James Green"), new Student(237165, courses, 3.7, "jamesgreensux", "Rachel Green")};
    a1[0]->inputScore(s[0], 82);
    a1[1]->inputScore(s[0], 96);
    a1[2]->inputScore(s[0], 100);

    c->addAssignment(s[0], a1[0]);
    c->addAssignment(s[0], a1[1]);
    c->addAssignment(s[0], a1[2]);

    c->printGradesHelper(courseGradesWindow);

    // Display the window
    courseGradesWindow->exec();
}

void StudentWindow::showMenu() {
    // Create a new QDialog object for the menu

    menuDialog = new QDialog(this);

    // Create a QVBoxLayout to hold the menu items
    QVBoxLayout* menuLayout = new QVBoxLayout;

    // Add menu items to the layout
//    int temp;
    for (int i = 0; i < courses.size(); i++) {
        QPushButton* x = new QPushButton("Course: " + QString::fromStdString(courses[i]->getClassName()), menuDialog);
        // ...
        menuLayout->addWidget(x);
    }

    addNewClass = new QPushButton("Add a course", menuDialog);
    removeNewClass = new QPushButton("Remove a course", menuDialog);
    // ...
    menuLayout->addWidget(addNewClass);
    menuLayout->addWidget(removeNewClass);

    // Connect the "Add a course" button to a lambda function that shows the "Add Class" dialog
    connect(addNewClass, &QPushButton::clicked, this, [=]() {
        addClassDialog();
    });

    connect(removeNewClass, &QPushButton::clicked, this, [=]() {
        removeClassDialog();
    });

    // Set the menu layout for the dialog
    menuDialog->setLayout(menuLayout);

    // Display the menu dialog
    menuDialog->exec();
}



void StudentWindow::addClassDialog() {
    // Create the dialog
    menuDialog->close();
    addCourseDialog = new QDialog(this);
    addCourseDialog->setWindowTitle("Add Class");

    // Create the label and line edit
    QLabel* label = new QLabel("Class Name:", addCourseDialog);
    QLineEdit* lineEdit = new QLineEdit(addCourseDialog);

    // Create the buttons
    QPushButton* confirmButton = new QPushButton("Confirm", addCourseDialog);
    QPushButton* cancelButton = new QPushButton("Cancel", addCourseDialog);

    // Add the buttons to the dialog
    QDialogButtonBox* buttonBox = new QDialogButtonBox(addCourseDialog);
    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    // Set the layout
    QGridLayout* layout = new QGridLayout(addCourseDialog);
    layout->addWidget(label, 0, 0);
    layout->addWidget(lineEdit, 0, 1);
    layout->addWidget(buttonBox, 1, 0, 1, 2);

    // Connect the confirm button to store the string
    connect(confirmButton, &QPushButton::clicked, addCourseDialog, [&]() {
        QString className = lineEdit->text();
        // Do something with the className, such as adding it to a list
        courses.push_back(new Course(className.toStdString(), 1300));
        addCourseDialog->close();
        showMenu();

    });

    // Show the dialog
    addCourseDialog->exec();

}

void StudentWindow::removeClassDialog() {

    menuDialog->close();
    removeCourseDialog = new QDialog(this);
    removeCourseDialog->setWindowTitle("Remove Class");
    QLabel* label = new QLabel("Class Name:", removeCourseDialog);
    QLineEdit* lineEdit = new QLineEdit(removeCourseDialog);

    // Create the buttons
    QPushButton* confirmButton = new QPushButton("Confirm", removeCourseDialog);
    QPushButton* cancelButton = new QPushButton("Cancel", removeCourseDialog);

    // Add the buttons to the dialog
    QDialogButtonBox* buttonBox = new QDialogButtonBox(removeCourseDialog);
    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    // Set the layout
    QGridLayout* layout = new QGridLayout(removeCourseDialog);
    layout->addWidget(label, 0, 0);
    layout->addWidget(lineEdit, 0, 1);
    layout->addWidget(buttonBox, 1, 0, 1, 2);

    // Connect the confirm button to store the string
    connect(confirmButton, &QPushButton::clicked, removeCourseDialog, [&]() {
        QString className = lineEdit->text();
        // Do something with the className, such as adding it to a list
        for (int i = 0; i < courses.size();i++) {

            if (courses[i]->getClassName() == className.toStdString()) {

                delete courses[i];
                courses[i] = nullptr;
                courses.erase(courses.begin() + i);
            }

        }


        removeCourseDialog->close();
        showMenu();

    });

    // Show the dialog
    removeCourseDialog->exec();






}






