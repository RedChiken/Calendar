#include "calendar_main.h"
#include "ui_calendar_main.h"
Calendar_main::Calendar_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calendar_main)
{
    ui->setupUi(this);
  //  m_editPlanForm = new EditPlan();
  //  connect((ui->EditPlanButton), &QPushButton::released,[&]{
   //     m_editPlanForm->show();
   // });
}

Calendar_main::~Calendar_main()
{
    delete m_editPlanForm;
    delete ui;
}

void Calendar_main::on_calendarWidget_clicked(const QDate &date)
{
    m_editPlanForm = new EditPlan();
    m_editPlanForm->setdata(date);
    m_editPlanForm->show();
    m_showPlanForm = new ShowPlan();
    m_showPlanForm->setData(date);
    m_showPlanForm->show();
}
