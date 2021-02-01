# godotHandtrack
A program that tracks hand position/rotation/shoot gesture, and sends them via UDP. 


# Usage
Launch the program (an executable) from the commandline with an optional parameter that is the device number of the camera (typically 0, 1, or 2). Get into a dark room and illuminate your left hand with light. Make a gun gesture so that the program could recoginize the orientation of the hand. If you 

# Compile
The program uses cmake. Please install cmake and opencv accroding to   
https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html   
or https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html  

If opencv is installed via `pacman`, please install  `vtk` and `hdf5` packages as well.
