#include "DataProvider.h"

DataProvider::DataProvider(std::ifstream& file, const std::string& path)
{
	inFile.open(path);

	if (inFile.is_open())
		std::cout << "File is open" << std::endl;
	else
		std::cout << "File is not open" << std::endl;
}

DataProvider::DataProvider(std::ofstream& file, const std::string& path)
{
	outFile.open(path);

	if (outFile.is_open())
		std::cout << "File is open" << std::endl;
	else
		std::cout << "File is not open" << std::endl;
}

DataProvider::~DataProvider() //обсудить с Женей
{
	outFile.close();
	std::cout << "File is closed" << std::endl;
	inFile.close();
	std::cout << "File is closed" << std::endl;
}

	int DataProvider::rdInt()
	{
		int number = 0;
		inFile >> number;
		return number;
	}

	std::string DataProvider::rdString()  
	{
		std::string stringLine = "";
		inFile >> stringLine;
		return stringLine;

	}

	Point2d DataProvider::rdPoint2d() 
	{
		double x = 0.0;
		double y = 0.0;
		inFile >> x;
		inFile >> y;

		return Point2d(x, y);
	}

	double DataProvider::rdDouble() 
	{
		double point = 0.0;
		inFile >> point;
		return point;
	}

	void DataProvider::writeInt(const int number)
	{
		outFile << number << std::endl;
	}

	void DataProvider::writePoint2d(const Point2d& point) 
	{
		outFile << point << std::endl;
	}

	void DataProvider::writeString(const std::string line) 
	{
		outFile << line << std::endl;
	}

	void DataProvider::writeDouble(const double number) 
	{
		outFile << number << std::endl;
	}

	void DataProvider::printPoint2d(const Point2d& point)
	{
		std::cout << point << std::endl;
	}
