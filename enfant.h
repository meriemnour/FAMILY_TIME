#ifndef ENFANT_H
#define ENFANT_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class enfant
{
public:
    enfant();
    enfant(int,QString,QString,QString,QString,float,float);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool rechercher(int);
    bool modifier(int);
private:
    int id;
    QString nom;
    QString prenom;
    QString sexe;
    QString datenais;
    float poids;
    float hauteur;
};

#endif // ENFANT_H
