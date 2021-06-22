# godotHandtrack
A program that tracks hand position/rotation/shoot gesture, and sends them via UDP.  
![Image of Handtrack](https://github.com/revanj/UDPHandtrack/blob/main/readme-images/image0.png)

# Usage
Launch the program (an executable) from the commandline with an optional parameter that is the device number of the camera (typically 0, 1, or 2). Get into a dark room and illuminate your left hand with light. Make a gun gesture so that the program could recoginize the orientation of the hand. You should see some bars with handles that were used to control the thresholding. You could mess around with them a bit to make sure that the Object Detection window properly shows your hand in one single white chunk.
  
## The release build:
(Windows after unzip)> `handtrack_win.exe 2` starts the program with camera #2  
(Linux with OpenCV properly installed)> `./handtrack_linux_executable 0` starts the program with camera #0  
Pick the camera that you would like to use.
  
**The program sends a string to via UDP to port 9000**   
  
The data is a string of data seperated by space, in the order below:  
`shoot`: whether or not the hand is making a "shoot" gesture.  
`index_x`: the x position of the tip of the index finger on screen, in pixels.  
`index_y`: the y position of the tip of the index finger on screen, in pixels.  
`thumb_x`: the x position of the tip of the thumb on screen, in pixels.  
`thumb_y`: the y position of the tip of the thumb on screen, in pixels.  
`curlicue_x`: the x position of the curlicue point on screen, in pixels.  
`curlicue_y`: the y position of the curlicue point on screen, in pixels.  
  
Typically the "shoot" gesture looks like this(ducking your thumb):  
![Image of Shoot](https://github.com/revanj/UDPHandtrack/blob/main/readme-images/image.png)  
  
Use these data as you'd please.  

# Compile
The program uses cmake. Please install cmake and opencv according to   
https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html   
or https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html  

If opencv is installed via `pacman`, please install  `vtk` and `hdf5` packages as well.  

After correct installation of opencv, the program should compile in a cmake-ready environment.(Visual Studio, CLion, VSCode... etc. or just a naked environment)
