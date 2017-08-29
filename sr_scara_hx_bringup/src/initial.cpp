#include <QCoreApplication>
#include <iostream>
#include<string>
#include<sstream>

using namespace std;
//using namespace patch;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace patch;

int main(int argc, char *argv[])
{


  string joint="2,0,0,0,0,0,0,70,0\r";
  float a=100.0;
  float b =3.190;
  float c=9.00;
  std::string pi = "pi is " + to_string(3.1415926);

 int length=joint.length();
 int startpoint=length-5;
 string pre=joint.substr(0,startpoint);
 cout<<" length "<<length<<"\n";
 cout<<"startpoint "<<startpoint<<"\n";
 cout<<"prefix "<<pre<<"\n";

 string post=to_string(a)+ "," +to_string(b)+","+to_string(c)+"\r";
 //string a_s=to_string(a);
 string c_output=pre+post;
 cout<<" my string : "<<c_output<<"\n";
 string last3=c_output.substr(startpoint);
 cout<<"last three digit "<<last3<<"\n";








}

