/*
******** Yumeyo's ARMY KNIFE（NetInfoChecker Qt Edition） ********
******** 2025© Ne0W0r1d
******** 2024-2025© Yumeyo
******** LGPL 2.1 License
******** This file about aboutinterface ********
*/


#include "about.h"
#include "ui_about.h"


about::about(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::about)
{
    setFixedSize(400,300);
    ui->setupUi(this);

    QString systemname = QSysInfo::kernelType();
    QString systemver = QSysInfo::productVersion();
    ui->env->setText(systemname);
    ui->sys->setText(systemver);
}

about::~about()
{
    delete ui;
}
