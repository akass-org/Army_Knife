#ifndef HOME_H
#define HOME_H
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

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
    void action_help_wiki_triggered();//wiki信号
    void action_help_cnb_triggered();//cnb信号
    void action_help_about_triggered();//关于信号
    void action_help_github_triggered();//github信号
    void action_help_updatelog_triggered();//更新日志信号
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
