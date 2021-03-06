#ifndef __WWIDGET_H__
#define __WWIDGET_H__

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtGui/QLineEdit>
#include <QtGui/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QString>

/**
 * @brief    WWidget: wps widget类, 从QT库的QWidget类继承
 */
class WWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WWidget(QWidget *parent = 0);
    virtual ~WWidget();
    /* 对给定两文件的绝对路径, 将两文件中相同的行去掉,输入文件分别备份 */
    void deal_with_file(const QString fir_path, const QString sec_path);

private:
    void init_widget();    /* 初始化控件 */
    void init_connection();    /* 初始化信号与槽 */
    bool judge_file(const QString filename);  /* 判断文件是否存在 */
    QString get_filename(const QString filename);    /* 获取文件名 */
    QString backup_file(const QString file_abs_path);   /* 备份文件 */

signals:

private slots:
    void fir_filename_from_fdlg();    /* 从文件对话框中选择第一个文件 */
    void get_fir_le_text(const QString str);    /* 第一个文本输入域的文体 */
    void sec_filename_from_fdlg();    /* 从文件对话框中选择第二个文件 */
    void get_sec_le_text(const QString str);    /* 第二个文本输入域的文体 */
    void exec_remove_lines();         /* 执行两件文的操作 */
    /* 删除相同的行,并更新文件 */
    void reflesh_file(const QString filename, const QString bak, const QHash<QString, bool> &str_hash);

private:
    /* 两个选择文件的按钮, 及一个执行命令的按钮 */
    QPushButton fir_file_btn, sec_file_btn;
    /* 两个文本输入域, 用于保存输入文件的绝对路径名 */
    QLineEdit fir_file_le, sec_file_le;
    /* 两文件的绝对路径名 */
    QString fir_file_str, sec_file_str;

    /* 执行按钮 */
    QPushButton process_btn;

    /* 布局管理器 */
    QGridLayout layout;

    QFile file_one, file_two;
};

#endif /* __WWIDGET_H__ */
