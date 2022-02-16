
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"
#include "Polilyne.h"

void testWriteDb()
{

	Database database("Figure1.txt");

	std::vector<Figure*> figures = database.GetObjects();

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->print();
	}

	database.Write("New Database.txt");

}

int main()
{
	testWriteDb();

}