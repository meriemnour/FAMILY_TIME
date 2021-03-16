#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "dialog_enfant.h"
#include "dialog_objet.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_pushButton_clicked()
{
    Dialog_enfant d;
    d.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog_objet d;
    d.exec();

}
