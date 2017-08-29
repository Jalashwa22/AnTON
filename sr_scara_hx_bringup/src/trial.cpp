#include <QCoreApplication>
#include <iostream>
#include <string>
#include <sstream>
//#include <array>

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
using namespace std;

class Eric
{
public:
    string writeR();
    Eric()
    {
        a=9.876;
        b=7.987;
        c=0.334;
        joint="2,0,0,0,0,0,0,70,0\r";

      //cmd[]={7.00,3.88,2.22};
        //cmd = new* float[3] = { 7.00, 3.88, 2.22};



        cmd[0]=7.800;
        cmd[1]=1.700;
        cmd[2]=9.7700;

    }

private:

    float a;
    float b;
    float c;
    float cmd[3];

    string joint;

};

string Eric::writeR()
{
 string cmdString="";
  for(int i=0;i<3;i++){
     cmdString+=to_string(cmd[i]);
     if(i<2)
       cmdString+=",";

  }

   cout<<"The original string is "<<joint<<endl;

    //std::cout<<"write "<<"  "<<cmd[0]<<" "<<cmd[1]<<" "<<cmd[2]<<std::endl;
    int lengthString=joint.length();
    int startpoint=lengthString-5;
    string pre=joint.substr(0,startpoint);
    cout<<" length "<<lengthString<<endl;
    cout<<"startpoint "<<startpoint<<endl;
    cout<<"prefix "<<pre<<endl;

    string post=to_string(a)+ "," +to_string(b)+","+to_string(c)+"\\r";
    string c_output=pre+post;
    cout<<" my string : "<<c_output<<endl;

    cout<<"\n my string : "<<cmdString<<endl;
    c_output=pre+cmdString+"\\r";

    cout<<"\n my string : "<<c_output<<endl;




    return "";

}


int main(int argc, char *argv[])
{

    Eric gamor;
    gamor.writeR();




    QCoreApplication a(argc, argv);

    return a.exec();
}












































