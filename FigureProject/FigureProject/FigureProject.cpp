
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"
#include "Polilyne.h"
#include "Commands.h"
#include "ConsoleDataProvider.h"

int f(int x)
{
	int count = 0;
	while (x)
	{
		count++;

		x = x & (x - 1);
	}
	return count;
}

bool validDb(std::shared_ptr<Database> base)
{
	if (base == 0)
	{
		std::cout << "Database does not exist " << std::endl;
		return false;
	}
	else return true;

}

void testSaveDb()
{

	Database database("Figure1.txt");

	std::vector<std::shared_ptr<Figure>> figures = database.GetObjects();

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->print();
	}

	database.save("New Database.txt");

}

void testCreateDb()
{
	std::shared_ptr<Database> base = 0;

	std::string command = "";

	base = createDb();

	std::cout << base << std::endl;
}

void testListDb()
{
	listDb(std::make_shared<Database>("Figure1.txt"));
}

void testChoiceDb()
{
	std::vector<std::shared_ptr <Database> > bases;
	bases.push_back(std::make_shared<Database>("Figure1.txt"));
	bases.push_back(std::make_shared<Database>("New Database.txt"));

	std::shared_ptr<Database> currentBase = 0;

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
	int type = 0;
	std::cin >> type;

	createObj(type)->print();

}

void testLoadDb()
{
	std::shared_ptr<Database> base;
	base = loadDb();

	std::cout << "Database was loaded" << std::endl << std::endl;

	listDb(base);
}

void testChangeObj()
{
	std::vector<std::shared_ptr <Figure>> obj = std::make_shared<Database>("Figure1.txt")->GetObjects();

	changeObj(obj[1]);
}

void testSearchId()
{
	std::vector<std::shared_ptr <Figure>> obj = std::make_shared<Database>("Figure1.txt")->GetObjects();
	int number = 102;
	int bad = 10;
	int result = searchId(obj, number);
	
	std::cout << "Number found obj: " << result << std::endl;

	int result2 = searchId(obj, bad);

	std::cout << "Number found obj: " << result2 << std::endl;

}

void testPrintDb()
{
	Database base("Figure1.txt");

	base.print();
}

void testCreateRec()
{
	ConsoleDataProvider console;
	Database* p = 0;
	std::shared_ptr<Database> pBase(p);
	while (true)
	{
		if (!validDb(pBase))
			continue;

			std::shared_ptr<Figure> obj = createObj(Polilyne::type);
			obj->read(console);
			pBase->addObj(obj);

			std::cout << "Polilyne was created" << std::endl;

			pBase->print();
	}
}

void testDeleteFigure()
{
	Database base("Figure1.txt");
	std::vector<std::shared_ptr <Figure>> obj = base.GetObjects();

	//std::vector<std::shared_ptr <Figure>> jbo = obj;

	for (int i = 0; i < obj.size(); i++)
	{
		obj[i]->print();
	}

	std::cout << std::endl;

	/*for (int i = 0; i < jbo.size(); i++)
	{
		jbo[i]->print();
	}*/

	std::cout << std::endl;

	std::cout << "deleteFigure" << std::endl;

	deleteFigure(obj, 3);

	for (int i = 0; i < obj.size(); i++)
	{
		obj[i]->print();
	}

	std::cout << std::endl;

	/*for (int i = 0; i < jbo.size(); i++)
	{
		jbo[i]->print();
	}*/

}




void UI()
{
	std::shared_ptr<Database> currentBase = 0;
	std::vector<std::shared_ptr<Database>> bases;
	ConsoleDataProvider console;

	std::string command = "";

	std::cout << "Available commands:" << std::endl << std::endl;
	std::cout << "createDb" << std::endl;
	std::cout << "saveDb" << std::endl;
	std::cout << "loadDb" << std::endl;
	std::cout << "createRectangle" << std::endl;
	std::cout << "createCircle" << std::endl;
	std::cout << "createPolilyne" << std::endl;
	std::cout << "printDb" << std::endl;
	std::cout << "changeObj" << std::endl;
	std::cout << "choiceDb" << std::endl;
	std::cout << "Exit" << std::endl;

	while (true)
	{
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

		else if (command == "createRectangle")
		{
			if (!validDb(currentBase))
				continue;

				std::shared_ptr<Figure> obj = createObj(Rectangle::type);
				obj->read(console);
				currentBase->addObj(obj);

				std::cout << "Rectangle was created" << std::endl;
		}
		else if (command == "createCircle")
		{
			if (!validDb(currentBase))
				continue;

				std::shared_ptr<Figure> obj = createObj(Circle::type);
				obj->read(console);
				currentBase->addObj(obj);

				std::cout << "Circle was created" << std::endl;
		}
		else if (command == "createPolilyne")
		{
			if (!validDb(currentBase))
				continue;

				std::shared_ptr<Figure> obj = createObj(Polilyne::type);
				obj->read(console);
				currentBase->addObj(obj);

				std::cout << "Polilyne was created" << std::endl;
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

				std::vector<std::shared_ptr<Figure>> listDb = currentBase->GetObjects();
				
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
	//testListObj();
	//testCreateDb();
	//testChoiceDb();
	//testCreateObj();
	//testLoadDb();
	//testChangeObj();
	//testSearchId();
	//testPrintDb();
	//testCreateRec();
	testDeleteFigure();
	//UI();

	
}