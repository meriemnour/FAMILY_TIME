#include "connection.h"

//test tutoriel git


Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("nour");//inserer nom de l'utilisateur
db.setPassword("meriem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
