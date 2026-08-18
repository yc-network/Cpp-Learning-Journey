#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StudentManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_Ensure_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    StudentManager manager;

protected:
    void closeEvent(QCloseEvent* event) override;
};
#endif // MAINWINDOW_H
