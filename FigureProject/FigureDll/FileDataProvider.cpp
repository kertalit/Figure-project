#include "FileDataProvider.h"

FileDataProvider::FileDataProvider(std::ifstream& stream, const std::string& path)
{
  inFile.open(path);

  if (inFile.is_open())
    std::cout << "File is open" << std::endl;
  else
    std::cout << "File is not open" << std::endl;
}

FileDataProvider::FileDataProvider(std::ofstream& stream, const std::string& path)
{
  outFile.open(path);

  if (outFile.is_open())
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
  inFile.read((char*)&val, sizeof(val));
  return val;
}

std::string FileDataProvider::rdString()
{
  std::string line = "";
  inFile.read((char*)&line, sizeof(line));
  return line;
}

Point2d FileDataProvider::rdPoint2d()
{
  Point2d point;
  inFile.read((char*)&point, sizeof(point));

  return point;
}

double FileDataProvider::rdDouble()
{
  double val = 0.0;
  inFile >> val;
  return val;
}

void FileDataProvider::writeInt(const int number)
{
  outFile << number << std::endl;
}

void FileDataProvider::writePoint2d(const Point2d& point)
{
  outFile << point << std::endl;
}

void FileDataProvider::writeString(const std::string& line)
{
  outFile << line << std::endl;
}

void FileDataProvider::writeDouble(const double number)
{
  outFile << number << std::endl;
}

void FileDataProvider::printPoint2d(const Point2d& point)
{
  std::cout << point << std::endl;
}
