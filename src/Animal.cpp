#include <iostream>
#include <string>
using namespace std;

class Animal{
  public:
    void getFamily(){ cout << "we are animals" << endl; }
    virtual void getClass() { cout << "I'm animal" << endl; }
};

class Dog : public Animal{
  public:
    void getClass() { cout << "I'm a dog" << endl; }
};

class GermanShepard : public Dog {
  public:
    void getClass() { cout << "I'm a German Shepard" << endl; }
    void getDerivd() { cout << "I'm animal and dog" << endl; }
};


void whatClass(Animal* animal) {
  animal -> getClass();
}


int main() {
  Animal* animal = new Animal;
  Dog* dog = new Dog;

  animal -> getClass();
  dog -> getClass();

  whatClass(animal);
  whatClass(dog);
 
  Dog spot;
  GermanShepard max;

  Animal* ptrDog = &spot;
  Animal* ptrGS = &max;

  ptrDog -> getFamily();
  ptrGS -> getClass();

  ptrGS -> getFamily();
  ptrGS -> getClass();
  
  return 0;
}
