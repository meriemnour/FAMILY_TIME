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
    QPixmap pix("C:/Users/asus/Desktop/rsz_7-tips-for-kids-safety-online-1200x628-1.png");
    ui->label->setPixmap(pix);

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
