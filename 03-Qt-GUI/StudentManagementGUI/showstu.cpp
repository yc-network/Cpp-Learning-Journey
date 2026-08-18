#include "showstu.h"
#include "teacherwindow.h"
#include "ui_showstu.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QHeaderView>
#include "StudentManager.h"
#include "Student.h"
#include <QAbstractItemView>
#include <QTableWidgetItem>
#include <algorithm>

namespace {
constexpr int kMaxVisibleRows = 10;
}

ShowStu::ShowStu(StudentManager* m, TeacherWindow* t, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ShowStu)
    , manager(m)
    , teacherwindow(t)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    refreshTable();
}

ShowStu::~ShowStu()
{
    delete ui;
}


void ShowStu::closeEvent(QCloseEvent *event){
    auto out=QMessageBox::question(this,"","确认要退出吗");
    if(out == QMessageBox::Yes){
        event->accept();
    }
    else{
        event->ignore();
    }
}

void ShowStu::fillStudentRow(int row, const Student& student)
{
    ui->tableWidget->setItem(
        row, 0,
        new QTableWidgetItem(QString::fromStdString(student.getid()))
        );

    ui->tableWidget->setItem(
        row, 1,
        new QTableWidgetItem(QString::fromStdString(student.getName()))
        );

    ui->tableWidget->setItem(
        row, 2,
        new QTableWidgetItem(QString::fromStdString(student.getSex()))
        );

    ui->tableWidget->setItem(
        row, 3,
        new QTableWidgetItem(QString::number(student.getAge()))
        );

    ui->tableWidget->setItem(
        row, 4,
        new QTableWidgetItem(QString::number(student.getMScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 5,
        new QTableWidgetItem(QString::number(student.getCScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 6,
        new QTableWidgetItem(QString::number(student.getEScores(), 'f', 2))
        );

    ui->tableWidget->setItem(
        row, 7,
        new QTableWidgetItem(QString::number(student.getAverage(), 'f', 2))
    );
}

void ShowStu::updateTableHeight(int rowCount)
{
    const int visibleRows = std::min(rowCount, kMaxVisibleRows);
    const int headerHeight = ui->tableWidget->horizontalHeader()->sizeHint().height();
    const int rowHeight = ui->tableWidget->verticalHeader()->defaultSectionSize();
    const int frameHeight = ui->tableWidget->frameWidth() * 2;

    ui->tableWidget->setFixedHeight(
        headerHeight + visibleRows * rowHeight + frameHeight
    );
}

void ShowStu::refreshTable()
{
    if (manager == nullptr) {
        return;
    }

    const auto& students = manager->getStudents();

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(static_cast<int>(students.size()));
    updateTableHeight(static_cast<int>(students.size()));

    for (int row = 0; row < static_cast<int>(students.size()); ++row) {
        fillStudentRow(row, students[row]);
    }
}

void ShowStu::on_pushButton_clicked()
{
    if (manager == nullptr) {
        QMessageBox::warning(this, "错误", "学生数据不可用！");
        return;
    }

    const QString qid = ui->Inputid->text().trimmed();

    // 输入框为空时，恢复显示全部学生。
    if (qid.isEmpty()) {
        refreshTable();
        return;
    }

    const Student* student = manager->findStudent(qid.toStdString());

    if (student == nullptr) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        updateTableHeight(0);
        QMessageBox::information(this, "提示", "未找到该学生！");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(1);
    updateTableHeight(1);
    fillStudentRow(0, *student);
}

void ShowStu::on_pushButton_2_clicked()
{
    auto answer = QMessageBox::question(this,"提示","确定要返回教师页面吗",QMessageBox::Yes|QMessageBox::No);
    if(answer!=QMessageBox::Yes){
        return;
    }
    teacherwindow->show();
    deleteLater();
}

