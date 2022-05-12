
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"
#include "Polilyne.h"
#include "Commands.h"
#include "ConsoleDataProvider.h"


bool validDb(DatabasePtr base)
{
	if (base == 0)
	{
		std::cout << "Database does not exist " << std::endl;
		return false;
	}
	return true;
}

void testSaveDb()
{

	Database database("Figure1.txt");

	std::vector<FigurePtr> figures = database.GetObjects();

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->print();
	}

	database.save("New Database.txt");

}

void testCreateDb()
{
	DatabasePtr base = 0;

	base = createDb();

	std::cout << base << std::endl;
}

void testListDb()
{
	listDb(std::make_shared<Database>("Figure1.txt"));
}

void testChoiceDb()
{
	std::vector<DatabasePtr> bases;
	bases.push_back(std::make_shared<Database>("Figure1.txt"));
	bases.push_back(std::make_shared<Database>("New Database.txt"));

	DatabasePtr currentBase = 0;

	int number;


	for (int i = 0; i < bases.size(); i++)
	{
		std::cout << std::endl;
		std::cout << "Base # " << i + 1 << std::endl << std::endl;
		listDb(bases[i]);
	}

	std::cout << "Enter the number of the base (1,2,3...) you want to change " << std::endl;
	std::cin >> number;

	currentBase = bases[number - 1];

	std::cout << "Current base:" << std::endl;

	currentBase->print();
}

void testCreateObj()
{
	std::cout << "Circle: " << std::endl;
	createObj(1)->print();

	std::cout << "Rectangle: " << std::endl;
	createObj(2)->print();

	std::cout << "Polilyne: " << std::endl;
	createObj(3)->print();
}

void testLoadDb()
{
	DatabasePtr base;
	base = loadDb();

	std::cout << "Database was loaded" << std::endl << std::endl;

	listDb(base);
}

void testChangeObj()
{
	Database base("Figure1.txt");

	std::vector<FigurePtr> obj = base.GetObjects();

	obj[1]->print();

	changeObj(obj[1]);

	base.print();
	
}

void testSearchId()
{
	std::vector<FigurePtr> obj = std::make_shared<Database>("Figure1.txt")->GetObjects();
	int number = 102;
	int bad_number = 10;
	int result = searchId(obj, number);
	
	std::cout << "Number found obj: " << result << std::endl;

	int result2 = searchId(obj, bad_number);

	std::cout << "Number found obj: " << result2 << std::endl;

}

void testPrintDb()
{
	Database base("Figure1.txt");

	base.print();
}

void testCreateFigure()
{
	ConsoleDataProvider console;

	auto pBase = std::make_shared<Database>();

			FigurePtr obj = createObj(Rectangle::type);
			obj->read(console);
			pBase->addObj(obj);

			std::cout << "Rectangle was created" << std::endl;

			pBase->print();
}

void testDeleteFigure()
{
	Database one("Figure1.txt");

	one.print();

	std::cout << std::endl;

	std::cout << "deleteFigure" << std::endl << std::endl;

	one.deleteFigure(101);

	one.print();

	std::cout << std::endl;

	std::cout << "deleteFigure" << std::endl << std::endl;

	one.deleteFigure(50);


	std::cout << std::endl;

	}




void UI()
{
	std::shared_ptr<Database> currentBase = 0;
	std::vector<DatabasePtr> bases;
	ConsoleDataProvider console;

	std::string command = "";

	std::cout << "Available commands:" << std::endl << std::endl;
	std::cout << "createDb" << std::endl;
	std::cout << "saveDb" << std::endl;
	std::cout << "loadDb" << std::endl;
	std::cout << "createFigure" << std::endl;
	std::cout << "printDb" << std::endl;
	std::cout << "changeObj" << std::endl;
	std::cout << "choiceDb" << std::endl;
	std::cout << "deleteFigure" << std::endl;
	std::cout << "Exit" << std::endl;

	while (true)
	{
		std::cout << "Enter command" << std::endl;
		std::cin >> command;

		if (command == "createDb")
		{
			currentBase = createDb();
			bases.push_back(currentBase);
		}

		else if (command == "saveDb")
		{
			if (!validDb(currentBase))
				continue;
			
				saveDb(currentBase);
		}

		else if (command == "loadDb")
		{
			currentBase = loadDb();
			bases.push_back(currentBase);

			std::cout << "Database was loaded" << std::endl;

		}

		else if (command == "createFigure")
		{
			if (!validDb(currentBase))
				continue;

			std::cout << "What figure to create?" << std::endl;
			std::cout << "Enter '1' for Circle" << std::endl;
			std::cout << "Enter '2' for Rectangle" << std::endl;
			std::cout << "Enter '3' for Polilyne" << std::endl;

			size_t type;
			std::cin >> type;

				FigurePtr obj = createObj(type);
				obj->read(console);
				currentBase->addObj(obj);

				std::cout << "Figure was created" << std::endl;
		}

		else if (command == "printDb")
		{
			if (!validDb(currentBase))
				continue;

				currentBase->print();
		}
		else if (command == "changeObj")
		{
			if (!validDb(currentBase))
				continue;

				int number = 0;
				int index = 0;

				listDb(currentBase);
				
				std::cout << std::endl;

				std::cout << "Enter the ID of the figure (1,2,3...) you want to change " << std::endl;
				std::cin >> number;

				std::vector<FigurePtr> listDb = currentBase->GetObjects();
				
				index = searchId(listDb, number);

				if (index == false)
				{
					std::cout << "ID does not found" << std::endl;
				}
				else
				{
					changeObj(listDb[index + 1]);
				}
		}

		else if (command == "choiceDb")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				int number;

				for (int i = 0; i < bases.size(); i++)
				{
					std::cout << std::endl;
					std::cout << "Base # " << i + 1 << std::endl << std::endl;
					listDb(bases[i]);
				}

				std::cout << "Enter the number of the shape (1,2,3...) you want to change " << std::endl;
				std::cin >> number;

				currentBase = bases[number - 1];
				std::cout << "Current base was changed" << std::endl;

			}
		}
		else if (command == "deleteFigure")
		{
			if (!validDb(currentBase))
			continue;
			
			std::cout << "Enter id figure" << std::endl;
			size_t number;
			std::cin >> number;

			currentBase->deleteFigure(number);

		}

		else if (command == "Exit")
		{
		if (validDb(currentBase))
		{
			std::string choice = "";
			std::cout << "Do you want to keep your current base? yes / no" << std::endl;
			std::cin >> choice;

			if (choice == "yes")
			{
				std::string path;
				std::cout << "Enter path to save" << std::endl;
				std::cin >> path;

				currentBase->save(path);
			}
			else return;
		}
		else return;
		}
	}
}



int main()
{
	//testWriteDb();
	//testListDb();
	//testCreateDb();
	//testChoiceDb();
	//testCreateObj();
	//testLoadDb();
	//testChangeObj();
	//testSearchId();
	//testPrintDb();
	//testCreateFigure();
	//testDeleteFigure();
	UI();

}