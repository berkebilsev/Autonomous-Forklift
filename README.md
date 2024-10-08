The processing of the data is achieved as follows: Encoder data from the motors is obtained using the Orion board. 
Based on this data, forward and inverse kinematic calculations specific to mecanum wheels are performed on the Raspberry Pi. 
The resulting wheel movements are then transmitted to the main PC via ROS for autonomous navigation.
