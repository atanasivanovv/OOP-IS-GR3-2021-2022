#include <iostream>
#include <cstring>

using namespace std;

class A
{
public:
  A()  { cout << "A's constructor called" << endl; }
};
  
class B
{
public:
  B()  { cout << "B's constructor called" << endl; }
};
  
class C: public B, public A  // обърнете внимание на реда
{
public:
  C()  { cout << "C's constructor called" << endl; }
};
  
int main()
{
    C c;
    return 0;
}