
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"



int main()
{
	Database test("Figure1.txt");

	for (int i = 0; i < test.GetObjects().size(); i++)
	{
		test.GetObjects()[i]->print();
	}
	
	test.wFile(test.GetObjects(), "New Database.txt");
	
}