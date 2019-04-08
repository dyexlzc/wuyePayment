#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include "qsqlquery.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Qt5Base.dll");//设置本地sqlite数据库

    //设置楼层
    tables = db.tables();  //获取数据库中的表
    if(!db.open())
    {
        qDebug()<<"e";
       QMessageBox::about(this,"ok",tr("数据库打开失败"));
    }


}
QSqlDatabase db;
QSqlTableModel *model,*model2;
QStringList tables ;
MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query(db);
    query.exec(QString("select * from user where username='%1'").arg(ui->lineEdit->text()).trimmed());

    query.first();
    qDebug()<<query.value(2).toString();
    if(ui->lineEdit_2->text()==""||ui->lineEdit->text()=="")
    {
        QMessageBox::about(this,"err","请输入用户名或密码");
        return;
    }
    if(ui->lineEdit_2->text()==query.value(2).toString())
    {
        qDebug()<<"登陆成功";
        QMessageBox::about(this,"ok",tr("登陆成功"));
        dlg1=new hall();
        dlg1->setModal(false);
        dlg1->show();
        close();
    }
    else
    {
        QMessageBox::about(this,"ok",tr("登陆失败！"));
    }
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}
