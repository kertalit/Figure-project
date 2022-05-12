#ifndef _FIGURE_H
#define _FIGURE_H


#include "Platform.h"
#include <fstream>
#include "Point2d.h"
#include "FileDataProvider.h"
#include "ConsoleDataProvider.h"

 using  FigurePtr = std::shared_ptr<class Figure> FIGURE_API;

class FIGURE_API Figure
{
	size_t id;
	std::string name;
	static size_t count;

public:

	Figure();
	Figure(size_t id, const std::string& name);

	void virtual read(DataProvider& provider) = 0;

	void virtual write(DataProvider& provider) = 0;

	void virtual print() = 0;

	int  virtual getType() const = 0;

	void setId(size_t id);
	void setName(const std::string& name);

	int getId() const;
	std::string getName() const;
	
};



#endif // !_FIGURE_H