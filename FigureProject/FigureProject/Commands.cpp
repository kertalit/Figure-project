
#include "Commands.h"

		std::shared_ptr<Figure> createObj(int type)
		{
			std::shared_ptr<Figure> obj = 0;

			switch (type)
			{
			case Circle::type:
			{
				obj = std::make_shared<Circle>();
				break;
			}
			case Rectangle::type:
			{
				obj = std::make_shared<Rectangle>();
				break;
			}
			case Polilyne::type:
			{
				obj = std::make_shared<Polilyne>();
				break;
			}
			default:
				throw std::exception("Wrong format");
			}

			return obj;
		}

		std::shared_ptr<Database> createDb()
		{
			
			std::cout << "Database was created" << std::endl;

			return std::make_shared<Database>();
		}

		void saveDb(std::shared_ptr<Database> base)
		{
			std::string path = " ";

			std::cout << "Enter path to Database" << std::endl;
			
			std::cin >> path;

			base->save(path);
			
			std::cout << "The database is saved and available on the path: " << path << std::endl;
		}

		std::shared_ptr<Database> loadDb()
		{
			std::string path = " ";

			std::cout << "Enter path to Database" << std::endl;

			std::cin >> path;

			return std::make_shared<Database>(path);
		}

		void changeObj(std::shared_ptr<Figure> obj)
		{
			switch (obj->getType())
			{
			case Circle::type:
			{
				std::shared_ptr<Circle> pCircle = std::static_pointer_cast<Circle>(obj);
				std::string parametr = "";
				std::cout << "Enter name parametr who you want to change: 'id' 'name' 'point' 'radius' " << std::endl;

				std::cin >> parametr;

				if (parametr == "id")
				{
					int newId;
					std::cout << "Enter new id" << std::endl;
					std::cin >> newId;
					pCircle->setId(newId);

					std::cout << "Id changed to " << newId << std::endl;
				}

				else if (parametr == "name")
				{
					std::string newName;
					std::cout << "Enter new name" << std::endl;
					std::cin >> newName;
					pCircle->setName(newName);

					std::cout << "Name changed to " << newName << std::endl;
				}

				else if (parametr == "point")
				{
					Point2d newPoint;
					std::cout << "Enter new point" << std::endl;
					std::cin >> newPoint;
					pCircle->setPoint(newPoint);

					std::cout << "Point changed to " << newPoint << std::endl;
				}

				else if (parametr == "radius")
				{
					double newRadius;
					std::cout << "Enter new radius" << std::endl;
					std::cin >> newRadius;
					pCircle->setRadius(newRadius);

					std::cout << "Radius changed to " << newRadius << std::endl;
				}
				break;
			}

			case Rectangle::type:
			{
				std::shared_ptr<Rectangle> pRectangle = std::static_pointer_cast<Rectangle>(obj);
				std::string parametr = "";
				std::cout << "Enter name parametr who you want to change: 'id' 'name' 'point' 'length' 'width' " << std::endl;

				std::cin >> parametr;

				if (parametr == "id")
				{
					int newId;
					std::cout << "Enter new id" << std::endl;
					std::cin >> newId;
					pRectangle->setId(newId);

					std::cout << "Id changed to " << newId << std::endl;
				}

				else if (parametr == "name")
				{
					std::string newName;
					std::cout << "Enter new name" << std::endl;
					std::cin >> newName;
					pRectangle->setName(newName);

					std::cout << "Name changed to " << newName << std::endl;
				}

				else if (parametr == "point")
				{
					Point2d newPoint;
					std::cout << "Enter new point" << std::endl;
					std::cin >> newPoint;
					pRectangle->setPoint(newPoint);

					std::cout << "Point changed to " << newPoint << std::endl;
				}

				else if (parametr == "length")
				{
					double newLength;
					std::cout << "Enter new length" << std::endl;
					std::cin >> newLength;
					pRectangle->setLength(newLength);

					std::cout << "Length changed to " << newLength << std::endl;
				}

				else if (parametr == "width")
				{
					double newWidth;
					std::cout << "Enter new width" << std::endl;
					std::cin >> newWidth;
					pRectangle->setLength(newWidth);

					std::cout << "Width changed to " << newWidth << std::endl;
				}
			}

			case Polilyne::type:
			{
				std::shared_ptr<Polilyne> pPolilyne = std::static_pointer_cast<Polilyne>(obj);
				std::string parametr = "";
				std::cout << "Enter name parametr who you want to change: 'id' 'name' 'points' " << std::endl;

				std::cin >> parametr;

				if (parametr == "id")
				{
					int newId;
					std::cout << "Enter new id" << std::endl;
					std::cin >> newId;
					pPolilyne->setId(newId);

					std::cout << "Id changed to " << newId << std::endl;
				}

				else if (parametr == "name")
				{
					std::string newName;
					std::cout << "Enter new name" << std::endl;
					std::cin >> newName;
					pPolilyne->setName(newName);

					std::cout << "Name changed to " << newName << std::endl;
				}

				else if (parametr == "points")
				{
					std::cout << "Which pair of point do you want to change? (1,2,3...)" << std::endl;
					int number;

					std::cin >> number;

					std::cout << "Enter new point" << std::endl;
					Point2d point;

					std::cin >> point.x >> point.y;
					std::cout << std::endl;

					pPolilyne->setPoint(point, number);
					std::cout << "Point changed to " << point << std::endl;
				}
			}
			default:
				break;
			}
		}

		void listDb(std::shared_ptr<Database> base)
		{
			std::vector<std::shared_ptr<Figure>> obj = base->GetObjects();

			for (int i = 0; i < obj.size(); i++)
			{
				switch (obj[i]->getType())
				{
				case Circle::type:
				{
					std::cout << "Circle ";
					break;
				}
				case Rectangle::type:
				{
					std::cout << "Rectangle ";
					break;
				}
				case Polilyne::type:
				{
					std::cout << "Polilyne ";
					break;
				}
				default:
					break;
				}

				obj[i]->Figure::print();

				std::cout << std::endl;
			}
		}

		int searchId(std::vector<std::shared_ptr<Figure> > obj, int key)
		{
			for (int i = 0; i < obj.size(); ++i)
			{
				if (key == obj[i]->getId())
				{
					return i;
					break;
				}
			}
			return 0;
		}

		void deleteFigure(std::vector < std::shared_ptr<Figure> > &obj, int pos)
		{
			auto itFigure = obj.begin();
			
			std::advance(itFigure, pos);
			obj.erase(itFigure);

			std::cout << "Objects number " << pos << " was deleted" <<	std::endl;

		}


