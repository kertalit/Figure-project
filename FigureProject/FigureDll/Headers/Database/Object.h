#pragma once

#include "DataProvider.h"

#include <string>

using ObjectPtr = std::shared_ptr<class Object> FIGURE_API;

class Object
{
public:
    Object();
    Object(const std::string& name);

    virtual void readFrom(DataProvider& provider) = 0;
    virtual void writeTo(DataProvider& provider) const = 0;

    virtual ~Object();

protected:
    std::string name;
};