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
#include <QDateTime> // 时钟支持
#include <QNetworkInterface> // 网卡信息支持
#include <QList> // 动态数组支持

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

private slots:
    /*Help*/
    void action_help_wiki_triggered();//wiki信号
    void action_help_cnb_triggered();//cnb信号
    void action_help_about_triggered();//关于信号
    void action_help_github_triggered();//github信号
    void action_help_updatelog_triggered();//更新日志信号
    void action_help_issuecnb_triggered();//IssueCNB
    void action_help_issuegithub_triggered();//IssueGithub
    /*Tools*/
    // void action_tools_wol();//菜单栏WOL
    // void action_tools_TraceRote();//Trace Route
    // void action_tools_nat();

private:
    Ui::home *ui;
    QNetworkAccessManager *sessionNet;
    void getV4dd();
    void getV6dd();
    void getISP();
};
#endif // HOME_H
