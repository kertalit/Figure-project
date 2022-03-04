#ifndef _FIGURE_H
#define _FIGURE_H

#include <fstream>
#include "Point2d.h"
#include "FileDataProvider.h"
#include "ConsoleDataProvider.h"



class Figure
{
	int id;
	std::string name;

public:

	Figure();
	Figure(int id, std::string& name);

	void virtual read(DataProvider& file) = 0;

	void virtual write(DataProvider& file) = 0;

	void virtual print() = 0;

	int  virtual getType() = 0;

	void setId(int id);
	void setName(std::string name);

	int getId();
	std::string getName();

};

#endif // !_FIGURE_H