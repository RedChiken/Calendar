#ifndef SHOWPLAN_H
#define SHOWPLAN_H

#include <QWidget>
#include "ScheduleManager.h"

namespace Ui {
class ShowPlan;
}

class ShowPlan : public QWidget
{
    Q_OBJECT

public:
    TimeManager date;
    void setData(QDate date);
    explicit ShowPlan(QWidget *parent = 0);
    ~ShowPlan();

private:
    Ui::ShowPlan *ui;
};

#endif // SHOWPLAN_H
