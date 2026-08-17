#include "addstu.h"
#include "ui_addstu.h"
#include "teacherwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

AddStu::AddStu(StudentManager* m, TeacherWindow* teacher,
               QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AddStu)
    , manager(m)
    , teacherWindow(teacher)
{
    ui->setupUi(this);
}

AddStu::~AddStu()
{
    delete ui;
}


void AddStu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}
void AddStu::on_return_2_clicked()
{
    auto answer = QMessageBox::question(
        this,
        "返回",
        "确定要返回教师页面吗？",
        QMessageBox::Yes | QMessageBox::No
        );

    if (answer != QMessageBox::Yes) {
        return;
    }

    teacherWindow->show();
    deleteLater();
}


void AddStu::on_Ensure_clicked()
{
    QString name=ui->InputeName->text();
     QMessageBox::information(this, "提示", "name");
}

