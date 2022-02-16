#include "Database.h"
#include "Sample.h"


	Database::Database(const std::string& path)
	{

		try
	  {
			std::ifstream file;
			DataProvider dataprovider(file, path);

			rdFile(dataprovider);
		}

		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			DeleteObject();
		}

	}

	Database::~Database()
	{
		DeleteObject();
	}

	std::vector<Figure*> Database::GetObjects() const
	{
		return figures;
	}

	void Database::Write(const std::string& path)
	{
		std::ofstream File;
		DataProvider dataprovider(File, path);
		
		dataprovider.writeInt(figures.size());

		for (int i = 0; i < figures.size(); i++)
		{
			figures[i]->write(dataprovider);
		}

	}

	
	void Database::rdFile(DataProvider& file)
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

	void Database::DeleteObject()
	{
		for (int i = 0; i < figures.size(); i++)
		{
			delete figures[i];
		}
	}