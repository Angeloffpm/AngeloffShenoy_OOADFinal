#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>
#include "teacher.h"

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr, Teacher *t = nullptr);
    ~TeacherWindow();

private:
    Ui::TeacherWindow *ui;
    Teacher *teacher;
};

#endif // TEACHERWINDOW_H
