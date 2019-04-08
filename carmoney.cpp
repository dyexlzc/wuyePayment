#include "carmoney.h"
#include "ui_carmoney.h"
#include "qsqlquery.h"
#include "qsqltablemodel.h"
#include "qtablewidget.h"
#include "qtextcodec.h"
#include "qstringlist.h"
#include "qlist.h"

carmoney::carmoney(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::carmoney)
{
    ui->setupUi(this);
    int i=0,_temp;
    this->qtable1=ui->tableView;
   // if(db==NULL){
    /*db=QSqlDatabase::addDatabase("QSQLITE","forcar");
    db.setDatabaseName("test.db");//设置本地sqlite数据库*/
    //}
    /*if(!db.open())
    {
       QMessageBox::about(this,"ok",tr("数据库打开失败"));
    }
    else
    {*/

        //QMessageBox::about(this,"ok",tr("打开成功 "));
        QSqlQuery query(db);
        QList<int> _slikt;
        query.exec("select distinct lou from car");
        while(query.next())
        {
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




        query.exec("select distinct ceng from car");
        while(query.next())
        {
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

        query.exec("select distinct hu from car");
        while(query.next())
        {
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
        ui->comboBox_2->insertItem(0,"*");
        ui->comboBox_3->insertItem(0,"*");
        qDebug()<<db.tables();
        model=new QSqlTableModel(ui->tableView);
        model->setTable("car");
        if(ui->comboBox->currentText()!="*")
            model->setFilter(QString("lou=%1").arg(ui->comboBox->currentText()));
        model->select();
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        _s();

        ui->tableView->setModel(model);

    //}
}

carmoney::~carmoney()
{
    //db.close();
    delete ui;
}



void carmoney::on_comboBox_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
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

void carmoney::on_comboBox_2_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
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

void carmoney::on_comboBox_3_currentIndexChanged(int index)
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
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

void carmoney::on_pushButton_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("name like '%")+QString("%1").arg(ui->lineEdit->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_2_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("carnumber like '%")+QString("%1").arg(ui->lineEdit_2->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_3_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_5_clicked()
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
        // QMessageBox::warning(this, tr("tableModel"),tr("提交成功"));
     } else {
         model2->database().rollback(); //回滚
        // QMessageBox::warning(this, tr("tableModel"),tr("数据库错误"));
     }
}

void carmoney::on_pushButton_4_clicked()
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
     }else{
     model->submitAll(); //否则提交，在数据库中删除该行
     }*/

}

void carmoney::on_pushButton_6_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
   //int id = 10;
    model->insertRow(rowNum); //添加一行
}

void carmoney::on_pushButton_8_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("type = '买'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_7_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("type = '租'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_9_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("cardnum like '%")+QString("%1").arg(ui->lineEdit_3->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_pushButton_10_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("pos like '%")+QString("%1").arg(ui->lineEdit_4->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}

void carmoney::on_tableView_pressed(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(ui->tableView->model()->index( ui->tableView->currentIndex().row(),0)).toString();
    QString name=ui->tableView->model()->data(ui->tableView->model()->index( ui->tableView->currentIndex().row(),1)).toString();
    var_name=name;
    var_id=id;
        QString str11=QString("%1的交费历史").arg(name);
        ui->label_8->setText(str11);
        model2=new QSqlTableModel(ui->tableView_2);
        model2->setTable("car_time");

        model2->setFilter(QString("name = '%1' and id = '%2'").arg(name).arg(id));

        model2->select();
        _s_3();
        ui->tableView_2->setModel(model2);

}

void carmoney::on_pushButton_11_clicked()
{
    var_table="car_time";

    dlg=new wy_jiaofei(this);
    dlg->setModal(true);
    dlg->show();

}

void carmoney::on_pushButton_12_clicked()
{
    model=new QSqlTableModel(ui->tableView);
    model->setTable("car");
    model->setFilter(QString("number like '%")+QString("%1").arg(ui->lineEdit_5->text())+QString("%'"));
    model->select();
    _s();
    ui->tableView->setModel(model);
}
