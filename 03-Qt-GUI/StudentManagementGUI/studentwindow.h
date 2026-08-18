#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>

class StudentManager;

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWindow(StudentManager *m,QWidget *parent = nullptr);
    ~StudentWindow();

private:
    Ui::StudentWindow *ui;
    StudentManager *manager;

protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_Ensure_clicked();
};

#endif // STUDENTWINDOW_H
