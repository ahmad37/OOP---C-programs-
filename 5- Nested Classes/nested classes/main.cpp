#include <iostream>

using namespace std;

/// Normal Class //////////////////////////////////
class A
{
  protected:
      int a1;

  public:
   void pp()
   {
       cout<<"father"<<endl;
   }
};

/// class B -
class B
{

public:

 ///Nested Class A inside Class B
      class A
       {
         protected:
                int a1;

         public:
              void pp()
                  {
                    cout<<"father"<<endl;
                  }
        }b; /// b is a global object of class A
//////////////////////////////////////
  void pz()
    {
        cout<<"son"<<endl;
    }
}X;  /// X is a global object of class B


int main()
{

     X.pz();
     X.b.pp();

    cout << "Hello world!" << endl;
    return 0;
}
