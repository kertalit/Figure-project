#include "Database.h"


	Database::Database(const std::string& path)
	{

		try
		{
			std::ifstream file;
			file.open(path);

			if (file.is_open())
				std::cout << "File is open" << std::endl;
			else
				std::cout << "File is not open" << std::endl;

			rdFile(file);
		}

		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			for (int i = 0; i < figures.size(); i++)
			{
				delete figures[i];
			}
		}

	}

	Database::~Database()
	{
		for (int i = 0; i < figures.size(); i++)
		{
			delete figures[i];
		}
	}

	std::vector<Figure*> Database::GetObjects() const
	{
		return figures;
	}

	void Database::wFile(std::vector<Figure*> objects, const std::string& path)
	{
		std::ofstream wFile(path);
		wFile << objects.size() << std::endl;

		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->write(wFile);
		}

	}


	void Database::rdFile(std::ifstream& file)
	{
		int objectCount = dataprovider.rdInt(file);

		figures.reserve(objectCount);

		for (int i = 0; i < objectCount; i++)
		{
			int type = dataprovider.rdInt(file);

			Figure* obj = 0;

			switch (type)
			{
			case 1:
			{
				obj = new Circle();
				break;
			}
			case 2:
			{
				obj = new Rectangle();
				break;
			}
			default:
				throw std::exception("Wrong format");
			}

			obj->read(file);
			figures.push_back(obj);

		}


	}