#include <iostream>
#include <fstream>

class Point
{
private:
   int x, y;
public:
   // деклариране на двата типа ++
   Point& operator++() {
       this->x++;
       this->y++;
       return *this;
   }
   Point operator++(int) {

   }     

   Point& operator--() {

   }   

   Point operator--(int) {

   }     

   // Define default constructor.
   Point() { 
       this->x = 0;
       this->y = 0; 
    }

   // Define accessor functions->
   int getX() { 
       return this->x; 
    }
   int getY() { 
       return this->y; 
    }

};

int main() {
    Point p;
    p++;
    p++;
    p++;

    ++p;
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;
}