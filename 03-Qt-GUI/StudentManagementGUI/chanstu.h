#ifndef CHANSTU_H
#define CHANSTU_H

#include <QWidget>

class TeacherWindow;

namespace Ui {
class ChanStu;
}

class ChanStu : public QWidget
{
    Q_OBJECT

public:
    explicit ChanStu(TeacherWindow *t,QWidget *parent = nullptr);
    ~ChanStu();

private:
    Ui::ChanStu *ui;
    TeacherWindow* teacherWindow;
protected:
    void closeEvent(QCloseEvent* event) override;
private slots:
    void on_return_2_clicked();
};

#endif // CHANSTU_H
