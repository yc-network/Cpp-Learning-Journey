#ifndef DELSTU_H
#define DELSTU_H

#include <QWidget>

class TeacherWindow;

namespace Ui {
class DelStu;
}

class DelStu : public QWidget
{
    Q_OBJECT

public:
    explicit DelStu(TeacherWindow* teacher,QWidget *parent = nullptr);
    ~DelStu();

private:
    Ui::DelStu *ui;
    TeacherWindow *teacherWindow;
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_pushButton_clicked();
};

#endif // DELSTU_H
