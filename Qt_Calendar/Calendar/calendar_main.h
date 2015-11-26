#ifndef CALENDAR_MAIN_H
#define CALENDAR_MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include "editplan.h"
namespace Ui {
class Calendar_main;
}

class Calendar_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar_main(QWidget *parent = 0);
    ~Calendar_main();

private:
    Ui::Calendar_main *ui;
    EditPlan *m_editPlanForm;
};

#endif // CALENDAR_MAIN_H
