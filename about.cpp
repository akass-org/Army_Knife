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
