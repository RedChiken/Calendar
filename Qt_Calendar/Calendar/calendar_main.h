#ifndef CALENDAR_MAIN_H
#define CALENDAR_MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include "editplan.h"
#include "showplan.h"

namespace Ui {
class Calendar_main;
}

class Calendar_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar_main(QWidget *parent = 0);
    ~Calendar_main();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Calendar_main *ui;
    EditPlan *m_editPlanForm;
    ShowPlan *m_showPlanForm;
};

#endif // CALENDAR_MAIN_H
