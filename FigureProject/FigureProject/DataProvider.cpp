#include "DataProvider.h"


	int DataProvider::rdInt(std::ifstream & file)
	{
		int number = 0;
		file >> number;
		return number;
	}

	std::string DataProvider::rdString(std::ifstream& file)
	{
		std::string stringLine = "";
		file >> stringLine;
		return stringLine;

	}

	Point2d DataProvider::rdPoint2d(std::ifstream& file)
	{
		double x = 0.0;
		double y = 0.0;
		file >> x;
		file >> y;

		return Point2d(x, y);
	}

	double DataProvider::rdDouble(std::ifstream& file)
	{
		double point = 0.0;
		file >> point;
		return point;
	}

	void DataProvider::writeInt(std::ofstream& file, int number)
	{
		file << number << std::endl;
	}

	void DataProvider::writePoint2d(std::ofstream& oFile, Point2d& point)
	{
		oFile << point.x << std::endl;
		oFile << point.y << std::endl;
	}

	void DataProvider::writeString(std::ofstream& file, std::string line)
	{
		file << line << std::endl;
	}

	void DataProvider::writeDouble(std::ofstream& file, double number)
	{
		file << number << std::endl;
	}

	void DataProvider::printPoint2d(Point2d point)
	{
		std::cout << point.x << std::endl;
		std::cout << point.y << std::endl;
	}
