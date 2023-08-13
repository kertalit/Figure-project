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

    void readFrom(DataProvider& provider);
    void writeTo(DataProvider& provider) const;
    void virtual print() const = 0;
    void virtual ToPlan(Plan& plan) const = 0;

    void setName(const std::string& name);

    int virtual getType() const = 0;

    int getId() const;

protected:
    virtual void writeInternal(DataProvider& provider) const = 0;
    virtual void readInternal(DataProvider& provider) = 0;

private:
    std::string name;
    size_t id;
    static size_t count;
};



#endif // !_FIGURE_H