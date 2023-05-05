#ifndef STUDENTCOURSEVIEWWINDOW_H
#define STUDENTCOURSEVIEWWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "course.h"
#include "assignment.h"
#include "gradestablemodel.h"
namespace Ui {
class studentcourseviewwindow;
}

class studentcourseviewwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentcourseviewwindow(QWidget *parent = nullptr, Course* course_ = nullptr);
    ~studentcourseviewwindow();

private slots:
    void on_newAssignmentButton_clicked();

private:
    Course* course;
    Ui::studentcourseviewwindow *ui;
    vector<QFrame*> assignmentFrames;

    void drawAssignment(Assignment *a, int x, int y);
    void updateAssignmentList();
};

#endif // STUDENTCOURSEVIEWWINDOW_H
