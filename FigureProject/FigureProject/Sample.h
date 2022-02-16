#pragma once
#include "Database.h"
#include "DataProvider.h"


Figure* createObj(int type);

Database createDb(const std::string& path);

void addObj(Figure* obj, Database& db);

void saveDb(Database& db);

void loadDb(Database& db);

