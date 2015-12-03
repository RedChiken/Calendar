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

    explicit EditPlan(QWidget *parent = 0);
    ~EditPlan();
private:
    void checkDateError();
    Ui::EditPlan *ui;
    TempPlanData data;
};

#endif // EDITPLAN_H
