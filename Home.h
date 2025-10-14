/*
******** Yumeyo's ARMY KNIFE（NetInfoChecker Qt Edition） ********
******** 2025© Ne0W0r1d
******** 2024-2025© Yumeyo
******** LGPL 2.1 License
******** This file about maininterface dependence ********
*/


#ifndef HOME_H
#define HOME_H
//所需头文件
#include <QMainWindow> //主窗口
#include <QNetworkAccessManager> //网络会话管理器
#include <QNetworkReply> // 网络回复
#include <QMenuBar> // 菜单栏
#include <QMenu>// 菜单
#include <QAction>// 指令
#include <QDesktopServices> // 与桌面交互服务
#include <QUrl> // QUrl类
#include <QMessageBox> // 标准对话框支持
#include <QHostInfo> // 主机名
#include <QHostAddress> // 主机地址
#include <QDateTime> // 时钟支持
#include <QNetworkInterface> // 网卡信息支持
#include <QList> // 动态数组支持
#include <QRegularExpression> // 正则表达式支持

QT_BEGIN_NAMESPACE
namespace Ui {
class home;
}
QT_END_NAMESPACE

class home : public QMainWindow
{
    Q_OBJECT

public:
    home(QWidget *parent = nullptr);
    ~home();
    void getwanv4(); // 获取广域v4信息
    void getwanv6(); // 获取广域v6信息
    void getisp(); // 获取ISP
    void getlan(); // 获取LAN相关
    void getpriority();// 查询IP优先级
private slots:
    /*Help*/
    void action_help_wiki_triggered();//wiki信号
    void action_help_cnb_triggered();//cnb信号
    void action_help_about_triggered();//关于信号
    void action_help_github_triggered();//github信号
    void action_help_updatelog_triggered();//更新日志信号
    void action_help_issuecnb_triggered();//IssueCNB
    void action_help_issuegithub_triggered();//IssueGithub
    /*Home*/
    void action_homeinfo_refresh(); // 刷新按钮
    // void action_homeinfo_settings(); //设置按钮
    // void action_homeinfo_recordtofile(); // 记录当前IP地址按钮
    // void action_homeinfo_privacymode(); // 隐私模式按钮
    // void action_homeinfo_checkrecorded(); //查询已记录按钮
private:
    Ui::home *ui;
    QNetworkAccessManager *sessionNet;
};
#endif // HOME_H
