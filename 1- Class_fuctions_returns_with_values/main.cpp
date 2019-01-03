#include <iostream>
#include <cmath>
using namespace std;

class complex
{
private :
    double re ;
    double im ;

public :
    complex ()
    {
        re =0 ;
        im = 0 ;
    }
    complex (double real=0, double imaginary=0)
    {
        re = real;
        im= imaginary;
    }
   void show_complex()
     {
         cout<<re<<endl<<im;
     }
   void  input_complex(complex obj )
     {
       re = obj.re;
       im = obj.im;
     }

complex add_complex(complex obj)
{
          /*
          double real = re + obj.re ;
          double ima  = im + obj.im ;
          return complex (real,ima);
          */

          complex result(0,0);  // creat an object to store the result of sum operations
          result.re = re + obj.re ;  // add the real part
          result.im = im + obj.im ;  // add the imaginary part
          return result ;       // return with an object which carry the new complex number
}

complex sub_complex(complex obj)
{
          /*
          double real = re + obj.re ;
          double ima  = im + obj.im ;
          return complex (real,ima);
          */

          complex result(0,0);  // creat an object to store the result of sub operations
          result.re = re - obj.re ;  // sub the real part
          result.im = im - obj.im ;  // sub the imaginary part
          return result ;       // return with an object which carry the new complex number
}

 complex  mul_complex(complex obj);
 double magnitude_complex();

};

complex  complex::mul_complex(complex obj)
{
    complex result(0,0) ;
    result.re = (re*obj.re) - (im * obj.im) ;
    result.im = (re*obj.im) + (obj.re * im);
    return result ;
}

double complex::magnitude_complex()
{
 double result = re*re + im*im ;

    return sqrt(result) ;
}

int main()
{
   complex c1(1,2) , c2(3,4) , c3(0,0) ;

    cout <<endl<<"*************ADD COMPLEX**************************************"<<endl;
    c3 = c1.add_complex(c2);
    c3.show_complex() ;

   cout <<endl<<"**************SUB COMPLEX**************************************"<<endl;
    c3 = c1.sub_complex(c2);
    c3.show_complex() ;

   cout <<endl<<"**************MUL COMPLEX**************************************"<<endl;
    c3 = c1.mul_complex(c2);
    c3.show_complex();

   cout <<endl<<"**************MAGNITUDE OF COMPLEX NUMBER *********************"<<endl;
    double magnitude =  c1.magnitude_complex();
    cout << magnitude <<endl ;
   cout <<endl<<"**************THANK YOU AHMAD *********************"<<endl;
 //   cout << "Hello world!" << endl;
    return 0;
}
