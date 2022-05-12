#include "Point2d.h"


	Point2d::Point2d()
		:x(0.0), y(0.0)
	{

	}

	Point2d::Point2d(double x, double y)
		:x(x), y(y)
	{

	}

	
	std::ostream& operator<<(std::ostream& file, const Point2d& point)
	{
		file << point.x << std::endl;
		file << point.y;

		return file;
	}

	std::istream& operator>> (std::istream& file, Point2d& point)
	{
		file >> point.x >> point.y;

		return file;
	}