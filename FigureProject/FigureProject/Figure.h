#ifndef _FIGURE_H
#define _FIGURE_H


#pragma once
#include <fstream>
#include "Point2d.h"
#include "DataProvider.h"



class Figure
{
public:
	void virtual read(std::ifstream& file) = 0;
	void virtual print() = 0;
	void virtual write(std::ofstream& file) = 0;
	int virtual getType() = 0;

};

#endif // !_FIGURE_H