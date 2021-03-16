#ifndef OBJET_ENFANT_H
#define OBJET_ENFANT_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QMessageBox>
class objet_enfant
{
public:
    objet_enfant();
    objet_enfant(int,QString,int,QString,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
private:
    int id;
    QString nomobjet;
    int nbobjet;
    QString type;
    QString priority;

};

#endif // OBJET_ENFANT_H


