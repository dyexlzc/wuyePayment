#ifndef HALL_H
#define HALL_H

#include "qdialog.h"
#include "viewdata.h"
#include "qtablewidget.h"
#include "qfiledialog.h"
#include "qstandardpaths.h"
#include "carmoney.h"

namespace Ui {
class hall;
}
extern QSqlDatabase db;
extern QSqlTableModel *model,*model2;
extern QStringList tables ;
class hall : public QDialog
{
    Q_OBJECT

public:
    explicit hall(QWidget *parent = 0);
    ~hall();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);



    void on_comboBox_2_currentIndexChanged(int index);



    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

private:
    Ui::hall *ui;
    carmoney *dlg2;

    viewdata *dlg;
    void _s_2()
    {
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setHeaderData(0,Qt::Horizontal,tr("唯一编号      "));
        model->setHeaderData(1,Qt::Horizontal,tr("姓名      "));
        model->setHeaderData(2,Qt::Horizontal,tr("楼   "));
        model->setHeaderData(3,Qt::Horizontal,tr("层   "));
        model->setHeaderData(4,Qt::Horizontal,tr("户   "));

        model->setHeaderData(5,Qt::Horizontal,tr("面积   "));
        model->setHeaderData(6,Qt::Horizontal,tr("物业费开始      "));
        model->setHeaderData(7,Qt::Horizontal,tr("物业费结束      "));
        model->setHeaderData(8,Qt::Horizontal,tr("电话号码            "));
        model->setHeaderData(9,Qt::Horizontal,tr("备注      "));
        model->setHeaderData(10,Qt::Horizontal,tr("是否交物业费"));

    }
    void _s()
    {
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setHeaderData(0,Qt::Horizontal,tr("唯一编号"));

        model->setHeaderData(1,Qt::Horizontal,tr("姓名    "));
        model->setHeaderData(2,Qt::Horizontal,tr("楼  "));
        model->setHeaderData(3,Qt::Horizontal,tr("层  "));
        model->setHeaderData(4,Qt::Horizontal,tr("户  "));
        model->setHeaderData(5,Qt::Horizontal,tr("车牌号           "));
        model->setHeaderData(6,Qt::Horizontal,tr("停车费开始        "));
        model->setHeaderData(7,Qt::Horizontal,tr("停车费结束        "));
        model->setHeaderData(8,Qt::Horizontal,tr("卡号      "));
        model->setHeaderData(9,Qt::Horizontal,tr("停车位类型"));
        model->setHeaderData(10,Qt::Horizontal,tr("停车费金额"));
        model->setHeaderData(11,Qt::Horizontal,tr("停车位置"));
        model->setHeaderData(12,Qt::Horizontal,tr("电话号码                              "));
        model->setHeaderData(13,Qt::Horizontal,tr("押金"));
        model->setHeaderData(14,Qt::Horizontal,tr("停车时长      "));
        model->setHeaderData(15,Qt::Horizontal,tr("备注      "));
        model->setHeaderData(16,Qt::Horizontal,tr("停车区域      "));
    }
     void Table2ExcelByHtml(QTableView *table,QString title);
};

#endif // HALL_H
