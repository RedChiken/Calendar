#ifndef EDITPLAN_H
#define EDITPLAN_H

#include <QWidget>

namespace Ui {
class EditPlan;
}

class EditPlan : public QWidget
{
    Q_OBJECT

public:
    explicit EditPlan(QWidget *parent = 0);
    ~EditPlan();

private:
    Ui::EditPlan *ui;
};

#endif // EDITPLAN_H
