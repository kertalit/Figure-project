#include "Rectangle.h"


Rectangle::Rectangle(int id, std::string name, Point2d point, double length, double width)
	:id(0), name(""), point(0.0, 0.0), length(0.0), width(0.0)
{

}
Rectangle::Rectangle()
{

}
	void Rectangle::read(std::ifstream& file)  
	{
		id = dataprovider.rdInt(file);
		name = dataprovider.rdString(file);
		point = dataprovider.rdPoint2d(file);
		length = dataprovider.rdDouble(file);
		width = dataprovider.rdDouble(file);
	}

	void Rectangle::print()
	{
		std::cout << id << std::endl;
		std::cout << name << std::endl;
		dataprovider.printPoint2d(point);
		std::cout << length << std::endl;
		std::cout << width << std::endl;
	}

	void Rectangle::write(std::ofstream& file)
	{
		file << getType() << std::endl;
		dataprovider.writeInt(file, id);
		dataprovider.writeString(file, name);
		dataprovider.writePoint2d(file, point);
		dataprovider.writeDouble(file, length);
		dataprovider.writeDouble(file, width);
	}

	int Rectangle::getType()
	{
		int type = 2;
		return type;
	}