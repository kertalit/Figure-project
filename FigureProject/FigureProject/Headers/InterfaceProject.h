#ifndef __INTERFACE_PROJECT
#define __INTERFACE_PROJECT

#include "Database.h"

#include <memory>


void saveDb(DatabasePtr base);

DatabasePtr loadDb();

DatabasePtr createDb();

void changeObj(FigurePtr obj);

void listDb(DatabasePtr base);




#endif // !__INTERFACE_PROJECT
