#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QWidget>
#include "StudentManager.h"

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);
    ~TeacherWindow();

private:
    Ui::TeacherWindow *ui;
    StudentManager manager;

protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_Addstu_clicked();
    void on_Delstu_clicked();
    void on_Showstu_clicked();
    void on_Chanstu_clicked();
};

#endif // TEACHERWINDOW_H
