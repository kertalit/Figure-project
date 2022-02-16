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
	
	~Database();

	std::vector<Figure*> GetObjects() const;

	void Write(const std::string& path);


private:
	std::vector<Figure*> figures;
	void rdFile(DataProvider& file);
	void DeleteObject();

};

#endif // !_DATABASE_H