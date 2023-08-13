#include "Database.h"
#include "Commands.h"
#include "FileDataProvider.h"


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

std::vector<EntityPtr> Database::GetObjects() const
{
    return figures;
}

void Database::save(const std::string& path)
{
    FileBinaryDataProvider filer(path, FileBinaryDataProvider::OpenMode::Out);

    filer.writeInt(figures.size());

    for (auto& obj : figures)
    {
        obj->writeTo(filer);
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

void Database::addObj(EntityPtr obj)
{
    figures.push_back(obj);
}

std::vector<EntityPtr>::iterator Database::subSearchId(size_t id)
{
    auto res = std::find_if(figures.begin(), figures.end(), [id](const EntityPtr& obj)->bool {return id == obj->getId(); });

    if (res == figures.end())
        throw std::exception("Id not found");

    return res;
}

EntityPtr Database::searchId(size_t id)
{
    return *subSearchId(id);
}


void Database::print() const
{
    for (auto& obj : figures)
    {
        obj->print();
    }
}

void Database::deleteFigure(size_t id)
{
    figures.erase(subSearchId(id));
}