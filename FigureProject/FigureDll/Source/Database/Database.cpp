#include "Database.h"
#include "Commands.h"
#include "FileBinaryDataProvider.h"
#include "FileDataProvider.h"
#include "ConsoleDataProvider.h"


Database::Database(const std::string& path)
{
    try
    {
        FileDataProvider fileDataProvider(path);
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

std::vector<ObjectPtr> Database::GetObjects() const
{
    return figures;
}

void Database::save(const std::string& path) const
{
    FileBinaryDataProvider filer(path, FileBinaryDataProvider::OpenMode::Out);

    writeTo(filer);
}

void Database::writeTo(DataProvider& provider) const
{
    provider.writeInt(figures.size());

    for (const auto& obj : figures)
    {
        obj->writeTo(provider);
    }
}

void Database::rdFile(DataProvider& stream)
{
    int objectCount = stream.rdInt();

    figures.reserve(objectCount);

    for (auto i = 0; i < objectCount; ++i)
    {
        auto type = stream.rdInt();
        auto obj = createObj(type);

        obj->readFrom(stream);
        figures.push_back(obj);
    }
}

void Database::addObj(ObjectPtr obj)
{
    figures.push_back(obj);
}

std::vector<ObjectPtr>::iterator Database::subSearchId(size_t id)
{
    auto res = std::find_if(figures.begin(), figures.end(), [id](const ObjectPtr& obj)->bool {return id == obj->getId(); });

    if (res == figures.end())
        throw std::exception("Id not found");

    return res;
}

ObjectPtr Database::searchId(size_t id)
{
    return *subSearchId(id);
}


void Database::print() const
{
    ConsoleDataProvider provider;

    writeTo(provider);
}

void Database::deleteFigure(size_t id)
{
    figures.erase(subSearchId(id));
}