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

    QString systemname = QSysInfo::kernelType();// 获取内核信息
    QString distro = QSysInfo::prettyProductName();// 获取发行版名称
    QString systemver = QSysInfo::productVersion();// 获取系统版本
    ui->softver_info->setText("0.3.anno.prototype.251001");//版本信息
    ui->env->setText(systemname + " (" + distro + ")");// 显示系统环境
    ui->sys->setText(systemver);// 显示系统版本
}

about::~about()
{
    delete ui;
}
