#include "wy_jiaofei.h"
#include "ui_wy_jiaofei.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
wy_jiaofei::wy_jiaofei(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wy_jiaofei)
{
    ui->setupUi(this);

     setFixedSize(790,400); // 禁止改变窗口大小。
     if(var_name=="")
     {
         QMessageBox::warning(this, tr("tableModel"),tr("还未选中人！"));
          close();
     }
     else{
     setWindowTitle(QString("给")+var_name+QString("缴费"));
     ui->label_2->setText(var_id);
     ui->label_4->setText(var_name);

     }
}

wy_jiaofei::~wy_jiaofei()
{
    delete ui;
}

void wy_jiaofei::on_pushButton_clicked()
{

    if(ui->lineEdit->text().length()==0)
    {
        QMessageBox::warning(this, tr("tableModel"),tr("请输入金额"));
    }else{
    QSqlQuery query(db);
    QString jiaofei=ui->calendarWidget_3->selectedDate().toString("yyyy-MM-dd");
    QString start = ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString over = ui->calendarWidget_2->selectedDate().toString("yyyy-MM-dd");
   //qDebug()<<QString("insert into %1 values ('%2','%3','%4','%5','%6',1)").arg(var_table,var_id,var_name,start,over,ui->lineEdit->text());
    query.exec(QString("update %1 set over_time = '%2' where name = '%3' and id = %4").arg(var_table=="car_time"?"car":"allp",over,var_name,var_id));
    query.exec(QString("update %1 set start_time = '%2' where name = '%3' and id = %4").arg(var_table=="car_time"?"car":"allp",start,var_name,var_id));
    query.exec(QString("update %1 set tok = 0 where name = '%2' and id = %3").arg(var_table,var_name,var_id));
    //以上是更新原表里面的数据
    //query.clear();
    query.exec(QString("  insert into %1 values ('%2','%3','%4','%5','%6','%7',1)    "   ).arg(var_table,var_id,var_name,jiaofei,start,over,ui->lineEdit->text()));
    //添加到历史缴费记录
    QMessageBox::warning(this, tr("tableModel"),tr("缴费成功"));
    //qDebug()<<var_table;
    var_name="";
    close();
    }
}
