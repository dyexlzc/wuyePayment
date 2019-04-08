#ifndef CARMONEY_H
#define CARMONEY_H

#include <QMainWindow>
#include <qsqldatabase.h>
#include <qdebug.h>
#include <qsqltablemodel.h>
#include <qmessagebox.h>
#include <qdesktopservices.h>
#include "wy_jiaofei.h"
#include "qtableview.h"
namespace Ui {
class carmoney;
}
extern QSqlDatabase db;
extern QSqlTableModel *model,*model2;
extern QString var_name,var_id,var_table;
class carmoney : public QMainWindow
{
    Q_OBJECT

public:
    explicit carmoney(QWidget *parent = 0);
    ~carmoney();
    QTableView *qtable1;
private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
    
    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_11_clicked();


    void on_pushButton_12_clicked();

private:
    Ui::carmoney *ui;

    void _s()
    {
        qtable1->setColumnWidth(0,0);
        model->removeColumn(6);
        model->removeColumn(6);
        //model->removeColumn(0);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setHeaderData(0,Qt::Horizontal,tr("唯一编号"));
       // model->setHeaderData(1,Qt::Horizontal,tr("缴费时间"));
        model->setHeaderData(1,Qt::Horizontal,tr("姓名        "));
        model->setHeaderData(2,Qt::Horizontal,tr("楼    "));
        model->setHeaderData(3,Qt::Horizontal,tr("层    "));
        model->setHeaderData(4,Qt::Horizontal,tr("户    "));
        model->setHeaderData(5,Qt::Horizontal,tr("车牌号            "));
        //model->setHeaderData(7,Qt::Horizontal,tr("停车费开始"));
        //model->setHeaderData(8,Qt::Horizontal,tr("停车费结束"));
        model->setHeaderData(6,Qt::Horizontal,tr("卡号            "));
        model->setHeaderData(7,Qt::Horizontal,tr("停车位类型        "));
        model->setHeaderData(8,Qt::Horizontal,tr("停车费金额        "));
        model->setHeaderData(9,Qt::Horizontal,tr("停车位置        "));
        model->setHeaderData(10,Qt::Horizontal,tr("电话号码            "));
        model->setHeaderData(11,Qt::Horizontal,tr("押金    "));
        model->setHeaderData(12,Qt::Horizontal,tr("停车时长    "));
        model->setHeaderData(13,Qt::Horizontal,tr("备注    "));
        model->setHeaderData(14,Qt::Horizontal,tr("停车区域    "));


    }
    void _s_3()
    {
        model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model2->removeColumn(6);
        model2->removeColumn(0);
        model2->setHeaderData(0,Qt::Horizontal,tr("姓名"));
        model2->setHeaderData(1,Qt::Horizontal,tr("缴费时间"));
        model2->setHeaderData(2,Qt::Horizontal,tr("停车费开始"));
        model2->setHeaderData(3,Qt::Horizontal,tr("停车费结束"));
        model2->setHeaderData(4,Qt::Horizontal,tr("停车费金额"));

    }
    wy_jiaofei *dlg;
};

#endif // CARMONEY_H
