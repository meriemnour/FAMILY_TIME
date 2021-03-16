#ifndef DIALOG_OBJET_H
#define DIALOG_OBJET_H

#include <QDialog>
#include "objet_enfant.h"
namespace Ui {
class Dialog_objet;
}

class Dialog_objet : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_objet(QWidget *parent = nullptr);
    ~Dialog_objet();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog_objet *ui;
    objet_enfant tmpo;
};

#endif // DIALOG_OBJET_H
