// adapted coded: http://learningprocessing.com/examples/chp17/example-17-03-scrollingtext, http://learningprocessing.com/examples/chp14/example-14-16-solar-system
import processing.serial.*;
import java.util.ArrayList;
import java.util.List;
Serial myPort;
String val;      // Data received from the serial port
float xPos = 0; // horizontal position of the graph
float yPos = 0;
float theta = 0;
float thetaWord = 0;
int x,y,z = 0;
int sunSize = 50;
String message = "Protect the Planet :)";
int changeTheta = 0;


String[] headlines = {
  "Protect the Planet :)", 
};

PFont f; // Global font variable
float x_; // Horizontal location
int index = 0;

void setup () {
  size(1400, 800);// window size
  String portName = "/dev/cu.wchusbserial54250292061";
  myPort = new Serial(this, portName, 115200);
  f = createFont("Arial", 60);
  x_ = width;
 
}


void draw () {
  
  background(0);
  stroke(0);
  
 
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
    if(val != null){
    String vals[] = split(val, ",");
    x = int(vals[0]);
    y = int(vals[1]);
    z = int(vals[2]);
    System.out.println("X IS " + x);
    System.out.println("Y IS " + y);
    System.out.println("Z IS " + z);
    System.out.print(height);
      
    }

  }
  
  if (val != null && val.equals("0")) {              // If the serial value is 0,
    fill(0);                   // set fill to black
  } 
  
  //if button is pressed
  if( z == 0){
    // Display headline at x location
    textFont(f, 30);
    textAlign (LEFT);
  
    // A specific String from the array is displayed according to the value of the "index" variable.
    text(headlines[index], x_, height-20); 
  
    // Decrement x
    x_ = x_ - 3;
  
    // If x is less than the negative width, then it is off the screen
    // textWidth() is used to calculate the width of the current String.
    float w = textWidth(headlines[index]); 
    if (x_ < -w) {
      x_ = width;
      // index is incremented when the current String has left the screen in order to display a new String.
      index = (index + 1) % headlines.length;
    }
  }  
  
  // Translate to center of window to draw the sun.
  translate(width/2, height/2);
  fill(255, 200, 50);
  ellipse(0, 0, sunSize, sunSize);
   
   if(sunSize > 350){
    System.out.println(message);
    fill(255);
    text(message, 100, 100);
    
  }
  if(x == 1947){
    sunSize +=0;
  }
  else if(x > 2500){
    sunSize += 2;
  }
  
  else if(x < 1800){
    sunSize -= .0005;
    
  }
  // The earth rotates around the sun
  pushMatrix();
  
  rotate(theta);
  if(y == 2000){
    rotate(theta);
  }
  else if(y > 2500){
    changeTheta += 1;
    rotate(theta * changeTheta);
  }
  
  else if(y < 1950){
  changeTheta -= 1;
  rotate(theta * changeTheta);
  }
  
  translate(200, 100);
  fill(50, 200, 255);
  ellipse(0, 0, 25, 25);

  // Moon #1 rotates around the earth
  // pushMatrix() is called to save the transformation state before drawing moon #1. 
  // This way we can pop and return to earth before drawing moon #2. 
  // Both moons rotate around the earth (which itself is rotating around the sun).
  pushMatrix(); 
  rotate(-theta*4);
  translate(36, 0);
  fill(50, 255, 200);
  ellipse(0, 0, 12, 12);
  popMatrix();
  

  popMatrix();
  
  theta += 0.01;
}
