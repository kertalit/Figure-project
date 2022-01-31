
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"
#include "Polilyne.h"



int main()
{
	Database database("Figure1.txt");

	std::vector<Figure*> figures = database.GetObjects();

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->print();
	}
	
	database.Write(database.GetObjects(), "New Database.txt");

}