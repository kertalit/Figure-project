#ifndef _FIGURE_H
#define _FIGURE_H


#pragma once
#include <fstream>
#include "Point2d.h"
#include "FileDataProvider.h"
#include "ConsoleDataProvider.h"



class Figure
{
public:
	void virtual read(DataProvider& file) = 0;

	void virtual write(DataProvider& file) = 0;

	void virtual print() = 0;

	int  virtual getType() = 0;

	void virtual change() = 0;


};

#endif // !_FIGURE_H