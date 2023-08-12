#include "Figure.h"

size_t Entity::count = 0;

Entity::Entity()
    :name(""), id(++count)
{

}

Entity::Entity(const std::string& name)
    :name(name), id(++count)
{

}

Entity::~Entity()
{

}

void Entity::read(DataProvider& provider)
{
    id = provider.rdInt();
    name = provider.rdString();
}
void Entity::print() const
{
    std::cout << id << std::endl;
    std::cout << name << std::endl;
}

void Entity::write(DataProvider& provider) const
{
    provider.writeInt(getType());
    provider.writeInt(id);
    provider.writeString(name);
}


void Entity::setName(const std::string& name)
{
    this->name = name;
}


int Entity::getId() const
{
    return id;
}

std::string Entity::getName() const
{
    return name;
}

