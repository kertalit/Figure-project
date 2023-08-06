#include "Figure.h"

size_t Figure::count = 0;

Figure::Figure()
 :name(""), id(++count)
{
  
}

Figure::Figure(const std::string& name)
 :name(name), id(++count)
{
  
}

Figure::~Figure()
{

}

void Figure::read(DataProvider& provider)
{
  id = provider.rdInt();
  name = provider.rdString();
}
void Figure::print() const
{
  std::cout << id << std::endl;
  std::cout << name << std::endl;
}

void Figure::write(DataProvider& provider) const
{
  provider.writeInt(getType());
  provider.writeInt(id);
  provider.writeString(name);
}


void Figure::setName(const std::string& name)
{
  this->name = name;
}


int Figure::getId() const
{
  return id;
}

std::string Figure::getName() const
{
  return name;
}

