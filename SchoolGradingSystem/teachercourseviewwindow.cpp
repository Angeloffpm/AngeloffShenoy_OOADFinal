#include "teachercourseviewwindow.h"
#include "qdialog.h"
#include "QTableView"
#include "ui_teachercourseviewwindow.h"

teacherCourseViewWindow::teacherCourseViewWindow(QWidget *parent, Course* course_) :
    QMainWindow(parent),
    course(course_),
    ui(new Ui::teacherCourseViewWindow)
{
    ui->setupUi(this);
    int i = 0;
    for (auto assignment : course->getAllAssignments())
    {
        drawAssignment(assignment, 20, 150+i);
        i += 110;
    }
}

teacherCourseViewWindow::~teacherCourseViewWindow()
{
    delete ui;
}

// helper function for drawing a frame for an Assignment
void teacherCourseViewWindow::drawAssignment(Assignment *a, int x, int y)
{
    // create frame
    QFrame* aFrame = new QFrame(this);
    aFrame->setFrameStyle(QFrame::Box | QFrame::Plain);
    aFrame->setGeometry(x, y, 760, 100);
    // create label
    QLabel* assignmentLabel = new QLabel(QString::fromStdString(a->getTitle()), aFrame);
    assignmentLabel->setGeometry(10, 10, 200, 80);
    assignmentLabel->setFont(QFont("Arial", 16));

    // create view grades button
    QPushButton* viewGradesButton = new QPushButton("View Grades", aFrame);
    viewGradesButton->setGeometry(600,30,100,30);
    // connect button signal to slot
    connect(viewGradesButton, &QPushButton::clicked, this, [=]() {
        // create dialog
        QDialog* dialog = new QDialog(this);
        dialog->setWindowTitle(QString::fromStdString(a->getTitle() + " Grades"));
        dialog->setGeometry(100, 100, 400, 400);

        // add contents to dialog
        QLabel* gradesLabel = new QLabel("Grades for " + QString::fromStdString(a->getTitle()), dialog);
        gradesLabel->setGeometry(10, 10, 200, 40);
        QTableView* tableView = new QTableView(dialog);
        tableView->setGeometry(10, 50, 380, 340);

        // show dialog
        dialog->exec();

        // clean up
        delete dialog;
    });
}
