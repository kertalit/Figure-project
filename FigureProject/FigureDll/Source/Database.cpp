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

		for (int i = 0; i < figures.size(); i++)
		{
			figures[i]->write(fileDataProvider);
		}
	}

	void Database::rdFile(DataProvider& file)
	{
		int objectCount = file.rdInt();

		figures.reserve(objectCount);

		for (size_t i = 0; i < objectCount; i++)
		{
			size_t type = file.rdInt();

			FigurePtr obj = createObj(type);

			obj->read(file);

			figures.push_back(obj);
		}
	}

	void Database::addObj(FigurePtr obj)
	{
		figures.push_back(obj);
	}

	void Database::print()
	{
		for (size_t i = 0; i < figures.size(); ++i)
		{
			figures[i]->print();
		}
	}

	void Database::deleteFigure(size_t id)
	{
		
		int position = searchId(figures, id);

		if (position < 0)
		{
			std::cout << "Id not found" << std::endl;
			return;
		}
			figures.erase(figures.begin() + position);

	}

