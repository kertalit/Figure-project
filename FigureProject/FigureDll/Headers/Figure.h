#ifndef _FIGURE_H
#define _FIGURE_H


#include "Platform.h"
#include <fstream>
#include "Point2d.h"
#include "FileBinaryDataProvider.h"
#include "ConsoleDataProvider.h"

 using  FigurePtr = std::shared_ptr<class Figure> FIGURE_API;

class FIGURE_API Figure
{
public:
 Figure();
 Figure(const std::string& name);

 virtual ~Figure();

 void virtual read(DataProvider& provider) = 0;
 void virtual write(DataProvider& provider) const = 0;
 void virtual print() const = 0;

 void setName(const std::string& name);

 int virtual getType() const = 0;
 int getId() const;
 std::string getName() const;


private:
 std::string name;
 size_t id;
 static size_t count;
};



#endif // !_FIGURE_H