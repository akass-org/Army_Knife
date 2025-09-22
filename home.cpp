#include "home.h"
#include "about.h"
#include "ui_home.h"


home::home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::home)
{
    sessionNet = new QNetworkAccessManager(this);
    ui->setupUi(this);
    setFixedSize(this->width(),this->height()); //固定大小
    // 菜单栏：帮助
    connect(ui -> about, &QAction::triggered, this, &home::action_help_about_triggered); // 连接UI：关于
    connect(ui -> wiki, &QAction::triggered, this, &home::action_help_wiki_triggered); // 连接UI：WIKI
    connect(ui -> CNB, &QAction::triggered, this, &home::action_help_cnb_triggered);// 连接UI：CNB GIT
    connect(ui -> Github, &QAction::triggered, this, &home::action_help_github_triggered);// 连接UI：Github
    connect(ui -> wiki, &QAction::triggered, this, &home::action_help_wiki_triggered); // 连接UI：WIKI
    connect(ui -> updatelog, &QAction::triggered, this, &home::action_help_updatelog_triggered);//连接UI：更新日志
    connect(ui -> issuecnb, &QAction::triggered, this, &home::action_help_issuecnb_triggered);//连接UI：IssueCNB
    connect(ui -> issuegithub, &QAction::triggered, this, &home::action_help_issuegithub_triggered);//UI：IssueGH
}

home::~home()
{
    delete ui;
}





// 菜单栏业务相关定义
    //打开Wiki/文档页
void home::action_help_wiki_triggered(){
    QUrl wikiurl("https://ak.ne0w0r1d.top");
    QDesktopServices::openUrl(wikiurl);
}
    //打开CNB
void home::action_help_cnb_triggered(){
    QUrl cnb_repo("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(cnb_repo);
}
    //打开github
void home::action_help_github_triggered(){
    QUrl wikiurl("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife");
    QDesktopServices::openUrl(wikiurl);
}
    //打开关于窗口
void home::action_help_about_triggered(){
    about *aboutWidget = new about(this);
    aboutWidget->setAttribute(Qt::WA_DeleteOnClose);
    aboutWidget->exec();
}
    //打开更新日志
void home::action_help_updatelog_triggered(){
    QUrl updateurl("https://ak.ne0w0r1d.top/?id=更新日志");
    QDesktopServices::openUrl(updateurl);
}
    //IssueCNB
void home::action_help_issuecnb_triggered(){
    QUrl issuecnb("https://cnb.cool/neoengine_dev/Yumeyo_no_Army_Knife/-/issues");
    QDesktopServices::openUrl(issuecnb);
}
    //IssueGithub
void home::action_help_issuegithub_triggered(){
    QUrl issuegithub("https://github.com/Ne0W0r1d/Yumeyo_no_Army_Knife/issues");
    QDesktopServices::openUrl(issuegithub);
}
