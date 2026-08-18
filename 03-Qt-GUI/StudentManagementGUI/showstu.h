#ifndef SHOWSTU_H
#define SHOWSTU_H

#include <QWidget>

class StudentManager;
class TeacherWindow;
class Student;

namespace Ui {
class ShowStu;
}

class ShowStu : public QWidget
{
    Q_OBJECT

public:
    explicit ShowStu(StudentManager* m, TeacherWindow* t,
                     QWidget* parent = nullptr);
    ~ShowStu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ShowStu* ui;
    StudentManager* manager;
    TeacherWindow* teacherwindow;

    void refreshTable();
    void fillStudentRow(int row, const Student& student);
    void updateTableHeight(int rowCount);

protected:
    void closeEvent(QCloseEvent* event) override;
};

#endif // SHOWSTU_H
