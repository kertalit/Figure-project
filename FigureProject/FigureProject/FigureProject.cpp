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
	
	point2d()
	{
		x = 0.0;
		y = 0.0;

	}
	point2d(double x, double y)
		:x(x), y(y)
	{
	
	}

	void print()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
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
	double x = 0.0;
	double y = 0.0;
	file >> x;
	file >> y;
	point2d point(x, y);

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
	void virtual print() = 0;

};

class Circle : public Figure
{
	int idCirle = 0;
	std::string	nCircle = "";
	point2d p2dCircle;
	double rCircle = 0.0;
	
public:

	void read(std::ifstream& file) override
	{
		idCirle = rdInt(file);
		nCircle = rdString(file);
		p2dCircle = rdPoint2d(file);
		rCircle = rdDouble(file);

	}

	void print() override
	{
		std::cout << idCirle << std::endl;
		std::cout << nCircle << std::endl;
		p2dCircle.print();
		std::cout << rCircle << std::endl;

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

	void print() override
	{

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

			if (file.is_open())
				std::cout << "File is open";
			else
				std::cout << "File is not open";

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

	void print(std::vector<Figure*> test)
	{
		for (int i = 0; i < test.size(); i++)
		{
			*test[i];

			

		}
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


int main()
{
	
	std::ifstream file;
	file.open("Figure1.txt");
	Circle obj;
	
	obj.read(file);
	obj.print();
	
}