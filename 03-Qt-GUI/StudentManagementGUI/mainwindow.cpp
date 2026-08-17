#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teacherwindow.h"
#include "studentwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->InputPasswords->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}

void MainWindow::on_Ensure_clicked()
{
    QString role=ui->comboBox->currentText();
    if(role=="老师"){
        QString Tacc=ui->InputAccount->text();
        QString Tpass=ui->InputPasswords->text();
        if(Tacc=="1" && Tpass=="1"){
            TeacherWindow* teacher=new TeacherWindow();
            teacher->show();
            this->hide();
        }
        else{
            QMessageBox::warning(this,"警告","密码或账号错误 请重新输入！");
        }
    }
    else{
        QString Sacc=ui->InputAccount->text();
        QString Spass=ui->InputPasswords->text();
        if(Sacc=="1" && Spass=="1"){
            StudentWindow* student=new StudentWindow();
            student->show();
            this->hide();
        }
        else{
            QMessageBox::warning(this,"警告","密码或账号错误 请重新输入！");
        }
    }
}


void MainWindow::on_pushButton_pressed()
{
    ui->InputPasswords->setEchoMode(QLineEdit::Normal);
}


void MainWindow::on_pushButton_released()
{
    ui->InputPasswords->setEchoMode(QLineEdit::Password);
}

