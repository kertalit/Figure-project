#include "ConsoleDataProvider.h"

ConsoleDataProvider::~ConsoleDataProvider()
{

}

int ConsoleDataProvider::rdInt()
{
    int val = 0;
    std::cin >> val;
    return val;
}

std::string ConsoleDataProvider::rdString()
{
    std::string line = "";
    std::cin >> line;
    return line;
}

Point2d ConsoleDataProvider::rdPoint2d()
{
    Point2d point;
    std::cin >> point;

    return point;
}

double ConsoleDataProvider::rdDouble()
{
    double val = 0.0;
    std::cin >> val;
    return val;
}

void ConsoleDataProvider::writeInt(const int number)
{
    std::cout << number << std::endl;
}

void ConsoleDataProvider::writePoint2d(const Point2d& point)
{
    std::cout << point << std::endl;
}

void ConsoleDataProvider::writeString(const std::string& line)
{
    std::cout << line << std::endl;
}

void ConsoleDataProvider::writeDouble(const double number)
{
    std::cout << number << std::endl;
}

void ConsoleDataProvider::printPoint2d(const Point2d& point)
{
    std::cout << point << std::endl;
}