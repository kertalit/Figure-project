#ifndef _COMMANDS_H
#define _COMMANDS_H

#include "Platform.h"
#include "Database.h"
#include "FileDataProvider.h"
#include "DataProvider.h"
#include <memory>



FigurePtr FIGURE_API createObj(size_t type);


void FIGURE_API saveDb(DatabasePtr base);

DatabasePtr FIGURE_API loadDb();

DatabasePtr FIGURE_API createDb();

void FIGURE_API changeObj(FigurePtr obj);

void FIGURE_API listDb(DatabasePtr base);

int FIGURE_API searchId(const std::vector<FigurePtr>& obj, size_t key);



#endif // !_COMMANDS_H