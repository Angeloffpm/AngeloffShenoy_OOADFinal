#ifndef TEACHERCOURSEVIEWWINDOW_H
#define TEACHERCOURSEVIEWWINDOW_H

#include <QMainWindow>
#include "course.h"
#include "assignment.h"
#include "gradestablemodel.h"

namespace Ui {
class teacherCourseViewWindow;
}

class teacherCourseViewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacherCourseViewWindow(QWidget *parent = nullptr, Course* course_ = nullptr);
    ~teacherCourseViewWindow();

private slots:
    void on_newAssignmentButton_clicked();

private:
    Course* course;
    Ui::teacherCourseViewWindow *ui;
    vector<QFrame*> assignmentFrames;

    void drawAssignment(Assignment *a, int x, int y);
    void updateAssignmentList();
};

#endif // TEACHERCOURSEVIEWWINDOW_H
