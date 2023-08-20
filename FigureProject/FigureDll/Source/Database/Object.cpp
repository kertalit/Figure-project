#include "Object.h"


Object::Object()
    :name("")
{
}

Object::Object(const std::string& name)
    :name(name)
{
}

void Object::readFrom(DataProvider& provider)
{
    name = provider.rdString();
}

void Object::writeTo(DataProvider& provider) const
{
    provider.writeString(name);
}

Object::~Object()
{
}
