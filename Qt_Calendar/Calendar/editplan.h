#ifndef EDITPLAN_H
#define EDITPLAN_H

#include <QWidget>
#include <QDateTime>
namespace Ui {
class EditPlan;
}

class EditPlan : public QWidget
{
    Q_OBJECT
public:
    typedef struct TempPlanData{
        QString title;
        QDateTime startTime;
        QDateTime endTime;
        QString details;
    };
    void setdata(QDate d);
    void EditPlan::convert2lunar(QDate d);
    explicit EditPlan(QWidget *parent = 0);
    ~EditPlan();
private slots:
    void on_checkBox_clicked();

    void on_checkBox_clicked(bool checked);


private:
    void checkDateError();
    Ui::EditPlan *ui;
    TempPlanData data;
};

#endif // EDITPLAN_H
