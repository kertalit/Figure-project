#include "Figure.h"


Figure::Figure()
 :name("")
{
  id = generateId();
}

Figure::Figure(const std::string& name)
 :name(name)
{
  id = generateId();
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

void Figure::setId(size_t id)
{
  this->id = id;
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

size_t Figure::generateId() const
{
  static size_t id = 0;
  return ++id;
}