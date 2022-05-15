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
 outFile.close();
 inFile.close();
 std::cout << "File is closed" << std::endl;
}

int FileDataProvider::rdInt()
{
 int number = 0;
 inFile >> number;
 return number;
}

std::string FileDataProvider::rdString()
{
 std::string line = "";
 inFile >> line;
 return line;
}

Point2d FileDataProvider::rdPoint2d()
{
 Point2d point;
 inFile >> point.x >> point.y;

 return point;
}

double FileDataProvider::rdDouble()
{
 double number = 0.0;
 inFile >> number;
 return number;
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
