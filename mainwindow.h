#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qsqldatabase.h>
#include <qdebug.h>
#include <qsqlquerymodel.h>
#include <qmessagebox.h>
#include "hall.h"
#include "qdialog.h"
#include "style.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    hall *dlg1;
};

#endif // MAINWINDOW_H
