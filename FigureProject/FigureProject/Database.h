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

	std::vector<std::shared_ptr<Figure>> GetObjects() const;

	void save(const std::string& path);
	void print();
	void addObj(std::shared_ptr<Figure> obj);

private:
	std::vector<std::shared_ptr<Figure>> figures;
	void rdFile(FileDataProvider& file);

};

#endif // !_DATABASE_H