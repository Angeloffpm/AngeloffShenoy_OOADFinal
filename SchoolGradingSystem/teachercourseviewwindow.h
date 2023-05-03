#ifndef TEACHERCOURSEVIEWWINDOW_H
#define TEACHERCOURSEVIEWWINDOW_H

#include <QMainWindow>
#include "course.h"
#include "assignment.h"

namespace Ui {
class teacherCourseViewWindow;
}

class teacherCourseViewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacherCourseViewWindow(QWidget *parent = nullptr, Course* course_ = nullptr);
    ~teacherCourseViewWindow();

private:
    Course* course;
    Ui::teacherCourseViewWindow *ui;

    void drawAssignment(Assignment *a, int x, int y);
};

#endif // TEACHERCOURSEVIEWWINDOW_H
