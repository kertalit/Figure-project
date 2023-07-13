#include "FileBinaryDataProvider.h"

FileBinaryDataProvider::FileBinaryDataProvider(std::ifstream& stream, const std::string& path)
{
  inFile.open(path, std::ios::binary);

  if (inFile.is_open())
   std::cout << "File is open" << std::endl;
  else
   std::cout << "File is not open" << std::endl;
}

FileBinaryDataProvider::FileBinaryDataProvider(std::ofstream& stream, const std::string& path)
{
  outFile.open(path, std::ios::binary);

  if (outFile.is_open())
   std::cout << "File is open" << std::endl;
  else
   std::cout << "File is not open" << std::endl;
}

FileBinaryDataProvider::~FileBinaryDataProvider()
{

}

int FileBinaryDataProvider::rdInt()
{
  int val = 0;
  inFile.read((char*) &val, sizeof(val));
  return val;
}

std::string FileBinaryDataProvider::rdString()
{
  std::string line = "";
  inFile.read((char*) &line, sizeof(line));
  return line;
}

Point2d FileBinaryDataProvider::rdPoint2d()
{
  Point2d point;
  inFile.read((char*) &point, sizeof(point));

  return point;
}

double FileBinaryDataProvider::rdDouble()
{
  double val = 0.0;
  inFile.read((char*) &val, sizeof(val));
  return val;
}

void FileBinaryDataProvider::writeInt(const int number)
{
  outFile.write((char*) &number, sizeof(number));
}

void FileBinaryDataProvider::writePoint2d(const Point2d& point)
{
  outFile.write((char*) &point, sizeof(point));
}

void FileBinaryDataProvider::writeString(const std::string& line)
{
  outFile.write((char*) &line, sizeof(line));
}

 void FileBinaryDataProvider::writeDouble(const double number)
{
  outFile.write((char*) &number, sizeof(number));
}

void FileBinaryDataProvider::printPoint2d(const Point2d& point)
{
  std::cout << point << std::endl;
}
  