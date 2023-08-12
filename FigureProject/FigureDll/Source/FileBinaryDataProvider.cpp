#include "FileBinaryDataProvider.h"

FileBinaryDataProvider::FileBinaryDataProvider(const std::string& path, OpenMode openmode)
{
    auto mode = openmode == OpenMode::In ? std::ios::in : std::ios::out;

    file.open(path, mode | std::ios::binary);

    if (file.is_open())
        std::cout << "File is open" << std::endl;
    else
        std::cout << "File is not open" << std::endl;
}

FileBinaryDataProvider::~FileBinaryDataProvider()
{
    file.close();
}

int FileBinaryDataProvider::rdInt()
{
    int val = 0;
    file.read(reinterpret_cast<char*>(&val), sizeof(val));
    return val;
}

std::string FileBinaryDataProvider::rdString()
{
    std::string line = "";
    file.read(reinterpret_cast<char*>(&line), sizeof(line));
    return line;
}

Point2d FileBinaryDataProvider::rdPoint2d()
{
    Point2d point;
    file.read(reinterpret_cast<char*>(&point), sizeof(point));

    return point;
}

double FileBinaryDataProvider::rdDouble()
{
    double val = 0.0;
    file.read(reinterpret_cast<char*>(&val), sizeof(val));
    return val;
}

void FileBinaryDataProvider::writeInt(const int number)
{
    file.write(reinterpret_cast<const char*>(&number), sizeof(number));
}

void FileBinaryDataProvider::writePoint2d(const Point2d& point)
{
    file.write(reinterpret_cast<const char*>(&point), sizeof(point));
}

void FileBinaryDataProvider::writeString(const std::string& line)
{
    file.write(reinterpret_cast<const char*>(&line), sizeof(line));
}

void FileBinaryDataProvider::writeDouble(const double number)
{
    file.write(reinterpret_cast<const char*>(&number), sizeof(number));
}

void FileBinaryDataProvider::printPoint2d(const Point2d& point)
{
    std::cout << point << std::endl;
}
