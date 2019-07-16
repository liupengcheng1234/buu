#include "ros/ros.h"
#include "task3/srv1.h"

bool add(task3::srv1::Request &req,
         task3::srv1::Response &res)
{


res.sum = req.A + req.B + req.C;
ROS_INFO("sending back respose : [%ld]",(int)res.sum);
return true;


}
int main(int argc,char** argv)
{

ros::init(argc,argv,"add_3");
ros::NodeHandle n;
ros::ServiceServer service = n.advertiseService("add_3_ints",add);
ros::spin();
return 0;
}
