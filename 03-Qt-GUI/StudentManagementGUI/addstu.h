#ifndef ADDSTU_H
#define ADDSTU_H

#include <QWidget>
class StudentManager;
class TeacherWindow;

namespace Ui {
class AddStu;
}

class AddStu : public QWidget
{
    Q_OBJECT

public:
    explicit AddStu(StudentManager* m, TeacherWindow* teacherWindow,
                    QWidget *parent = nullptr);
    ~AddStu();

private:
    Ui::AddStu *ui;
    StudentManager* manager;
    TeacherWindow* teacherWindow;
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_return_2_clicked();
    void on_Ensure_clicked();
};

#endif // ADDSTU_H
