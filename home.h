#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

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
    void on_wiki_triggered();//wiki信号
    void on_cnb_triggered();//cnb信号
    //void onAction_about_triggered();//关于信号
    void onAction_github_triggered();//github信号
    void onAction_updatelog_triggered();//更新日志信号
private:
    Ui::home *ui;

};
#endif // HOME_H
