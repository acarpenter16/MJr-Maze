//Diagonal movement vital to win

#include <MeggyJrSimple.h>

int xdot=0; //declaring variables for x+y coor w/ initial values
int ydot=0;

int xgoal=3; //ending pt
int ygoal=6;

void setup ()
{
  MeggyJrSimpleSetup();
}

void loop ()  
{
  
  ClearSlate();
  
  CheckButtonsDown();
  
    if (Button_Up)        
    ydot=ydot+1; //if up pressed, increase y coor by 1 

  if (ydot>7) //avoid bug if the dot goes offscreen
    ydot=7;

  if (Button_Down)       
    ydot=ydot-1; //down pressed, decrease y by 1 
    
  if (ydot<0) //avoid bug if the dot goes offscreen
    ydot=0;

  if (Button_Right)       
    xdot=xdot+1; //right pressed, increase x coor by 1 
    
  if (xdot>7) //avoid bug if the dot goes offscreen
    xdot=7;

  if (Button_Left)       
    xdot=xdot-1; //left pressed, decrease x by 1

  if (xdot<0) //avoid bug if the dot goes offscreen
    xdot=0;
    
  DrawPx(xdot, ydot, 12);
  DrawPx(xgoal, ygoal, Green);
  
  DrawPx(0,4,1);
  DrawPx(0,5,1);
  DrawPx(0,7,1);
  DrawPx(1,1,1);
  DrawPx(1,2,1);
  DrawPx(1,3,1);
  DrawPx(1,7,1);
  DrawPx(2,3,1);
  DrawPx(2,4,1);
  DrawPx(2,5,1);
  DrawPx(2,6,1);
  DrawPx(2,7,1);
  DrawPx(3,3,1);
  DrawPx(3,5,1);
  DrawPx(4,1,1);
  DrawPx(4,2,1);
  DrawPx(4,3,1);
  DrawPx(4,6,1);
  DrawPx(5,0,1);
  DrawPx(5,4,1);
  DrawPx(6,0,1);
  DrawPx(6,4,1);
  DrawPx(6,5,1);
  DrawPx(6,6,1);
  DrawPx(6,7,1);
  DrawPx(7,0,1);
  DrawPx(7,1,1);
  DrawPx(7,2,1);

  if(ReadPx(xdot,ydot)==Red) //Code for dot+wall collision
    {
      xdot=0;
      ydot=0;
    }
    
  if(ReadPx(xdot,ydot)==Green) //Code for post-goal image
    {
      ClearSlate();
      DrawPx(0,1,Violet);
      DrawPx(0,2,Violet);
      DrawPx(0,3,Violet);
      DrawPx(1,1,Violet);
      DrawPx(1,5,Violet);
      DrawPx(1,6,Violet);
      DrawPx(2,1,Violet);
      DrawPx(2,5,Violet);
      DrawPx(2,6,Violet);
      DrawPx(3,1,Violet);
      DrawPx(4,1,Violet);
      DrawPx(5,1,Violet);
      DrawPx(5,5,Violet);
      DrawPx(5,6,Violet);
      DrawPx(6,1,Violet);
      DrawPx(6,5,Violet);
      DrawPx(6,6,Violet);
      DrawPx(7,1,Violet);
      DrawPx(7,2,Violet);
      DrawPx(7,3,Violet);
    }

  DisplaySlate();
  delay(300);
  
}

