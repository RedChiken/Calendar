#include "calendar_main.h"
#include "ui_calendar_main.h"
Calendar_main::Calendar_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calendar_main)
{
    ui->setupUi(this);
    m_editPlanForm = new EditPlan();
    connect((ui->EditPlanButton), &QPushButton::released,[&]{
        m_editPlanForm->show();
    });
}

Calendar_main::~Calendar_main()
{
    delete m_editPlanForm;
    delete ui;
}
