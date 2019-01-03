/***
 in this program we do a simple program to demonstrate the polymorphism in OOP
 Polymorphism: How To use a same function to do a different Job
 in this case we do this of function called: draw();
 To do a polymorphism you Must do Class inheritance , and make the Desired function as a Virtual

 draw()- in the Base Class Must to be Virtual to do polymorphism
     At the drived classes you can write the draw() functions with different definition in each.

 in main() -
   - first , make a pointer of type of the Base Class
   - to use the draw() function in the Drived Classes make the pointer points to the Desired object
     then, you can access the class and use the Desired function { draw() - in this case }
***/

#include <iostream>
using namespace std;


/// The Base class {Shape}
class Shape
{
public :
   virtual void draw(){cout<<"hhhhhhhhh";}
};

/// First Drived Class
class Astric : public Shape
{
public :
    void draw()
    {
        cout<<"***************:"<<endl;
    }
};

/// Second Drived Class
class Dash : public Shape
{
    void draw()
    {
        cout<<"---------------:"<<endl;
    }
};


int main()
{
   Shape *ptr ;
   Shape S1;
   Astric a1;
   Dash   d1;
   ptr = &a1;
   ptr->draw();
   ptr= &d1;
   ptr->draw();


    cout << "Hello world!" << endl;

    return 0;
}
