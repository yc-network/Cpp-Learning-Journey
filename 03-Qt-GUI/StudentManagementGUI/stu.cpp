#include "stu.h"
#include "ui_stu.h"
#include "chanstu.h"
#include "Student.h"
#include "StudentManager.h"
#include <QMessageBox>
#include <QCloseEvent>

Stu::Stu(Student *s,StudentManager *m,ChanStu *c,QWidget *parent)
    : student(s),manager(m),change(c),QWidget(parent)
    , ui(new Ui::Stu)
{
    ui->setupUi(this);
    ui->InputeName->setText(QString::fromStdString(student->getName()));
    ui->InputeAge->setText(QString::number(student->getAge()));
    ui->InputeId->setText(QString::fromStdString(student->getid()));
    ui->InputeId->setReadOnly(true);
    ui->comboBox->setCurrentText(
        QString::fromStdString(student->getSex())
        );
    ui->InputeM->setText(QString::number(student->getMScores()));
    ui->InputeE->setText(QString::number(student->getEScores()));
    ui->InputeC->setText(QString::number(student->getCScores()));
}

Stu::~Stu()
{
    delete ui;
}

void Stu::on_pushButton_2_clicked()
{
    auto answer = QMessageBox::question(this,"提示","确定要返回选择页面吗",QMessageBox::Yes|QMessageBox::No);
    if(answer!=QMessageBox::Yes){
        return;
    }
    change->show();
    deleteLater();
}

void Stu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}
void Stu::on_pushButton_clicked()
{
    std::fstream file;
    QString qname=ui->InputeName->text().trimmed();
    QString qsex=ui->comboBox->currentText();
    bool ageok,Mok,Cok,Eok;
    int age=ui->InputeAge->text().toInt(&ageok);
    double M=ui->InputeM->text().toDouble(&Mok);
    double C=ui->InputeC->text().toDouble(&Cok);
    double E=ui->InputeE->text().toDouble(&Eok);
    if(qname.isEmpty()){
        QMessageBox::warning(this,"警告","姓名不能为空！");
        return;
    }
    if(!ageok||!Mok||!Cok||!Eok){
        QMessageBox::warning(this,"警告","年龄、成绩必须为数字！");
        return;
    }
    student->setName(qname.toStdString());
    student->setSex(qsex.toStdString());
    student->setAge(age);
    student->setMScore(M);
    student->setCScore(C);
    student->setEScore(E);
    manager->save(file);
    QMessageBox::information(this,"提示","修改成功！");
    change->show();
    deleteLater();
}

