#include "Sample.h"
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

		Database createDb(const std::string& path)
		{
			Database base(path);

			return base;
		}

		void addObj(Figure* obj, Database& db)
		{
		

		}