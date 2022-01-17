#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <exception>


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

		try
		{
			std::ifstream file;
			file.open(path);
			rdFile(file);
		}
		catch (const std::exception& ex)
		{
			ex.what();
			for (int i = 0; i < figures.size(); i++)
			{
				delete figures[i];
			}
		}
		
	}

	~DataBase()
	{
		for (int i = 0; i < figures.size(); i++)
		{
			delete figures[i];
		}
	}
	
	std::vector<Figure*> GetObject() const
	{
		return figures;
	}

private:

	std::vector<Figure*> figures;

	int rdFile(std::ifstream& file)
	{
		int objectCount = rdInt(file);

		figures.reserve(objectCount);

		for (int i = 0; i < objectCount; i++)
		{
			int type = rdInt(file);

			Figure* obj = 0;

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
					throw std::exception("Wrong format");
				}
			
			obj->read(file);
			figures.push_back(obj);
			
		}


	}
	

};
	