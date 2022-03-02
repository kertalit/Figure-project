
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


void UI()
{
	std::vector<Figure*> figures;
	Figure* obj;

	Database* base = 0;

	std::string command = "";

	std::cout << "Available commands:" << std::endl << std::endl;
	std::cout << "createDb" << std::endl;
	std::cout << "saveDb" << std::endl;
	std::cout << "loadDb" << std::endl;
	std::cout << "createRectangle" << std::endl;
	std::cout << "createCircle" << std::endl;
	std::cout << "createPolilyne" << std::endl;
	std::cout << "saveObj" << std::endl;
	std::cout << "printDb" << std::endl;
	std::cout << "changeObj" << std::endl;
	std::cout << "Exit" << std::endl;

	while (true)
	{
		std::cin >> command;

		if (command == "createDb")
		{
			base = createDb();
		}

		else if (command == "saveDb")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				saveDb(base);
			}
		}

		else if (command == "loadDb")
		{
			base = loadDb();

			std::cout << "Database was loaded" << std::endl;
			
		}

		else if (command == "createRectangle")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				obj = createObj(Rectangle::type);
				figures.push_back(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}
		else if (command == "createCircle")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				obj = createObj(Circle::type);
				figures.push_back(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}
		else if (command == "createPolilyne")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				obj = createObj(Polilyne::type);
				figures.push_back(obj);

				std::cout << "Rectangle was created" << std::endl;
			}
		}


		else if (command == "saveObj")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				saveObj(*base, figures);
			}
		}

		else if (command == "printDb")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				base->printDb();
			}
		}
		else if (command == "changeObj")
		{
			if (base == 0)
			{
				std::cout << "Database does not exist " << std::endl;
			}
			else
			{
				int number;
				base->printDb();
				std::cout << std::endl;

				std::cout << "Enter the number of the shape (1,2,3...) you want to change " << std::endl;
				std::cin >> number;

				std::vector<Figure*> listObj = base->GetObjects();

				listObj[number]->change();

				base->setObjects(listObj);
			}
		}
		else if (command == "Exit")
		{
			return;
		}
	}
}

void change2(Figure* obj)
{
	switch (obj->getType())
	{
	case Circle::type:
	{
		Circle* pcircle = static_cast<Circle*> (obj);
		std::string parametr = "";
		std::cout << "Enter name parametr who you want to change: 'id' 'name' 'point' 'radius' " << std::endl;

		std::cin >> parametr;

		if (parametr == "id")
		{
			int newId;
			std::cout << "Enter new id" << std::endl;
			std::cin >> newId;
			pcircle->setId(newId);

			std::cout << "Id changed to " << newId << std::endl;
		}

		else if (parametr == "name")
		{
			std::string newName;
			std::cout << "Enter new name" << std::endl;
			std::cin >> newName;
			obj->setName(newName);

			std::cout << "Name changed to " << newName << std::endl;
		}

		else if (parametr == "point")
		{
			Point2d newPoint;
			std::cout << "Enter new point" << std::endl;
			std::cin >> newPoint;
			obj->setPoint(newPoint);

			std::cout << "Point changed to " << newPoint << std::endl;
		}

		else if (parametr == "radius")
		{
			double newRadius;
			std::cout << "Enter new radius" << std::endl;
			std::cin >> newRadius;
			setRadius(newRadius);

			std::cout << "Radius changed to " << newRadius << std::endl;
		}
		break;
	}
	default:
		break;
	}
}


int main()
{
	//testWriteDb();

	UI();
}