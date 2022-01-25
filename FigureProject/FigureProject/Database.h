#ifndef _DATABASE_H
#define _DATABASE_H


#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>

class Database
{

public:
	Database(const std::string& path);
	
	~Database();

	std::vector<Figure*> GetObjects() const;

	void wFile(std::vector<Figure*> objects, const std::string& path);


private:
	std::vector<Figure*> figures;
	DataProvider dataprovider;
	void rdFile(std::ifstream& file);

};

#endif // !_DATABASE_H