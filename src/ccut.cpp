#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
  private:
    int height;
    int weight;
    string name;

    static int numOf;
  public:
    int getHeight() { return height;}
    int getWeight() { return weight;}
    string getName(){ return name; }

    void setHeight(int cm) { height = cm; }
    void setWeight(int wm) { weight = wm; }
    void setName(string nn) { name = nn; }

    Animal(int, int, string);

    ~Animal();
    
    Animal();
    
    static int getNumOf() { return numOf; }

    void toString();
};

int Animal::numOf = 0;

Animal::Animal(int height, int weight, string name) {
  this -> height = height;
  this -> weight = weight;
  this -> name = name;
  Animal::numOf++;
}

Animal::~Animal() {
 cout << "the animal:" << this -> name  << "destoryed" << endl;
}

Animal::Animal(){
  Animal::numOf++;
}

void Animal::toString(){
  cout << this -> name << " is " << this -> weight << " kgs " << this -> height << " cm" << endl;
}

class Dog : public Animal {
  private:
    string sound = "woof";
  public:
    void getSound() { cout << sound << endl;}
    Dog(int, int, string, string);
    Dog(): Animal(){};

    void toString();
};

Dog::Dog(int height, int weight, string name, string bark):
  Animal(height,weight,name) {
   this -> sound = bark;
}

void Dog::toString(){
  cout << this -> getName() << " is " << this -> getHeight() << " cms tall and " << this -> getWeight() <<
    " sound: " << this -> sound << endl;
}

int main() {
 
  Animal fred;
  fred.setWeight(3);
  fred.setHeight(12);
  fred.setName("fred");
  
  cout << fred.getName() << " is " << fred.getWeight() << " kgs and " << fred.getHeight() << " cm" << endl;
 
  Dog spot(22,16,"Spot","woof");
  spot.toString();
  spot.Animal::toString();
  
  return 0;
}
