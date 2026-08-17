#include "addstu.h"
#include "ui_addstu.h"
#include "teacherwindow.h"
#include "Student.h"
#include "StudentManager.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <fstream>

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
    std::fstream file;
    QString qname=ui->InputeName->text().trimmed();
    QString qsex=ui->comboBox->currentText();
    QString qid=ui->InputeId->text().trimmed();
    bool ageok,Mok,Cok,Eok;
    int age=ui->InputeAge->text().toInt(&ageok);
    double M=ui->InputeM->text().toDouble(&Mok);
    double C=ui->InputeC->text().toDouble(&Cok);
    double E=ui->InputeE->text().toDouble(&Eok);
    if(qname.isEmpty()||qid.isEmpty()){
        QMessageBox::warning(this,"警告","姓名和学号不能为空！");
        ui->InputeName->clear();
        ui->InputeId->clear();
        ui->InputeAge->clear();
        ui->InputeM->clear();
        ui->InputeC->clear();
        ui->InputeE->clear();
        ui->comboBox->setCurrentIndex(0);
        return;
    }
    if(!ageok||!Mok||!Cok||!Eok){
        QMessageBox::warning(this,"警告","年龄、成绩必须为数字！");
        ui->InputeName->clear();
        ui->InputeId->clear();
        ui->InputeAge->clear();
        ui->InputeM->clear();
        ui->InputeC->clear();
        ui->InputeE->clear();
        ui->comboBox->setCurrentIndex(0);
        return;
    }
    auto name=qname.toStdString();
    auto sex=qsex.toStdString();
    auto id=qid.toStdString();
    if(manager->checkid(id)){
        QMessageBox::warning(this,"警告","该学生已存在 请检查学号是否正确");
        ui->InputeName->clear();
        ui->InputeId->clear();
        ui->InputeAge->clear();
        ui->InputeM->clear();
        ui->InputeC->clear();
        ui->InputeE->clear();
        ui->comboBox->setCurrentIndex(0);
        return;
    }
    Student s(name,id,sex,age,M,C,E);
    manager->AddStudent(s);
    manager->save(file);
    ui->InputeName->clear();
    ui->InputeId->clear();
    ui->InputeAge->clear();
    ui->InputeM->clear();
    ui->InputeC->clear();
    ui->InputeE->clear();
    ui->comboBox->setCurrentIndex(0);
    QMessageBox::information(this,"提示","添加成功！");
}

