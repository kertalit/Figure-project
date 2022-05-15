#ifndef _DATABASE_H
#define _DATABASE_H

#include "Platform.h"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polyline.h"
#include <vector>

using DatabasePtr = std::shared_ptr<class Database> FIGURE_API;

class FIGURE_API Database
{
public:
  Database(const std::string& path);
  Database();
  ~Database();

  void save(const std::string& path);
  void print() const;
  void addObj(FigurePtr obj);
  std::vector<FigurePtr>::iterator searchId(size_t key);
  void deleteFigure(size_t pos);

  std::vector<FigurePtr> GetObjects() const;

private:
  std::vector<FigurePtr> figures;
  void rdFile(DataProvider& stream);
};

#endif // !_DATABASE_H