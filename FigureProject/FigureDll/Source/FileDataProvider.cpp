#include "FileDataProvider.h"

FileDataProvider::FileDataProvider(const std::string& path)
{
  file.open(path);

  if (file.is_open())
    std::cout << "File is open" << std::endl;
  else
    std::cout << "File is not open" << std::endl;
}

FileDataProvider::~FileDataProvider()
{

}

int FileDataProvider::rdInt()
{
  int val = 0;
  file >> val;
  return val;
}

std::string FileDataProvider::rdString()
{
  std::string line = "";
  file >> line;
  return line;
}

Point2d FileDataProvider::rdPoint2d()
{
  Point2d point;
  file >> point;

  return point;
}

double FileDataProvider::rdDouble()
{
  double val = 0.0;
  file >> val;
  return val;
}

void FileDataProvider::writeInt(const int number)
{
  file << number << std::endl;
}

void FileDataProvider::writePoint2d(const Point2d& point)
{
  file << point << std::endl;
}

void FileDataProvider::writeString(const std::string& line)
{
  file << line << std::endl;
}

void FileDataProvider::writeDouble(const double number)
{
  file << number << std::endl;
}

void FileDataProvider::printPoint2d(const Point2d& point)
{
  std::cout << point << std::endl;
}
