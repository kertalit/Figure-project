#pragma once
#include "Database.h"
#include "FileDataProvider.h"
#include "DataProvider.h"


Figure* createObj(int type);


void addObj(Figure* obj, Database& db);

void saveDb(Database* base);

Database* loadDb();

Database* createDb();

void saveObj(Database& base, std::vector<Figure*>& obj);

void changeObj();
