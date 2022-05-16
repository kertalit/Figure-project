#include "InterfaceProject.h"


bool validDb(DatabasePtr base)
{
 if (base == nullptr)
 {
  std::cout << "Database does not exist " << std::endl;
  return false;
 }
 return true;
}

void testSaveDb()
{
 auto base = std::make_shared<Database>("Figure1.txt");
 auto figures = base->GetObjects();

 for (auto obj : figures)
 {
   obj->print();
 }
 base->save("New Database.txt");
}

void testCreateDb()
{
 DatabasePtr base = createDb();

 std::cout << base << std::endl;
}

void testListDb()
{
 listDb(std::make_shared<Database>("Figure1.txt"));
}

void testChoiceDb()
{
 std::vector<DatabasePtr> bases;
 bases.push_back(std::make_shared<Database>("Figure1.txt"));
 bases.push_back(std::make_shared<Database>("New Database.txt"));

 DatabasePtr currentBase = nullptr;

 for (auto i = 0; i < bases.size(); ++i)
 {
  std::cout << std::endl;
  std::cout << "Base # " << i + 1 << std::endl << std::endl;
  listDb(bases[i]);
 }

 currentBase = bases[1];

 std::cout << "Current base:" << std::endl;
 currentBase->print();
}

void testCreateObj()
{
 std::cout << "Circle: " << std::endl;
 createObj(Circle::type)->print();

 std::cout << "Rectangle: " << std::endl;
 createObj(Rectangle::type)->print();

 std::cout << "Polyline: " << std::endl;
 createObj(Polyline::type)->print();
}

void testLoadDb()
{
 DatabasePtr base = loadDb();

 std::cout << "Database was loaded" << std::endl << std::endl;

 listDb(base);
}

void testChangeObj()
{
 Database base("Figure1.txt");
 base.print();

 try
 {
   auto figure = base.searchId(102);
   changeObj(figure);
   base.print();
 }
 catch (const std::exception& ex)
 {
   std::cout << ex.what() << std::endl;
 }
}

void testSearchId()
{
 Database base("Figure1.txt");
 int number = 102;
 int bad_number = 10;

 try
 {
   auto result = base.searchId(bad_number);
   std::cout << "Id found" << std::endl;

   auto result2 = base.searchId(number);
   std::cout << "Exception didn't work " << std::endl;
 }
 catch (const std::exception& ex)
 {
   std::cout << ex.what() << std::endl;
 }
}

void testPrintDb()
{
 Database base("Figure1.txt");
 base.print();
}

void testCreateFigure()
{
 ConsoleDataProvider console;

 auto pBase = std::make_shared<Database>();

 FigurePtr obj = createObj(Rectangle::type);
 obj->read(console);
 pBase->addObj(obj);

 std::cout << "Rectangle was created" << std::endl;

 pBase->print();
}

void testDeleteFigure()
{
 Database base("Figure1.txt");

 base.print();

 std::cout << std::endl;
 std::cout << "deleteFigure" << std::endl << std::endl;
 base.deleteFigure(101);

 base.print();
 std::cout << std::endl;

 std::cout << "deleteFigure" << std::endl << std::endl;
 base.deleteFigure(50);
 std::cout << std::endl;
}




void UI()
{
 DatabasePtr currentBase = nullptr;
 std::vector<DatabasePtr> bases;
 ConsoleDataProvider console;

 std::string command = "";

 std::cout << "Available commands:" << std::endl << std::endl;
 std::cout << "createDb" << std::endl;
 std::cout << "saveDb" << std::endl;
 std::cout << "loadDb" << std::endl;
 std::cout << "createFigure" << std::endl;
 std::cout << "printDb" << std::endl;
 std::cout << "changeObj" << std::endl;
 std::cout << "choiceDb" << std::endl;
 std::cout << "deleteFigure" << std::endl;
 std::cout << "Exit" << std::endl;

 while (true)
 {
  std::cout << "Enter command" << std::endl;
  std::cin >> command;

  if (command == "createDb")
  {
   currentBase = createDb();
   bases.push_back(currentBase);
  }
  else if (command == "saveDb")
  {
   if (!validDb(currentBase))
    continue;
   
    saveDb(currentBase);
  }
  else if (command == "loadDb")
  {
   currentBase = loadDb();
   bases.push_back(currentBase);

   std::cout << "Database was loaded" << std::endl;

  }
  else if (command == "createFigure")
  {
   if (!validDb(currentBase))
    continue;

   std::cout << "What figure to create?" << std::endl;
   std::cout << "Enter '1' for Circle" << std::endl;
   std::cout << "Enter '2' for Rectangle" << std::endl;
   std::cout << "Enter '3' for Polyline" << std::endl;

   size_t type;
   std::cin >> type;

    FigurePtr obj = createObj(type);
    obj->read(console);
    currentBase->addObj(obj);

    std::cout << "Figure was created" << std::endl;
  }
  else if (command == "printDb")
  {
   if (!validDb(currentBase))
    continue;

   currentBase->print();
  }
  else if (command == "changeObj")
  {
   if (!validDb(currentBase))
    continue;

   listDb(currentBase);
   
   std::cout << std::endl;

   int number = 0;
   std::cout << "Enter figure ID (1,2,3...)" << std::endl;
   std::cin >> number;

   try
   {
     auto index = currentBase->searchId(number);
     auto figure = currentBase->GetObjects();
     changeObj(index);
   }
    catch (const std::exception& ex)
    {
      std::cout << ex.what();
    }
  }
  else if (command == "choiceDb")
  {
   if (!validDb(currentBase))
    continue;

   for (size_t i = 0; i < bases.size(); i++)
   {
     std::cout << std::endl;
     std::cout << "Base # " << i + 1 << std::endl << std::endl;
     listDb(bases[i]);
   }

   size_t index;
   std::cout << "Enter base index (1,2,3...)" << std::endl;
   std::cin >> index;

   if (index > bases.size())
   {
     std::cout << "No such base" << std::endl;
   }
   else
   {
     currentBase = bases[index];
     std::cout << "Current base was changed" << std::endl;
   }
  }
  else if (command == "deleteFigure")
  {
    if (!validDb(currentBase))
     continue;
   
    std::cout << "Enter id figure" << std::endl;
    size_t id;
    std::cin >> id;

    currentBase->deleteFigure(id);
  }
  else if (command == "Exit")
  {
  if (validDb(currentBase))
  {
   std::string choice = "";
   std::cout << "Do you want to keep current base? yes / no" << std::endl;
   std::cin >> choice;

   if (choice == "yes")
   {
    std::string path;
    std::cout << "Enter path to save" << std::endl;
    std::cin >> path;

    currentBase->save(path);
   }
   else return;
  }
  else return;
  }
 }
}



int main()
{
 //testWriteDb();
 //testListDb();
 //testCreateDb();
 //testChoiceDb();
 //testCreateObj();
 //testLoadDb();
 //testChangeObj();
 //testSearchId();
 //testPrintDb();
 //testCreateFigure();
 //testDeleteFigure();
 //UI();

}