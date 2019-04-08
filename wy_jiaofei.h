#ifndef WY_JIAOFEI_H
#define WY_JIAOFEI_H

#include <QDialog>
#include "qsqldatabase.h"
#include "QCloseEvent"
#include "qdebug.h"

namespace Ui {
class wy_jiaofei;
}
extern QString var_name;
extern QString var_id;
extern QSqlDatabase db;
extern QString var_table;
class wy_jiaofei : public QDialog
{
    Q_OBJECT

public:
    explicit wy_jiaofei(QWidget *parent = 0);
    ~wy_jiaofei();
    void closeEvent(QCloseEvent* event)
    {
        qDebug()<<"dd";
        if(var_table=="car")
        {


        }
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::wy_jiaofei *ui;
};

#endif // WY_JIAOFEI_H
