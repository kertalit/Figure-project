#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(const std::string& name) : Object(name)
{
}

void Entity::readFrom(DataProvider& provider)
{
}

void Entity::writeTo(DataProvider& provider) const
{
}
