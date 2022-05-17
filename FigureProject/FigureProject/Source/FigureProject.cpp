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
 base->save("NewDatabase.txt");
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
 bases.push_back(std::make_shared<Database>("NewDatabase.txt"));

 DatabasePtr currentBase = nullptr;

 for (auto i = 0; i < bases.size(); ++i)
 {
  std::cout << std::endl;
  std::cout << "Base # " << i << std::endl << std::endl;
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

 try
 {
   createObj(4);
 }
 catch (const std::exception& ex)
 {
   std::cout << ex.what() << std::endl;
 }
}

void testLoadDb()
{
  DatabasePtr base = std::make_shared<Database>("Figure1.txt");
  listDb(base);
}

void testSearchId()
{
  auto base = std::make_shared<Database>("Figure1.txt");
  int id = 102;
  int bad_id= 10;

 try
 {
   auto result = base->searchId(id);
   std::cout << "Id found" << std::endl;

   auto result2 = base->searchId(bad_id);
   std::cout << "Exception did`not work" << std::endl;
 }
 catch (const std::exception& ex)
 {
   std::cout << ex.what() << std::endl;
 }
}

void testPrintDb()
{
  auto base = std::make_shared<Database>("Figure1.txt");
  base->print();
}

void testCreateFigure()
{
  ConsoleDataProvider console;

  auto pBase = std::make_shared<Database>();

  FigurePtr obj = createObj(Rectangle::type);
  obj->read(console);
  pBase->addObj(obj);

  std::cout << "Rectangle was created and added to base" << std::endl;

  pBase->print();
}

void testDeleteFigure()
{
  auto base = std::make_shared<Database>("Figure1.txt");

  base->print();
  try
  {
    std::cout << std::endl;
    std::cout << "deleteFigure" << std::endl << std::endl;
    base->deleteFigure(101);

    base->print();
    std::cout << std::endl;

    std::cout << "deleteFigure" << std::endl << std::endl;
    base->deleteFigure(50);
    std::cout << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
  }
  
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

    std::cout << "Figure was created and added to base" << std::endl;
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
   std::cout << "Enter figure Id" << std::endl;
   std::cin >> number;

   try
   {
     auto index = currentBase->searchId(number);
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
     continue;
   }
   currentBase = bases[index];
   std::cout << "Current base was changed" << std::endl;
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

    return;
   }
   else return;
  }
  else return;
  }
 }
}



int main()
{
 //testSaveDb();
 //testListDb();
 //testCreateDb();
 //testChoiceDb();
 //testCreateObj();
 //testLoadDb();
 //testSearchId();
 //testPrintDb();
 //testDeleteFigure();
 //UI();

}