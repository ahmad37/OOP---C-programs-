#include <iostream>
using namespace std;
#include <cmath> // for sqrt()-function

class complex
{
private :
    double re ;
    double im ;

public :
complex () /// first constructor - no parameter
 {
          re =0 ;
          im = 0 ;
 }
complex (double real=0, double imaginary=0) /// second constructor
 {
          re = real;
          im= imaginary;
 }
void show_complex() /// cout<< the private members
 {
          cout<<re<<endl<<im;
 }
void input_complex(complex obj ) /// cin<< the private members
 {
          re = obj.re;
          im = obj.im;
 }

complex add_complex(complex obj) /// Summation of Private members
 {
          /* // Also you code write by this way
          double real = re + obj.re ;
          double ima  = im + obj.im ;
          return complex (real,ima);
          */
          complex result(0,0);  /// creat an object to store the result of sum operations
          result.re = re + obj.re ;  /// add the real part
          result.im = im + obj.im ;  /// add the imaginary part
          return result ;       /// return with an object which carry the new complex number
 }

complex sub_complex(complex obj) /// Subtraction of Private members
 {
          /*
          double real = re + obj.re ;
          double ima  = im + obj.im ;
          return complex (real,ima);
          */

          complex result(0,0);  /// creat an object to store the result of sub operations
          result.re = re - obj.re ;  /// sub the real part
          result.im = im - obj.im ;  /// sub the imaginary part
          return result ;       /// return with an object which carry the new complex number
 }
/// Multiplication of Private members
complex mul_complex(complex obj)
 {
          complex result(0,0) ;
          result.re = (re*obj.re) - (im * obj.im) ;
          result.im = (re*obj.im) + (obj.re * im);
          return result ;
 }
complex div_complex(complex obj)
 {
          double den ;
          den = (obj.re*obj.re)+(obj.im*obj.im);

          complex num(0,0);
          num.re = (re*obj.re) - (im*(-obj.im));
          num.im = (re*(-obj.im)) + (im*obj.re);

          complex result(0,0);
          result.re = num.re / den;
          result.im = num.im / den;

          return result;
 }
double  magnitude_complex()
 {
          double result = re*re + im*im ;

          return sqrt(result) ;
 }

/*****OverLoading Operators{How To deal with the Objects as a normal Variables!}******/
/*
Overloading is very powerful feature in OOP - make the Code more easy to read,write and
save time in writing or debug the code.
with overloading operator you can make any Arithmatic or Logical operations directly
like a built-in variable ( int , float , ..etc).
you can add object+object Directly or Sub,Mul,Div,++prefix,postfix++,<,>,=<,>= ...etc
//////////
Example :
/// creating an object of Class(complex) /////
    Complex obj1 , obj2 , obj3 ;
      obj3= obj1+obj2 ;
*/
/*****Declarations of Functions*******/

complex operator++(); /// prefix operation
complex operator++(int); /// prefix operation
complex operator+(complex obj); ///Summation Operation
complex operator-(complex obj); ///Subtraction Operation
complex operator*(complex obj); ///Multiplication Operator
complex operator/(complex obj); ///Division operator
void operator+=(complex obj);
void operator-=(complex obj);
void operator*=(complex obj);
void operator/=(complex obj);
bool operator<(complex obj);
bool operator>(complex obj);
bool operator<=(complex obj);
bool operator>=(complex obj);
bool operator==(complex obj);
bool operator!=(complex obj);

///TO OVERLOADING ON COUT<< AND CIN>> OPERATION WE MUST USE THE FRIEND FUNCTIONS ////
friend istream& operator>>(istream& , complex&);  /// cin>>  overloading
friend ostream& operator<<(ostream& , complex&);  /// cout<< overloading

/// Overloading on [] brackets - to deals with objects like arrays!!!?

};
complex complex::operator++()
 {
   complex _prefix(0,0);
   _prefix.re = ++re;
   _prefix.im = ++im;
    return _prefix;
 }
complex complex::operator++(int)
 {
    complex _postfix(0,0);
    _postfix.re = ++re;
    _postfix.im = ++im;
    return _postfix;
 }

complex complex::operator+(complex obj)
 {  complex result(0,0);
    result.re = re+obj.re;
    result.im = im+obj.im;
    return result ;
 }
complex complex::operator-(complex obj)
 {  complex result(0,0);
    result.re = re-obj.re;
    result.im = im-obj.im;
    return result ;
 }

complex complex::operator*(complex obj)
 {
    complex result(0,0);
    result.re= (re*obj.re)-(im*obj.im);
    result.im= (re*obj.im)+(obj.re*im);
    return result;
 }
complex complex::operator/(complex obj)
 {

    double den ;
    den = (obj.re*obj.re)+(obj.im*obj.im);

    complex num(0,0);
    num.re = (re*obj.re) - (im*(-obj.im));
    num.im = (re*(-obj.im)) + (im*obj.re);

    complex result(0,0);
    re = num.re / den;
    im = num.im / den;

    return result;
 }
void complex::operator+=(complex obj)
 {
    re = re+obj.re;
    im = im+obj.im;
 }
void complex::operator-=(complex obj)
 {
    re = re-obj.re;
    im = im-obj.im;
 }
void complex::operator*=(complex obj)
 {
    re = (re*obj.re) - (im*obj.im);
    im = (re*obj.im) + (im*obj.re);
 }
void complex::operator/=(complex obj)
 {  double den ;
    den = (obj.re*obj.re)+(obj.im*obj.im);

    complex num(0,0);
    num.re = (re*obj.re) - (im*(-obj.im));
    num.im = (re*(-obj.im)) + (im*obj.re);

    complex result(0,0);
    re = num.re / den;
    im = num.im / den;
 }
bool complex::operator<(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1<mag2)
        return true;
    else
        return false;

   ///YOU CAN SHORT THIS FUNCTION IN ONE LINE OF CODE
   /// return mag()<obj.mag();
 }
bool complex::operator>(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1>mag2)
        return true;
    else
        return false;

   ///YOU CAN SHORT THIS FUNCTION IN ONE LINE OF CODE
   /// return mag()>obj.mag();
 }
bool complex::operator<=(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1<=mag2)
        return true;
    else
        return false;

   ///YOU CAN make THIS FUNCTION SHORT IN ONE LINE OF CODE
   /// return mag()<=obj.mag();
 }
 bool complex::operator>=(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1>=mag2)
        return true;
    else
        return false;

   ///YOU CAN SHORT THIS FUNCTION IN ONE LINE OF CODE
   /// return mag()>=obj.mag();
 }
 bool complex::operator==(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1==mag2)
        return true;
    else
        return false;

   ///YOU CAN SHORT THIS FUNCTION IN ONE LINE OF CODE
   /// return mag()==obj.mag();
 }
 bool complex::operator!=(complex obj)
 {
    double mag1 = magnitude_complex();
    double mag2 = obj.magnitude_complex();
    if(mag1!=mag2)
        return true;
    else
        return false;

   ///YOU CAN SHORT THIS FUNCTION IN ONE LINE OF CODE
   /// return mag()!=obj.mag();
 }

///this a friend function to class complex{}; , you don't need to write complex:: any more
//this function must have two input and return a value of type istream{};
// istream is a built-in class in library <iostream>, used to print a data or messages on consol screen
// then, cout<<  is an object of class iostream{};
istream& operator>>(istream& xin , complex& obj )
{
    xin>>obj.re;
    xin>>obj.im;
    return xin;
}
///this a friend function to class complex{}; , you don't need to write complex:: any more
ostream& operator<<(ostream& xin , complex& obj )
{
    xin<<obj.re;
    xin<<obj.im;
    return xin;
}
/*
class in : public complex
{

};
*/

int main()
{
   complex c1(1,2) , c2(3,4) , c3(0,0) , x(2,-6) ;
//   in a;
   /// prefix operation /////////////////////////
   ++x;
   c3= ++x;
   x.show_complex();
   cout<<endl;
   /// postfix operation ///////////////////////
   x++;
   c3=x++;
   x.show_complex();
   cout<<endl;

   /// += operator ///////////////////////////
   c2+=c1;
   c2.show_complex();
   cout<<endl;

   /// -= operator ///////////////////////////
   c2-=c1;
   c2.show_complex();
   cout<<endl;

   /// *= operator ///////////////////////////
   c2*=c1;
   c2.show_complex();
   cout<<endl;

   /// /= operator ///////////////////////////
   c1/=x;
   c1.show_complex();
   cout<<endl;

   /// < smaller than operator //////////////
   if(c1<c2)
     cout<<" it's true! < "<<endl;

   /// < smaller than operator //////////////
   if(c1>c2)
     cout<<" it's true! > "<<endl;

/**-----------------------------------------------------------------------------------------------------*/
    cout <<endl<<"******Before overloading*******ADD COMPLEX**************************************"<<endl;
    c3 = c1.add_complex(c2);
    c3.show_complex() ;
    cout <<endl<<"******After overloading*******ADD COMPLEX**************************************"<<endl;
                  c3=c1+c2;
                  c3.show_complex();
                  cout<<endl;
/**-----------------------------------------------------------------------------------------------------*/
    cout <<endl<<"*******Before overloading*******SUB COMPLEX**************************************"<<endl;
    c3 = c1.sub_complex(c2);
    c3.show_complex() ;
    cout <<endl<<"******After overloading*******SUB COMPLEX**************************************"<<endl;
                  c3=c1-c2;
                  c3.show_complex();
                  cout<<endl;
/**-----------------------------------------------------------------------------------------------------*/
    cout <<endl<<"*******Before overloading*******MUL COMPLEX**************************************"<<endl;
    c3 = c1.mul_complex(c2);
    c3.show_complex();
    cout <<endl<<"*******After overloading*******MUL COMPLEX**************************************"<<endl;
                  c3=c1*c2 ;
                  c3.show_complex();
                  cout<<endl;
/**-----------------------------------------------------------------------------------------------------*/
    cout <<endl<<"*******Before overloading*******DIV COMPLEX**************************************"<<endl;
    c3 = c1.div_complex(c2);
    c3.show_complex();
    cout <<endl<<"*******After overloading*********DIV COMPLEX**************************************"<<endl;
                  c3=c1/c2 ;
                  c3.show_complex();
                  cout<<endl;
/**-----------------------------------------------------------------------------------------------------*/
    cout <<endl<<"*******MAGNITUDE OF COMPLEX NUMBER *********************"<<endl;
    double magnitude =  c1.magnitude_complex();
    cout << magnitude <<endl ;
/**-----------------------------------------------------------------------------------------------------*/
/// overloading on cin>> and cout<< with objects :D ///
    cin>>c3;
    cout<<c3;
/**-----------------------------------------------------------------------------------------------------*/
   cout <<endl<<"**************THANK YOU AHMAD *********************"<<endl;
 ///   cout << "Hello world!" << endl;
    return 0;
}
