#ifndef CHANSTU_H
#define CHANSTU_H

#include <QWidget>

class TeacherWindow;
class StudentManager;
class Student;

namespace Ui {
class ChanStu;
}

class ChanStu : public QWidget
{
    Q_OBJECT

public:
    explicit ChanStu(StudentManager* m,TeacherWindow *t,QWidget *parent = nullptr);
    ~ChanStu();

private:
    Ui::ChanStu *ui;
    TeacherWindow* teacherWindow;
    StudentManager* manager;
    Student* student;
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_return_2_clicked();
    void on_Ensure_clicked();
};

#endif // CHANSTU_H
