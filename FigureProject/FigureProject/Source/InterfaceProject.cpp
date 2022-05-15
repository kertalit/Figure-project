#include "InterfaceProject.h"

DatabasePtr createDb()
{
  std::cout << "Database was created" << std::endl;
  return std::make_shared<Database>();
}

void saveDb(DatabasePtr base)
{
  std::string path = " ";
  std::cout << "Enter path to Database" << std::endl;

  std::cin >> path;
  base->save(path);
  std::cout << "The database is saved and available on the path: " << path << std::endl;
}

DatabasePtr loadDb()
{
  std::string path = " ";
  std::cout << "Enter path to Database" << std::endl;
  std::cin >> path;

  return std::make_shared<Database>(path);
}

void changeObj(FigurePtr obj)
{
  std::string param = "";
  std::cout << "Enter name parameter who you want to change \n 1. name \n 2. others" << std::endl;
  std::cin >> param;

  if (param == "name")
  {
    std::string newName;
    std::cout << "Enter new name" << std::endl;
    std::cin >> newName;

    obj->setName(newName);
    std::cout << "Name changed to " << newName << std::endl;
  }

  else switch (obj->getType())
  {
  case Circle::type:
  {
    std::shared_ptr<Circle> pCircle = std::static_pointer_cast<Circle>(obj);
    std::cout << "Enter name parameter who you want to change: 'point' 'radius' " << std::endl;

    std::cin >> param;

    if (param == "point")
    {
      Point2d newPoint;
      std::cout << "Enter new point" << std::endl;
      std::cin >> newPoint;
      pCircle->setPoint(newPoint);

      std::cout << "Point changed to " << newPoint << std::endl;
    }

    else if (param == "radius")
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
    std::cout << "Enter name parametr who you want to change: 'point' 'length' 'width' " << std::endl;

    std::cin >> param;

    if (param == "point")
    {
      Point2d newPoint;
      std::cout << "Enter new point" << std::endl;
      std::cin >> newPoint;
      pRectangle->setPoint(newPoint);

      std::cout << "Point changed to " << newPoint << std::endl;
    }

    else if (param == "length")
    {
      double newLength;
      std::cout << "Enter new length" << std::endl;
      std::cin >> newLength;
      pRectangle->setLength(newLength);

      std::cout << "Length changed to " << newLength << std::endl;
    }

    else if (param == "width")
    {
      double newWidth;
      std::cout << "Enter new width" << std::endl;
      std::cin >> newWidth;
      pRectangle->setLength(newWidth);

      std::cout << "Width changed to " << newWidth << std::endl;
    }
    break;
  }
  case Polyline::type:
  {
    std::shared_ptr<Polyline> pPolilyne = std::static_pointer_cast<Polyline>(obj);
    std::cout << "Enter name parametr who you want to change: 'points' " << std::endl;

    std::cin >> param;

    if (param == "points")
    {
      std::cout << "Which point do you want to change? (1,2,3...)" << std::endl;
      int number;
      std::cin >> number;

      std::cout << "Enter new point" << std::endl;
      Point2d point;
      std::cin >> point;

      std::cout << std::endl;

      pPolilyne->setPoint(point, number);
      std::cout << "Point changed to " << point << std::endl;
    }
    break;
  }
  default:
    break;
  }
}

void listDb(DatabasePtr base)
{
  std::vector<FigurePtr> obj = base->GetObjects();

  for (size_t i = 0; i < obj.size(); i++)
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
    case Polyline::type:
    {
      std::cout << "Polyline ";
      break;
    }
    default:
      break;
    }

    obj[i]->Figure::print();
    std::cout << std::endl;
  }
}