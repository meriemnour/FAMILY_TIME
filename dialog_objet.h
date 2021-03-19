#ifndef DIALOG_OBJET_H
#define DIALOG_OBJET_H

#include <QDialog>
#include "objet_enfant.h"
#include <QMetaType>
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

    void on_label_3_linkActivated(const QString &link);

    void on_pushButton_4_clicked();

private:
    Ui::Dialog_objet *ui;
    objet_enfant tmpo;
      int id;
};

#endif // DIALOG_OBJET_H
