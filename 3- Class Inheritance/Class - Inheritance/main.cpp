/**
*
*  this code shows how is the inheritance useful to fix or enhance
*   a previous class that had some issues.

************************************************************
 inheritance also useful to make code shorter and save times
 inheritance is a very useful and powerful in OOP.
************************************************************
*/

#include <iostream>
#include<process.h>
#define max_size 5
using namespace std;

/// this a basic stack data structure - But Yes,it have some Problems
/// we will fix some problems in another class called "enhanced_stack"
/// to fix the problems we will use the inheritance :D
/// But Now, here it is the Basic stack.
/*****************************************************************////

class stack
{
  protected:
     float container[max_size];  /// array stack
     int  top ;                /// points to the data will popped or pushed

  public:
    stack()   /// constructor to initialized top to -1
    {
        top=-1 ;
    }

    void push(float data);
    float pop();
    void print_stack();

};

/// functionality : push the data in the container
/// Problem : no check of the container state if it Full !
void stack::push(float data)
{
    container[++top]=data;
    top++;

}
/// functionality : pop the data from the container
/// Problem : no check of the container state if it Empty !
float stack::pop()
{
    cout<<container[top]<<endl;
    top -- ;
     return container[top];
}
/// functionality : Print the data in the container
/// Problem : no check of the container state if it Empty !
void stack::print_stack()
{
    for (int i =top; i<max_size; i++)
        cout<<container[i]<<endl;
}

///  -- //////////* / */////////* / */////////////* / */////// -- ///
/// we make this class to fix some problems founded in the last class called "stack"
class enhanced_stack : public stack
{
   public:

    void push(float data);
    float pop();
    void print_stack();
};

/// functionality : Push the data in the container
/// last Problem (solved) : check of the container state if it Full?
void enhanced_stack::push(float data)
{
   if (top > max_size)
        cout<<"Stack is Full."<<endl;
   else
     stack::push(data);
}

/// functionality : pop the data from the container
/// last Problem (solved) : check of the container state if it Empty?
float enhanced_stack::pop()
{
   if (top <= 0)
     {
       cout<<"Stack is Empty."<<endl;
     }
     else
     {
          return stack::pop();
     }

}

class a7a
{

}a1,a2;
int main()
{
   enhanced_stack a ;
   a.push(10.3);
   a.push(12);
   a.pop(); // 12
   a.pop(); //10.3
   for (int i=0; i<=5;i++)
    a.pop();
   a.pop();
   /*
   enhanced_stack es1;
   es1.push(200);
   es1.pop();
*/
a.pop();a.pop();a.pop();
   cout << "Hello world!" << endl;
return 0;
}
