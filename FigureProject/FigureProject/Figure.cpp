#include "Figure.h"


Figure::Figure()
	:id(0), name(" ")
{

}
Figure::Figure(int id, std::string& name)
	:id(id), name(name)
{

}

void  Figure::read(DataProvider& file)
{
	id = file.rdInt();
	name = file.rdString();
}
void  Figure::print() 
{
	std::cout << id << " ";
	std::cout << name << std::endl;
}

void  Figure::write(DataProvider& file)
{
	file.writeInt(id);
	file.writeString(name);
}

int  Figure::getType() 
{
	return 0;
}

void Figure::setId(int id)
{
	this->id = id;
}

void Figure::setName(std::string name)
{
	this->name = name;
}

int Figure::getId()
{
	return id;
}

std::string Figure::getName()
{
	return name;
}