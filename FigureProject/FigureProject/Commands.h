#ifndef _COMMANDS_H
#define _COMMANDS_H

#include "Database.h"
#include "FileDataProvider.h"


#include "DataProvider.h"


Figure* createObj(int type);


void saveDb(Database* base);

Database* loadDb();

Database* createDb();

void changeObj(Figure* obj);

void listDb(Database* base);

int serchId(std::vector<Figure*> obj, int key);


#endif // !_COMMANDS_H