#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QTimer>
#include "etat.h"
#include "repas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  //  void on_pushButton_clicked();

    void on_b_ajouter_3_clicked();

    //void on_pushButton_2_clicked();

    void on_b_modifier_3_clicked();

    void on_b_sup_3_clicked();

    void on_b_ajouter_repa_clicked();

    void on_b_modifier_repa_clicked();

    void on_b_sup_repas_clicked();

private:
   Ui::MainWindow *ui;
   Etat_enfant tmp ;
   repas etmp;
};
#endif // MAINWINDOW_H
