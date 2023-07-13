#ifndef _F_BINARY_DATAPROVIDER_H
#define _F_BINARY_DATAPROVIDER_H


#include "Platform.h"
#include "Point2d.h"
#include "DataProvider.h"

#include <ostream>
#include <string>
#include <fstream>

class FIGURE_API FileBinaryDataProvider : public DataProvider
{
public:
  FileBinaryDataProvider(std::ifstream& stream, const std::string& path);
  FileBinaryDataProvider(std::ofstream& stream, const std::string& path);

  ~FileBinaryDataProvider() override;

  int rdInt() override;
  std::string rdString() override;
  Point2d rdPoint2d() override;
  double rdDouble() override;

  void writeInt(const int number) override;
  void writePoint2d(const Point2d& point) override;
  void writeString(const std::string& line) override;
  void writeDouble(const double number) override;

  void printPoint2d(const Point2d& point) override;

private:
  std::ifstream inFile;
  std::ofstream outFile;
};

#endif // !_F_BINARY_DATAPROVIDER_H