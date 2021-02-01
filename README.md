# godotHandtrack
A program that tracks hand position/rotation/shoot gesture, and sends them via UDP.  
![Image of Handtrack](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/fe4195d8-4177-4ac4-b187-edf0ff0e1c23/image0.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAT73L2G45O3KS52Y5%2F20210201%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20210201T221739Z&X-Amz-Expires=86400&X-Amz-Signature=930abe9aa1a6afcc4ee347dd35f53eeda4d8eb84460d2bc481d43ac33223c4ca&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22image0.png%22)

# Usage
Launch the program (an executable) from the commandline with an optional parameter that is the device number of the camera (typically 0, 1, or 2). Get into a dark room and illuminate your left hand with light. Make a gun gesture so that the program could recoginize the orientation of the hand.  
The program sends a string to the UDP port 
# Compile
The program uses cmake. Please install cmake and opencv accroding to   
https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html   
or https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html  

If opencv is installed via `pacman`, please install  `vtk` and `hdf5` packages as well.
