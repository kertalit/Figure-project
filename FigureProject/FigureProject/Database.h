#ifndef _DATABASE_H
#define _DATABASE_H


#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polilyne.h"
#include <vector>

class Database
{

public:
	Database(const std::string& path);
	Database();
	
	~Database();

	std::vector<Figure*> GetObjects() const;

	void save(const std::string& path);
	void print();
	void addObj(Figure* obj);

private:
	std::vector<Figure*> figures;
	void rdFile(FileDataProvider& file);
	void DeleteObject();

};

#endif // !_DATABASE_H