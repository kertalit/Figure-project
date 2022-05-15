#ifndef __INTERFACE_PROJECT
#define __INTERFACE_PROJECT

#include "Commands.h"
#include "Database.h"
#include "FileDataProvider.h"
#include "DataProvider.h"
#include <memory>
#include "Point2d.h"



void saveDb(DatabasePtr base);

DatabasePtr loadDb();

DatabasePtr createDb();

void changeObj(FigurePtr obj);

void listDb(DatabasePtr base);




#endif // !__INTERFACE_PROJECT
