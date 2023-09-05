#ifndef _FIGURE_H
#define _FIGURE_H

#include "Object.h"
#include "Draw.h"

#include <fstream>

using EntityPtr = std::shared_ptr<class Entity> FIGURE_API;

class FIGURE_API Entity : public Object
{
public:
    Entity();
    Entity(const std::string& name);

    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;
    virtual void draw(Draw::ptr draw) const = 0;
    virtual void calculateSegments() = 0;

    virtual int getType() const = 0;
};



#endif // !_FIGURE_H