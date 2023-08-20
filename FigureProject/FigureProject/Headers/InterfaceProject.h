#ifndef __INTERFACE_PROJECT
#define __INTERFACE_PROJECT

#include "Database.h"
#include "FileDataProvider.h"

#include <memory>


void saveDb(DatabasePtr base);

DatabasePtr loadDb();

DatabasePtr createDb();

void changeObj(ObjectPtr obj);

void listDb(DatabasePtr base);




#endif // !__INTERFACE_PROJECT
