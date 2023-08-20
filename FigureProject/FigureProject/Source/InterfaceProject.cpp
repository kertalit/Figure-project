#include "InterfaceProject.h"

DatabasePtr createDb()
{
    std::cout << "Database was created" << std::endl;
    return std::make_shared<Database>();
}

void saveDb(DatabasePtr base)
{
    std::string path = "";
    std::cout << "Enter path to Database" << std::endl;

    std::cin >> path;
    base->save(path);
    std::cout << "The database is saved: " << path << std::endl;
}

DatabasePtr loadDb()
{
    std::string path = "";
    std::cout << "Enter path to Database" << std::endl;
    std::cin >> path;

    return std::make_shared<Database>(path);
}

void changeObj(ObjectPtr obj)
{
    std::cout << "Enter parameter to change \n name \n others" << std::endl;
    std::string param = "";
    std::cin >> param;

    if (param == "name")
    {
        std::cout << "Enter new name" << std::endl;
        std::string newName;
        std::cin >> newName;

        obj->setName(newName);
        std::cout << "Name changed to " << newName << std::endl;
    }

    else
    {
        switch (obj->getType())
        {
        case Circle::type:
        {
            CirclePtr pCircle = std::static_pointer_cast<Circle>(obj);
            std::cout << "Enter parameter to change: 'point' 'radius' " << std::endl;

            std::cin >> param;

            if (param == "point")
            {
                std::cout << "Enter new point" << std::endl;
                Point2d newPoint;
                std::cin >> newPoint;

                pCircle->setPoint(newPoint);

                std::cout << "Point changed to " << newPoint << std::endl;
            }

            else if (param == "radius")
            {
                std::cout << "Enter new radius" << std::endl;
                double newRadius;
                std::cin >> newRadius;

                pCircle->setRadius(newRadius);

                std::cout << "Radius changed to " << newRadius << std::endl;
            }
            break;
        }
        case Rectangle::type:
        {
            RectanglePtr pRectangle = std::static_pointer_cast<Rectangle>(obj);
            std::cout << "Enter parameter to change: 'point' 'length' 'width' " << std::endl;

            std::cin >> param;

            if (param == "point")
            {
                std::cout << "Enter new point" << std::endl;
                Point2d newPoint;
                std::cin >> newPoint;

                pRectangle->setPoint(newPoint);

                std::cout << "Point changed to " << newPoint << std::endl;
            }

            else if (param == "length")
            {
                std::cout << "Enter new length" << std::endl;
                double newLength;
                std::cin >> newLength;

                pRectangle->setLength(newLength);

                std::cout << "Length changed to " << newLength << std::endl;
            }

            else if (param == "width")
            {
                std::cout << "Enter new width" << std::endl;
                double newWidth;
                std::cin >> newWidth;

                pRectangle->setLength(newWidth);

                std::cout << "Width changed to " << newWidth << std::endl;
            }
            break;
        }
        case Polyline::type:
        {
            PolylinePtr pPolyline = std::static_pointer_cast<Polyline>(obj);
            std::cout << "Enter parameter to change: 'points' " << std::endl;

            std::cin >> param;

            if (param == "points")
            {
                std::cout << "Which point to change? (1,2,3...)" << std::endl;
                int number;
                std::cin >> number;

                std::cout << "Enter new point" << std::endl;
                Point2d point;
                std::cin >> point;

                std::cout << std::endl;

                pPolyline->setPoint(point, number);
                std::cout << "Point changed to " << point << std::endl;
            }
            break;
        }
        default:
            break;
        }
    }
}

void listDb(DatabasePtr base)
{
    std::vector<ObjectPtr> figures = base->GetObjects();

    for (auto& obj : figures)
    {
        switch (obj->getType())
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

        ConsoleDataProvider console;
        obj->Object::writeTo(console);
        std::cout << std::endl;
    }
}