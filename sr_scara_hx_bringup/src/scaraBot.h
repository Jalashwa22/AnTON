#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <iostream>
#include <string>
#include <sstream>

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


class scaraBot : public hardware_interface::RobotHW
{
public:
    scaraBot()
    {
        cmd[0]=0;
        cmd[1]=0;
        cmd[2]=0;
        pos[0]=0;
        pos[1]=0;
        pos[2]=0;
        eff[0]=0;
        eff[1]=0;
        eff[2]=0;
        sendCommand="2,0,0,0,0,0,0,0,0\r";
        receiveCommand="4,0,0,0,0,0,0,0,0\r";
        
        // Connect and Register the Joint State Interface
        hardware_interface::JointStateHandle state_handle_1("joint1", &pos[0], &vel[0], &eff[0]); 
        jnt_state_interface.registerHandle(state_handle_1);
        
        hardware_interface::JointStateHandle state_handle_2("joint2", &pos[1], &vel[1], &eff[1]); 
        jnt_state_interface.registerHandle(state_handle_2);
        
        hardware_interface::JointStateHandle state_handle_3("joint3", &pos[2], &vel[2], &eff[2]);	
        jnt_state_interface.registerHandle(state_handle_3);
        
        registerInterface(&jnt_state_interface);
        
        
        // Connect and Register the Joint Position Interface
        hardware_interface::JointHandle handle_1(jnt_state_interface.getHandle("joint1"), &cmd[0]); 
        jnt_pos_interface.registerHandle(handle_1);
        jnt_eff_interface.registerHandle(handle_1); 
        
        hardware_interface::JointHandle handle_2(jnt_state_interface.getHandle("joint2"), &cmd[1]); 
        jnt_pos_interface.registerHandle(handle_2);
        jnt_eff_interface.registerHandle(handle_2); 
        
        hardware_interface::JointHandle handle_3(jnt_state_interface.getHandle("joint3"), &cmd[2]); 
        jnt_pos_interface.registerHandle(handle_3);
        jnt_eff_interface.registerHandle(handle_3); 
        
        registerInterface(&jnt_pos_interface);
        registerInterface(&jnt_eff_interface);
    }
    
    virtual ~scaraBot()
    {}
    
    
private:
    hardware_interface::JointStateInterface jnt_state_interface;
    hardware_interface::PositionJointInterface jnt_pos_interface;
    hardware_interface::VelocityJointInterface jnt_vel_interface;
    hardware_interface::EffortJointInterface jnt_eff_interface;
    double cmd[3];
    double pos[3];
    double vel[3];
    double eff[3];
    string sendCommand;
    string receiveCommand;
};


string scaraBot::writeR()
{
    
    string cmdString="";
    for(int i=0;i<3;i++){
        cmdString+=to_string(cmd[i]);
        if(i<2)
            cmdString+=",";
    }
    
    
    cout<<"write "<<"  "<<cmd[0]<<" "<<cmd[1]<<" "<<cmd[2]<<endl;
    int lengthString=sendCommand.length();
    int startpoint=lengthString-5;
    string pre=sendCommand.substr(0,startpoint);
    // cout<<" length "<<length<<"\n";
    // cout<<"startpoint "<<startpoint<<"\n";
    // cout<<"prefix "<<pre<<"\n";
    
    //string post=to_string(a)+ "," +to_string(b)+","+to_string(c)+"\r";
    // string c_output=pre+post;
    // cout<<" my string : "<<c_output<<"\n";
    
    c_output=pre+cmdString+"\\r";
    
    cout<<"\n my string : "<<c_output<<endl;
    
    return "";
    
    
}

int ScaraBot::readeR()
{
    std::cout<<"read "<<"  "<<pos[0]<<" "<<pos[1]<<std::endl;
}


