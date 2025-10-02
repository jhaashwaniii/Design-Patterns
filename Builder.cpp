#include<bits/stdc++.h>
using namespace std;

//Product-- final object
class House{
  
  private:
     string walls;
     string roofs;
     string windows;
  public:
   void setWalls(string w)
   {
     walls=w;
   }
   void setRoofs(string r)
   {
     roofs=r;
   }
   void setWindows(string w)
   {
     windows=w;
   }
   
   void show()
   {
     cout<<"House with "<<walls<<" "<<roofs<<" "<<windows;
   }
  
};


//Abstarct Builder-- define steps
class HouseBuilder{
  public:
  virtual void buildWalls()=0;
  virtual void buildRoofs()=0;
  virtual void buildWindows()=0;
  virtual House* getHouse()=0;
};


//Concrete Builder-- implement steps for different variants
class WoodenHouseBuilder : public HouseBuilder{
  private:
  House* house;
  
  public:
  WoodenHouseBuilder ()
  {
    house=new House();
  }
  void buildWalls()
  {
    house->setWalls("Wooden Walls");
  }
  
  void buildRoofs()
  {
    house->setRoofs("wooden roofs");
  }
  
  void buildWindows()
  {
    house->setWindows("wooden windows");
  }
  House* getHouse()
  {
    return house;
  }
  
  
  
};

class GlassHouseBuilder : public HouseBuilder{
  private:
  House* house;
  
  public:
  GlassHouseBuilder ()
  {
    house=new House();
  }
  void buildWalls()
  {
    house->setWalls("Glass Walls");
  }
  
  void buildRoofs()
  {
    house->setRoofs("Glass roofs");
  }
  
  void buildWindows()
  {
    house->setWindows("Glass windows");
  }
  
   House* getHouse()
  {
    return house;
  }
  
  
};

//Director-- controls construction steps


class Director{
  
  private:
  HouseBuilder* builder;
  
  public:
  Director(HouseBuilder* b){
    builder=b;
  }
  
  House* constructHouse(){
    builder->buildWalls();
    builder->buildWindows();
    builder->buildRoofs();
    return builder->getHouse();
  }
};

int main()
{
  WoodenHouseBuilder woodenHouseBuilder;
  Director* d1=new Director(&woodenHouseBuilder);
  House* woodenHouse=d1->constructHouse();
  woodenHouse->show();
  return 0;
}
