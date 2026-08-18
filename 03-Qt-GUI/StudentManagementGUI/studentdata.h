#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QWidget>

class StudentWindow;
class Student;

namespace Ui {
class StudentData;
}

class StudentData : public QWidget
{
    Q_OBJECT

public:
    explicit StudentData(Student* student, StudentWindow *studentwindow,
                         QWidget *parent = nullptr);
    ~StudentData();

private:
    Ui::StudentData *ui;
    Student* student;
    StudentWindow *studentwindow;

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void fillStudentRow(int row, const Student& student);
private slots:
    void on_pushButton_2_clicked();
};

#endif // STUDENTDATA_H
