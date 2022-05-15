#include "ConsoleDataProvider.h"


ConsoleDataProvider::ConsoleDataProvider()
{
	
}

ConsoleDataProvider::~ConsoleDataProvider()
{

}

int ConsoleDataProvider::rdInt()
{
	int number = 0;
	std::cin >> number;
	return number;
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
	std::cin >> point.x >> point.y;

	return point;
}

double ConsoleDataProvider::rdDouble()
{
	double number = 0.0;
	std::cin >> number;
	return number;
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