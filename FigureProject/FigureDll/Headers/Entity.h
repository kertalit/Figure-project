#ifndef _FIGURE_H
#define _FIGURE_H

#include "Platform.h"
#include "Point2d.h"
#include "FileBinaryDataProvider.h"
#include "ConsoleDataProvider.h"
#include "Plan.h"

#include <fstream>


using  EntityPtr = std::shared_ptr<class Entity> FIGURE_API;

class FIGURE_API Entity
{
public:
    Entity();
    Entity(const std::string& name);

    virtual ~Entity();

    virtual void readFrom(DataProvider& provider) = 0;
    virtual void writeTo(DataProvider& provider) const = 0;
    virtual void toPlan(Plan& plan) const = 0;

    void setName(const std::string& name);

    virtual int getType() const = 0;
    int getId() const;

private:
    std::string name;
    size_t id;
    static size_t count;
};



#endif // !_FIGURE_H