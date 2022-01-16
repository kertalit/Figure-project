#include <fstream>
#include <string>
#include <iostream>
#include <vector>


class point2d
{
public:
	double x;
	double y;
	
	point2d(double x, double y)
		:x(0.0), y(0.0)
	{

	}

};

int rdInt(std::ifstream& file)
{
	int number = 0;
	file >> number;
	return number;
}
std::string rdString(std::ifstream& file)
{
	std::string stringLine = "";
	file >> stringLine;
	return stringLine;

}
point2d rdPoint2d(std::ifstream& file)
{
	double x;
	double y;
	point2d point(x, y);

	file >> x;
	file >> y;

	return point;
}
double rdDouble(std::ifstream& file)
{
	double point = 0.0;
	file >> point;
	return point;
}


class Figure
{
public:
	void virtual read(std::ifstream& file) = 0;

};

class Circle : public Figure
{

	void read(std::ifstream& file) override
	{
		int idCirle = rdInt(file);
		std::string	nCircle = rdString(file);
		point2d p2dCircle = rdPoint2d(file);
		double rCircle = rdDouble(file);
	}
};

class Rectangle : public Figure
{

	void read(std::ifstream& file) override
	{
		int idRectangle = rdInt(file);
		std::string	nRectangle = rdString(file);
		point2d p2dRectangle = rdPoint2d(file);
		double lRectangle = rdDouble(file);
		double wRectangle = rdDouble(file);
	}
};


class DataBase
{
	
public:
	DataBase(const std::string& path)
	{
		std::ifstream file;
		file.open(path);

		rdFile(file);
	}

	~DataBase()
	{

	}
	
	std::vector<Figure*> GetObject() const;

private:

	std::vector<Figure*> figures;

	void rdFile(std::ifstream& file)
	{
		int objectCount = rdInt(file);

		figures.reserve(objectCount);

		for (int i = 0; i < objectCount; i++)
		{
			int type = rdInt(file);

			Figure* obj;

			switch (type) 
			{
			case 1:
			{
				obj = new Circle();
				break; 
			}
			case 2:
			{
				obj = new Rectangle();
				break;
			}
			default:
				throw std::exception();
			}

			obj->read(file);
			figures.push_back(obj);

		}


	}

};
	