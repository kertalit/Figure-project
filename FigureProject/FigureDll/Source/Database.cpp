#include "Database.h"
#include "Commands.h"


Database::Database(const std::string& path)
{
 std::ifstream file;
 try
 {
  FileDataProvider fileDataProvider(file, path);
  rdFile(fileDataProvider);
 }

 catch (const std::exception& ex)
 {
  std::cout << ex.what() << std::endl;
 }
}
 
Database::Database()
{

}

Database::~Database()
{

}

std::vector<FigurePtr> Database::GetObjects() const
{
  return figures;
}

void Database::save(const std::string& path)
{
  std::ofstream File;
  FileDataProvider fileDataProvider(File, path);
  
  fileDataProvider.writeInt(figures.size());

  for (size_t i = 0; i < figures.size(); i++)
  {
   figures[i]->write(fileDataProvider);
  }
}

void Database::rdFile(DataProvider& stream)
{
  int objectCount = stream.rdInt();

  figures.reserve(objectCount);

  for (size_t i = 0; i < objectCount; i++)
  {
   size_t type = stream.rdInt();
   FigurePtr obj = createObj(type);

   obj->read(stream);
   figures.push_back(obj);
  }
}

void Database::addObj(FigurePtr obj)
{
  figures.push_back(obj);
}

std::vector<FigurePtr>::iterator Database::searchId(size_t key)
{
  auto res = std::find_if(figures.begin(), figures.end(), [key](const FigurePtr& obj)->bool {return key == obj->getId();});

  if (res == figures.end())
    throw std::exception ("Id not found");

  return res;
}

void Database::print() const
{
  for (size_t i = 0; i < figures.size(); ++i)
  {
    figures[i]->print();
  }
}

void Database::deleteFigure(size_t id)
{
  auto position = std::find_if(figures.begin(), figures.end(), [id](const FigurePtr& obj)->bool {return id == obj->getId();});

  if (position == figures.end())
  {
    std::cout << "Id not found" << std::endl;
    return;
  }
  figures.erase(position);
}