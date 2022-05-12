#ifndef _DATABASE_H
#define _DATABASE_H


#pragma once

#include "Platform.h"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polilyne.h"
#include <vector>

using DatabasePtr = std::shared_ptr<class Database> FIGURE_API;

class FIGURE_API Database
{

public:
	Database(const std::string& path);
	Database();
	
	~Database();

	std::vector<FigurePtr> GetObjects() const;

	void save(const std::string& path);
	void print();
	void addObj(FigurePtr obj);
	void deleteFigure(size_t pos);

private:
	std::vector<FigurePtr> figures;
	void rdFile(DataProvider& file);

};

#endif // !_DATABASE_H