#include "Commands.h"
#include "Database.h"





		Figure* createObj(int type)
		{
			Figure* obj = 0;

			switch (type)
			{
			case Circle::type:
			{
				obj = new Circle();
				break;
			}
			case Rectangle::type:
			{
				obj = new Rectangle();
				break;
			}
			case Polilyne::type:
			{
				obj = new Polilyne();
				break;
			}
			default:
				throw std::exception("Wrong format");
			}

			return obj;
		}

		Database* createDb()
		{
			Database* base = new Database();
			std::cout << "Database was created" << std::endl;

			return base;
		}

		void saveDb(Database* base)
		{
			std::string path = " ";

			std::cout << "Enter path to Database" << std::endl;
			
			std::cin >> path;

			base->save(path);
			
			std::cout << "The database is saved and available on the path: " << path << std::endl;
		}

		Database* loadDb()
		{
			std::string path = " ";

			std::cout << "Enter path to Database" << std::endl;

			std::cin >> path;
			
			Database* base = new Database(path);

			return base;
		}

		void saveObj(Database& base, std::vector<Figure*>& obj)
		{
			base.addObj(obj);
			obj.clear();
			std::cout << "All created objects have been added" << std::endl;
		}
