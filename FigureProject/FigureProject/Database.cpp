#include "Database.h"
#include "Commands.h"


	Database::Database(const std::string& path)
	{

		try
	  {
			std::ifstream file;
			FileDataProvider fileDataProvider(file, path);

			rdFile(fileDataProvider);
		}

		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			DeleteObject();
		}

	}
	
	Database::Database()
	{

	}

	Database::~Database()
	{
		DeleteObject();
	}

	std::vector<Figure*> Database::GetObjects() const
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

	void Database::rdFile(FileDataProvider& file)
	{
		int objectCount = file.rdInt();

		figures.reserve(objectCount);

		for (int i = 0; i < objectCount; i++)
		{
			int type = file.rdInt();

			Figure* obj = createObj(type);

			obj->read(file);

			figures.push_back(obj);
		}
	}

	void Database::addObj(Figure* obj)
	{
		figures.push_back(obj);
	}

	void Database::print()
	{
		for (int i = 0; i < figures.size(); ++i)
		{
			figures[i]->print();
		}
	}

	void Database::DeleteObject()
	{
		for (int i = 0; i < figures.size(); i++)
		{
			delete figures[i];
		}
	}

