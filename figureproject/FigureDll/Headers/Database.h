#ifndef _DATABASE_H
#define _DATABASE_H

#include "Platform.h"
#include "Entity.h"
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
  void addObj(EntityPtr obj);
  EntityPtr searchId(size_t id);
  void deleteFigure(size_t id);

  std::vector<EntityPtr> GetObjects() const;

private:
  std::vector<EntityPtr> figures;
  void rdFile(DataProvider& stream);
  std::vector<EntityPtr>::iterator subSearchId(size_t id);

  //Database(const Database& base);
  //Database operator = (const Database& base);
};

#endif // !_DATABASE_H