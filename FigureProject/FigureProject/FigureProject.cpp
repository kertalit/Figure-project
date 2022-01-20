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

	void write(std::ofstream& oFile)
	{
		oFile << x << std::endl;
		oFile << y << std::endl;
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
	void virtual write(std::ofstream& file) = 0;
	int virtual getType() = 0;

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

	void write(std::ofstream& file) override
	{
		file << Circle::getType() << std::endl;
		file << idCirle << std::endl;
		file << nCircle << std::endl;
		p2dCircle.write(file);
		file << rCircle << std::endl;
	}

	int getType() override
	{
		int type = 1;
		return type;
	}
};

class Rectangle : public Figure
{
	int idRectangle = 0;
	std::string	nRectangle = "";
	point2d p2dRectangle;
	double lRectangle = 0.0;
	double wRectangle = 0.0;

	void read(std::ifstream& file) override
	{
		idRectangle = rdInt(file);
		nRectangle = rdString(file);
		p2dRectangle = rdPoint2d(file);
		lRectangle = rdDouble(file);
		wRectangle = rdDouble(file);
	}

	void print() override
	{
		std::cout << idRectangle << std::endl;
		std::cout << nRectangle << std::endl;
		p2dRectangle.print();
		std::cout << lRectangle << std::endl;
		std::cout << wRectangle << std::endl;
	}

	void write(std::ofstream& file) override
	{
		file << Rectangle::getType() << std::endl;
		file << idRectangle << std::endl;
		file << nRectangle << std::endl;
		p2dRectangle.write(file);
		file << lRectangle << std::endl;
		file << wRectangle << std::endl;
	}

	int getType() override
	{
		int type = 2;
		return type;
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
				std::cout << "File is open" << std::endl;
			else
				std::cout << "File is not open" << std::endl;

			rdFile(file);
		}

		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
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
	
	std::vector<Figure*> GetObjects() const
	{
		return figures;
	}
	
	void wFile(std::vector<Figure*> objects, const std::string& path)
	{
		std::ofstream wFile(path);
		wFile << objects.size() << std::endl;
		
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->write(wFile);
		}

	}



private:

	std::vector<Figure*> figures;

	void rdFile(std::ifstream& file)
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
					throw std::exception ("Wrong format");
				}
			
			obj->read(file);
			figures.push_back(obj);
			
		}


	}

};



int main()
{
	DataBase test("Figure1.txt");

	for (int i = 0; i < test.GetObjects().size(); i++)
	{
		test.GetObjects()[i]->print();
	}
	
	test.wFile(test.GetObjects(), "New Database.txt");
	
}