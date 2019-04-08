#include "viewdata.h"
#include "ui_viewdata.h"
#include "qsqlquery.h"
#include "qsqltablemodel.h"
#include "qtablewidget.h"
#include "qtextcodec.h"
#include "qstringlist.h"

QString var_name,var_id,var_table;
viewdata::viewdata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewdata)
{
    ui->setupUi(this);
    QApplication::addLibraryPath("plugins");
    int i,_temp;
    this->qtable1=ui->tableView;
    //QMessageBox::about(this,"ok",tr("？？"));
    //创建数据库实例
    /*db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");//设置本地sqlite数据库
    if(!db.open())
    {
       QMessageBox::about(this,"ok",tr("数据库打开失败"));
    }
    else
    {*/
        //QMessageBox::about(this,"ok",tr("打开成功 "));
        QSqlQuery query(db);
        QList<int> _slikt;
        query.exec("select distinct lou from allp");
        while(query.next())
        {
           // sortlist<<query.value(0).toString();
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
           ui->comboBox_4->insertItem(i,QString("%1").arg(_slikt[i]));
           ui->comboBox_5->insertItem(i,QString("%1").arg(_slikt[i]));
        }
        _slikt.clear();




        query.exec("select distinct ceng from allp");
        while(query.next())
        {
           // sortlist<<query.value(0).toString();
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

        query.exec("select distinct hu from allp");
        while(query.next())
        {
           // sortlist<<query.value(0).toString();
            _temp=query.value(0).toInt();
             if(_temp!=0)
             _slikt<<_temp;
        }
        //qSort(sortlist.begin(),sortlist.end());
        //sortlist=_slikt.
        qSort(_slikt.begin(),_slikt.end());
        for(i=0;i<_slikt.length();i++)
        {
           ui->comboBox_3->insertItem(i,QString("%1").arg(_slikt[i]));
        }
        _slikt.clear();


        ui->comboBox->insertItem(0,"*");
        ui->comboBox_4->insertItem(0,"*");
        ui->comboBox_5->insertItem(0,"*");
        ui->comboBox_2->insertItem(0,"*");
        ui->comboBox_3->insertItem(0,"*");

        //qDebug()<<db.tables();
        model=new QSqlTableModel(ui->tableView);
        model->setTable("allp");
        if(ui->comboBox->currentText()!="*")
            model->setFilter(QString("lou=%1").arg(ui->comboBox->currentText()));
        model->select();
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        _s();

        ui->tableView->setModel(model);

   // }


}

viewdata::~viewdata()
{
    //db.close();
    delete ui;
}

void viewdata::on_comboBox_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        qDebug()<<"aaa";
    }
   else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1").arg(ui->comboBox->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("ceng=%1").arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {

        model->setFilter(QString("hu=%1").arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("ceng=%1 and hu=%2").arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and hu=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2 and hu=%3").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void viewdata::on_comboBox_2_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        qDebug()<<"aaa";
    }
   else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1").arg(ui->comboBox->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("ceng=%1").arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {

        model->setFilter(QString("hu=%1").arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("ceng=%1 and hu=%2").arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and hu=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2 and hu=%3").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void viewdata::on_comboBox_3_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        qDebug()<<"aaa";
    }
   else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1").arg(ui->comboBox->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("ceng=%1").arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {

        model->setFilter(QString("hu=%1").arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()=="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()));

    }
    else if(ui->comboBox->currentText()=="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("ceng=%1 and hu=%2").arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()=="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and hu=%2").arg(ui->comboBox->currentText()).arg(ui->comboBox_3->currentText()));

    }
    else if(ui->comboBox->currentText()!="*"&&ui->comboBox_2->currentText()!="*"&&ui->comboBox_3->currentText()!="*")
    {
        model->setFilter(QString("lou=%1 and ceng=%2 and hu=%3").arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(ui->comboBox_3->currentText()));

    }
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void viewdata::on_pushButton_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    model->select();
    _s();
    ui->tableView->setModel(model);
}



void viewdata::on_pushButton_4_clicked()
{
    model->database().transaction(); //开始事务操作
     if (model->submitAll()) {
         model->database().commit(); //提交
        QMessageBox::warning(this, tr("tableModel"),tr("提交成功"));
     } else {
         model->database().rollback(); //回滚
         QMessageBox::warning(this, tr("tableModel"),tr("数据库错误"));
     }
     model2->database().transaction(); //开始事务操作
     if (model2->submitAll()) {
         model2->database().commit(); //提交
         //QMessageBox::warning(this, tr("tableModel"),tr("提交成功"));
     } else {
         model2->database().rollback(); //回滚
        // QMessageBox::warning(this, tr("tableModel"),tr("数据库错误"));
     }
}

void viewdata::on_pushButton_3_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
     //获取选中的行
     model->removeRow(curRow);
     //删除该行
     /*int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？无法撤销"),
                          QMessageBox::Yes,QMessageBox::No);
     if(ok == QMessageBox::No)
     {
        model->revertAll(); //如果不删除，则撤销
     }
     else
     {
     model->submitAll(); //否则提交，在数据库中删除该行
     }*/


}

void viewdata::on_pushButton_2_clicked(bool checked)
{
    int rowNum = model->rowCount(); //获得表的行数
   //int id = 10;
    model->insertRow(rowNum); //添加一行
   // model->setData(model->index(rowNum,0),id);
}

void viewdata::on_pushButton_5_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    model->setFilter(QString("date(over_time) < date('now','+31 day') and lou = %1 and ifok = '' ").arg(ui->comboBox_4->currentText()));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void viewdata::on_pushButton_6_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    model->setFilter(QString("date(over_time) < date('now','+31 day') and lou = %1 and ifok !='' ").arg(ui->comboBox_4->currentText()));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void viewdata::on_pushButton_7_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    model->setFilter(QString("name like '%")+QString("%1").arg(ui->lineEdit->text())+QString("%'"));
    qDebug()<<QString("name like '%")+QString("%1").arg(ui->lineEdit->text())+QString("%'");
    model->select();
    _s();
    ui->tableView->setModel(model);
}



void viewdata::on_tableView_pressed(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(ui->tableView->model()->index( ui->tableView->currentIndex().row(),0)).toString();
    QString name=ui->tableView->model()->data(ui->tableView->model()->index( ui->tableView->currentIndex().row(),1)).toString();
    var_name=name;
    var_id=id;
        QString str11=QString("%1的交费历史").arg(name);
        ui->label_7->setText(str11);
        model2=new QSqlTableModel(ui->tableView_2);
        model2->setTable("allp_time");
        //qDebug()<<QString("name = '%1'").arg(str11);
        model2->setFilter(QString("name = '%1' and id = '%2'").arg(name).arg(id));
        //model->setFilter("wy_start");
        model2->select();
        _s_3();
        ui->tableView_2->setModel(model2);
}

void viewdata::on_pushButton_8_clicked()
{
    var_table="allp_time";
    dlg=new wy_jiaofei(this);
    dlg->setModal(true);
    dlg->show();

}

void viewdata::on_pushButton_2_clicked()
{

}

void viewdata::on_pushButton_4_clicked(bool checked)
{

}

void viewdata::on_pushButton_9_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("allp");
    model->setFilter(QString("number like '%")+QString("%1").arg(ui->lineEdit_2->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}
