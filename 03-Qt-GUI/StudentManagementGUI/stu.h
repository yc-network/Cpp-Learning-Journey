#ifndef STU_H
#define STU_H

#include <QWidget>

class ChanStu;
class Student;
class StudentManager;

namespace Ui {
class Stu;
}

class Stu : public QWidget
{
    Q_OBJECT

public:
    explicit Stu(Student *student,StudentManager *manager,ChanStu *c,QWidget *parent = nullptr);
    ~Stu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Stu *ui;
    ChanStu *change;
    Student *student;
    StudentManager *manager;
protected:
    void closeEvent(QCloseEvent* event) override;
};

#endif // STU_H
