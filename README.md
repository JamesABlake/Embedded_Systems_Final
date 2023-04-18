# Embedded Systems Final

Description:
  Re-create Worm using the Dot Matrix as a display and the JoyStick as input.

Group: 
  James Blake - Everything

Components:
  Dot Matrix
  JoyStick

Libraries:
  MD_MAX72XX

Context Diagram:
  JoyStick <-> Arduino <-> Dot Matrix

Sequence Diagram:
  I = Initialization
  L = Loop

  J   A   D
      I==>|
  |<==L
  |-->L
      L==>|

Transition Functions:
  JoyStick & Arduino
    ButtonDown()

  Arduino & Dot Matrix
    begin()
    control(...);
    setBuffer(...);