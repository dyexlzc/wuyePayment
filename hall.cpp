#include "hall.h"
#include "ui_hall.h"
#include "carmoney.h"
#include "qsqlquery.h"
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include "qsqlerror.h"
hall::hall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hall)
{
    ui->setupUi(this);
    setWindowTitle( "管理大厅");

    int i;int _temp;
    QSqlQuery query(db);
    QList<int> _slikt;






    query.exec("select distinct lou from car where name in (select name from car_time where date(over_time) < date('now','+7 day') and tok = 1) and date(over_time) < date('now','+7 day')");

    while(query.next())
    {

       //qDebug()<<query.value(0);
       _temp=query.value(0).toInt();
        if(_temp!=0)
        _slikt<<_temp;
    }
    //qSort(sortlist.begin(),sortlist.end());
    //sortlist=_slikt.
    qSort(_slikt.begin(),_slikt.end());
    for(i=0;i<_slikt.length();i++)
    {
       ui->comboBox->insertItem(i,QString("%1").arg(_slikt[i]));
    }
    _slikt.clear();






    query.exec("select distinct lou from allp where name in (select name from allp_time where date(over_time) < date('now','+31 day') and tok = 1) and date(over_time) < date('now','+31 day')");
    while(query.next())
    {
        //qDebug()<<query.value(0);
        _temp=query.value(0).toInt();
         if(_temp!=0)
         _slikt<<_temp;
    }
    //qSort(sortlist.begin(),sortlist.end());
    //sortlist=_slikt.
    qSort(_slikt.begin(),_slikt.end());
    for(i=0;i<_slikt.length();i++)
    {
       ui->comboBox_2->insertItem(i,QString("%1").arg(_slikt[i]));
    }
    _slikt.clear();





    model=new QSqlTableModel(ui->tableView_2);
    model->setTable("allp");
    model->setFilter(QString("name in (select name from allp_time where date(over_time) <= date('now','+7 day') and tok = 1) and date(over_time) <= date('now','+7 day')"));
    model->select();

    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _s_2();
    ui->tableView_2->setModel(model);


    //QMessageBox::about(this,"ok",tr("设置表格"));
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("name in (select name from car_time where date(over_time) <= date('now','+7 day') and tok = 1) and date(over_time) <= date('now','+7 day')"));
    //model->setFilter("name = '梁子聪'");
    model->select();
   //  QMessageBox::about(this,"ok",QString("%1").arg(model->lastError().text()  ));
    _s();

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
    ui->tableView_2->resizeColumnsToContents();
   // QMessageBox::about(this,"ok",tr("完毕"));

    ui->comboBox->insertItem(0,"*");
    ui->comboBox_2->insertItem(0,"*");


}

hall::~hall()
{
    db.close();
    delete ui;
}


//第一个参数是页面上的表格，第二个是导出文件的表头数据
void hall::Table2ExcelByHtml(QTableView *table,QString title)
 {
     QMessageBox::about(NULL,"注意","正在导出，过程中会卡顿，请点击确定以后等待成功提示");
     QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
     if (fileName!="")
     {
         QAxObject *excel = new QAxObject;
         if (excel->setControl("Excel.Application")) //连接Excel控件
         {
             //excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
             excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
             excel->setProperty("Visible", false);
             QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
             workbooks->dynamicCall("Add");//新建一个工作簿
             QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
             QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

             int i,j;
             int colcount=table->model()->columnCount();
             int rowcount=table->model()->rowCount();

             QAxObject *cell,*col;
             //标题行
             cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
             cell->dynamicCall("SetValue(const QString&)", title);
             cell->querySubObject("Font")->setProperty("Size", 18);
             //调整行高
             worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
             //合并标题行
             QString cellTitle;
             cellTitle.append("A1:");
             cellTitle.append(QChar(colcount - 1 + 'A'));
             cellTitle.append(QString::number(1));
             QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
             range->setProperty("WrapText", true);
             range->setProperty("MergeCells", true);
             range->setProperty("HorizontalAlignment", -4108);//xlCenter
             range->setProperty("VerticalAlignment", -4108);//xlCenter

             //列标题
             for(i=0;i<colcount;i++)
             {
                 QString columnName;
                 columnName.append(QChar(i  + 'A'));
                 columnName.append(":");
                 columnName.append(QChar(i + 'A'));
                 col = worksheet->querySubObject("Columns(const QString&)", columnName);
                 col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                 cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                 //QTableWidget 获取表格头部文字信息
                 //columnName=table->horizontalHeaderItem(i)->text();
                 //QTableView 获取表格头部文字信息
                 columnName=table->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                 cell->dynamicCall("SetValue(const QString&)", columnName);
                 cell->querySubObject("Font")->setProperty("Bold", true);
                 cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                 cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                 cell->setProperty("VerticalAlignment", -4108);//xlCenter
             }

            //数据区

            //QTableWidget 获取表格数据部分
            /* for(i=0;i<rowcount;i++){
                 for (j=0;j<colcount;j++)
                 {
                     worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
                 }
             }*/


            //QTableView 获取表格数据部分

              for(i=0;i<rowcount;i++) //行数
                 {
                     for (j=0;j<colcount;j++)   //列数
                     {
                         QModelIndex index =table->model()->index(i, j);
                         QString strdata=table->model()->data(index).toString();
                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
                    }
                 }


             //画框线
             QString lrange;
             lrange.append("A2:");
             lrange.append(colcount - 1 + 'A');
             lrange.append(QString::number(table->model()->rowCount() + 2));
             range = worksheet->querySubObject("Range(const QString&)", lrange);
             range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
             range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
             //调整数据区行高
             QString rowsName;
             rowsName.append("2:");
             rowsName.append(QString::number(table->model()->rowCount() + 2));
             range = worksheet->querySubObject("Range(const QString&)", rowsName);
             range->setProperty("RowHeight", 20);
             workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
             workbook->dynamicCall("Close()");//关闭工作簿
             excel->dynamicCall("Quit()");//关闭excel
             delete excel;
             excel=NULL;
             if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
             {
                 QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
             }
         }
         else
         {
             QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
         }
     }
 }

void hall::on_pushButton_2_clicked()
{
    dlg2=new carmoney(this);
    dlg2->show();
}
void hall::on_pushButton_clicked()
{
    dlg=new viewdata(this);
    dlg->show();
}

void hall::on_pushButton_3_clicked()
{
    Table2ExcelByHtml(ui->tableView,"车位到期");
}

void hall::on_pushButton_4_clicked()
{
     Table2ExcelByHtml(ui->tableView_2,"物业费到期");
}

void hall::on_comboBox_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");

    if(ui->comboBox->currentText()=="*")
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day')").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText()));
    }
   else
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day') and lou = %3").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText(),ui->comboBox->currentText()));

    }


    model->select();
    _s();
    ui->tableView->setModel(model);
}


void hall::on_comboBox_2_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView_2);
    model->setTable("allp");

    if(ui->comboBox_2->currentText()=="*")
    {
        model->setFilter(QString("name in (select name from allp_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day')").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText()));
    }
   else
    {
        model->setFilter(QString("name in (select name from allp_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day') and lou = %3").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText(),ui->comboBox_2->currentText()));

    }

    model->select();
    _s_2();
    ui->tableView_2->setModel(model);
}

void hall::on_comboBox_5_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    if(ui->comboBox->currentText()=="*")
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day')").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText()));
    }
   else
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day') and lou = %3").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText(),ui->comboBox->currentText()));

    }

    model->select();
    _s();
    ui->tableView->setModel(model);
}

void hall::on_pushButton_5_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    if(ui->comboBox->currentText()=="*")
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day')").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText()));
    }
   else
    {
        model->setFilter(QString("name in (select name from car_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day') and lou = %3").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText(),ui->comboBox->currentText()));

    }

    model->select();
    _s();
    ui->tableView->setModel(model);

    model=new QSqlTableModel(ui->tableView_2);
    model->setTable("allp");

    if(ui->comboBox_2->currentText()=="*")
    {
        model->setFilter(QString("name in (select name from allp_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day')").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText()));
    }
   else
    {
        model->setFilter(QString("name in (select name from allp_time where date(over_time) < date('now','+%1 day') and tok = 1) and date(over_time) < date('now','+%2 day') and lou = %3").arg(ui->comboBox_5->currentText(),ui->comboBox_5->currentText(),ui->comboBox_2->currentText()));

    }


    model->select();
    _s_2();
    ui->tableView_2->setModel(model);
}

void hall::on_comboBox_5_currentIndexChanged(const QString &arg1)
{

}
