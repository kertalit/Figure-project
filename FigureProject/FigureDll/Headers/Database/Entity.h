#ifndef _FIGURE_H
#define _FIGURE_H

#include "Platform.h"
#include "Point2d.h"
#include "FileBinaryDataProvider.h"
#include "ConsoleDataProvider.h"
#include "Object.h"

#include <fstream>




class FIGURE_API Entity : public Object
{
public:
    Entity();
    Entity(const std::string& name);

    void readFrom(DataProvider& provider) override;
    void writeTo(DataProvider& provider) const override;

    virtual int getType() const = 0;

    int getId() const;

private:

};



#endif // !_FIGURE_H