
#include "DataProvider.h"
#include "Figure.h"
#include "Point2d.h"
#include "Database.h"
#include "Polilyne.h"
#include "Commands.h"
#include "ConsoleDataProvider.h"

void testWriteDb()
{

	Database database("Figure1.txt");

	std::vector<Figure*> figures = database.GetObjects();

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->print();
	}

	database.save("New Database.txt");

}

void testCreateDb()
{
	Database* base = 0;

	std::string command = "";

	while (true)
	{
		std::cin >> command;

		if (command == "createDb")
		{
			base = createDb();
		}

		if (command == "Exit")
			break;
	}

	std::cout << base << std::endl;
}

void testListObj()
{
	Database database("Figure1.txt");
	listObj(&database);
}

void testChoiceDb()
{
	Database base("Figure1.txt");
	Database base1("New Database.txt");
	std::vector<Database*> bases;
	bases.push_back(&base);
	bases.push_back(&base1);

	Database* currentBase = 0;

	int number;


	for (int i = 0; i < bases.size(); i++)
	{
		std::cout << std::endl;
		std::cout << "Base # " << i + 1 << std::endl << std::endl;
		listObj(bases[i]);
	}

	std::cout << "Enter the number of the shape (1,2,3...) you want to change " << std::endl;
	std::cin >> number;

	currentBase = bases[number - 1];

	currentBase->print();
}






void UI()
{
	Database* currentBase = 0;
	std::vector<Database*> bases;

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
	std::cout << "changeDb" << std::endl;
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
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				saveDb(currentBase);
			}
		}

		else if (command == "loadDb")
		{
			currentBase = loadDb();

			std::cout << "Database was loaded" << std::endl;

		}

		else if (command == "createRectangle")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				Figure* obj = createObj(Rectangle::type);
				currentBase->addObj(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}
		else if (command == "createCircle")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				Figure* obj = createObj(Circle::type);
				currentBase->addObj(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}
		else if (command == "createPolilyne")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				Figure* obj = createObj(Polilyne::type);
				currentBase->addObj(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}

		else if (command == "printDb")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				currentBase->print();
			}
		}
		else if (command == "changeObj")
		{
			if (currentBase == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				int number = 0;
				int index = 0;

				listDb(currentBase);
				
				std::cout << std::endl;

				std::cout << "Enter the ID of the figure (1,2,3...) you want to change " << std::endl;
				std::cin >> number;

				std::vector<Figure*> listDb = currentBase->GetObjects();
				
				index = serchId(listDb, number);

				if (index == -1)
				{
					std::cout << "Id does not found" << std::endl;
				}
				else
				{
					changeObj(listDb[index + 1]);
				}
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

			}
		}

		else if (command == "Exit")
		{
			return;
		}
	}
}


int main()
{
	//testWriteDb();
	//testListObj();
	
	//UI();
	
}