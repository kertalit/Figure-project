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
	std::string stringLine = "";
	std::cin >> stringLine;
	return stringLine;

}

Point2d ConsoleDataProvider::rdPoint2d()
{
	double x = 0.0;
	double y = 0.0;
	std::cin >> x;
	std::cin >> y;

	return Point2d(x, y);
}

double ConsoleDataProvider::rdDouble()
{
	double point = 0.0;
	std::cin >> point;
	return point;
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
