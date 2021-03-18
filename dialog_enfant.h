#ifndef DIALOG_ENFANT_H
#define DIALOG_ENFANT_H

#include <QDialog>
#include "enfant.h"
#include <QMessageBox>
namespace Ui {
class Dialog_enfant;
}

class Dialog_enfant : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_enfant(QWidget *parent = nullptr);
    ~Dialog_enfant();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_label_15_linkActivated(const QString &link);

private:
    Ui::Dialog_enfant *ui;
    enfant tmpenf;
    int id;
};

#endif // DIALOG_ENFANT_H
