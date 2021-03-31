#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");
db.setUserName("amine");
db.setPassword("amine");

if (db.open())
test=true;
return test;


}
