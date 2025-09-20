#include "home.h"
//#include "about.h"
#include "ui_home.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QNetworkAccessManager>

home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
    setFixedSize(this->width(),this->height()); //固定大小
    // 菜单栏：帮助
    //connect(ui -> about, &QAction::triggered, this, &home::onAction_about_triggered); // 连接UI：关于和关于槽
    connect(ui -> wiki, &QAction::triggered, this, &home::on_wiki_triggered); // 连接UI：WIKI和WIKI槽
    connect(ui -> CNB, &QAction::triggered, this, &home::on_cnb_triggered);// 连接UI：CNB GIT和CNB GIT槽
    connect(ui -> Github, &QAction::triggered, this, &home::onAction_github_triggered);// 连接UI：Github和Github槽
    //connect(ui -> about, &QAction::triggered, this, &home::onAction_about_triggered); // 连接UI：关于和
    connect(ui -> wiki, &QAction::triggered, this, &home::on_wiki_triggered); // 连接UI：WIKI
    connect(ui -> CNB, &QAction::triggered, this, &home::on_cnb_triggered);// 连接UI：CNB
    connect(ui -> Github, &QAction::triggered, this, &home::onAction_github_triggered);// 连接UI：Github
    connect(ui -> updatelog, &QAction::triggered, this, &home::onAction_updatelog_triggered);//连接UI：更新日志
}

home::~home()
{
    delete ui;
}





// 菜单栏业务相关定义
    //打开Wiki/文档页
void home::on_wiki_triggered(){
    QUrl wikiurl("https://ak.ne0w0r1d.top");
    QDesktopServices::openUrl(wikiurl);
}
    //打开CNB
void home::on_cnb_triggered(){
    QUrl cnb_repo("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(cnb_repo);
}
    //打开github
void home::onAction_github_triggered(){
    QUrl wikiurl("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(wikiurl);
}
    //打开关于窗口
/*void home::onAction_about_triggered(){
    about *aboutDialog = new about(this);
    aboutDialog->setAttribute(Qt::WA_DeleteOnClose);
    aboutDialog->exec();
}*/
//打开更新日志
void home::onAction_updatelog_triggered(){
    QUrl updateurl("https://ak.ne0w0r1d.top/?id=更新日志");
    QDesktopServices::openUrl(updateurl);
}
