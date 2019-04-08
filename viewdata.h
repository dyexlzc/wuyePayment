#ifndef VIEWDATA_H
#define VIEWDATA_H

#include "qmainwindow.h"
#include <qsqldatabase.h>
#include <qdebug.h>
#include <qsqltablemodel.h>
#include <qmessagebox.h>
#include "wy_jiaofei.h"
#include <qtableview.h>
namespace Ui {
class viewdata;
}
extern QSqlDatabase db;
extern QSqlTableModel *model,*model2;
class viewdata : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewdata(QWidget *parent = 0);
    ~viewdata();
    QTableView *qtable1;
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_9_clicked();

private:
    Ui::viewdata *ui;
    wy_jiaofei *dlg;
     void _s()
     {model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->removeColumn(6);
        model->removeColumn(6);
        qtable1->setColumnWidth(0,0);
         model->setHeaderData(0,Qt::Horizontal,tr("唯一编号"));
         model->setHeaderData(1,Qt::Horizontal,tr("姓名        "));
         model->setHeaderData(2,Qt::Horizontal,tr("楼    "));
         model->setHeaderData(3,Qt::Horizontal,tr("层    "));
         model->setHeaderData(4,Qt::Horizontal,tr("户    "));
         model->setHeaderData(5,Qt::Horizontal,tr("面积        "));
         model->setHeaderData(6,Qt::Horizontal,tr("电话号码            "));
         model->setHeaderData(7,Qt::Horizontal,tr("备注            "));
         model->setHeaderData(8,Qt::Horizontal,tr("是否交物业费"));
     }
     void _s_3()
     {model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
         model2->removeColumn(6);
         model2->removeColumn(0);
         model2->setHeaderData(0,Qt::Horizontal,tr("姓名"));
         model2->setHeaderData(1,Qt::Horizontal,tr("缴费时间"));
         model2->setHeaderData(2,Qt::Horizontal,tr("物业费开始"));
         model2->setHeaderData(3,Qt::Horizontal,tr("物业费结束"));
         model2->setHeaderData(4,Qt::Horizontal,tr("物业费金额"));
     }
};

#endif // VIEWDATA_H
