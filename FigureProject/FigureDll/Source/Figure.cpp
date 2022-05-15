#include "Figure.h"


Figure::Figure()
 :id(0), name(" ")
{

}

Figure::Figure(size_t id, const std::string& name)
 :id(id), name(name)
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

int Figure::getType() const
{
  return 0;
}

int Figure::getId() const
{
 return id;
}

std::string Figure::getName() const
{
 return name;
}