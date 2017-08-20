#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <iostream>

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
   
   // Connect and Register the Joint State Interface
   hardware_interface::JointStateHandle state_handle_1("joint1", &pos[0], &vel[0], &eff[0]); 
   jnt_state_interface.registerHandle(state_handle_1);

   hardware_interface::JointStateHandle state_handle_2("joint2", &pos[1], &vel[1], &eff[1]); 
   jnt_state_interface.registerHandle(state_handle_2);

   hardware_interface::JointStateHandle state_handle_3("joint3", &pos[2], &vel[2], &eff[2]);	
   jnt_state_interface.registerHandle(state_handle_3);

   registerInterface(&jnt_state_interface);

   // Connect and Register the Joint Position Interface
   hardware_interface::JointHandle pos_handle_1(jnt_state_interface.getHandle("joint1"), &cmd[0]); 
   jnt_pos_interface.registerHandle(pos_handle_1);

   hardware_interface::JointHandle pos_handle_2(jnt_state_interface.getHandle("joint2"), &cmd[1]); 
   jnt_pos_interface.registerHandle(pos_handle_2);

   hardware_interface::JointHandle pos_handle_3(jnt_state_interface.getHandle("joint3"), &cmd[2]); 
   jnt_pos_interface.registerHandle(pos_handle_3);

   registerInterface(&jnt_pos_interface);
 }

  virtual ~scaraBot()
  {}

  void write()
  {
	  std::cout<<"write "<<"  "<<cmd[0]<<" "<<cmd[1]<<std::endl;
  }

  void read()
  {
          std::cout<<"read "<<"  "<<pos[0]<<" "<<pos[1]<<std::endl;
  }

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  double cmd[3];
  double pos[3];
  double vel[3];
  double eff[3];
};
