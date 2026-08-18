#ifndef DELSTU_H
#define DELSTU_H

#include <QWidget>


class StudentManager;
class TeacherWindow;

namespace Ui {
class DelStu;
}

class DelStu : public QWidget
{
    Q_OBJECT

public:
    explicit DelStu(StudentManager* m,TeacherWindow* teacher,QWidget *parent = nullptr);
    ~DelStu();

private:
    Ui::DelStu *ui;
    TeacherWindow *teacherWindow;
    StudentManager* manager;
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_pushButton_clicked();
    void on_Ensure_clicked();
};

#endif // DELSTU_H
