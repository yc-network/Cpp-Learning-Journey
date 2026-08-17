#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QWidget>

namespace Ui {
class StudentData;
}

class StudentData : public QWidget
{
    Q_OBJECT

public:
    explicit StudentData(QWidget *parent = nullptr);
    ~StudentData();

private:
    Ui::StudentData *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // STUDENTDATA_H
