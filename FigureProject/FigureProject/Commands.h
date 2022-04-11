#ifndef _COMMANDS_H
#define _COMMANDS_H

#include "Database.h"
#include "FileDataProvider.h"
#include "DataProvider.h"
#include <memory>


std::shared_ptr<Figure> createObj(int type);


void saveDb(std::shared_ptr<Database> base);

std::shared_ptr<Database> loadDb();

std::shared_ptr<Database> createDb();

void changeObj(std::shared_ptr<Figure> obj);

void listDb(std::shared_ptr<Database> base);

int searchId(std::vector<std::shared_ptr<Figure> > obj, int key);

void deleteFigure(std::vector < std::shared_ptr<Figure> > &obj, int pos);


#endif // !_COMMANDS_H