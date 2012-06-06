# PinkSubmarine

PinkSubmarine is a project for my daughters.  The idea is simple.  Create an underwater ROV that will film the 
world beneath the waves.

The project came about because they wanted to "build something" that was cool.  I figured rockets would do the trick,
but after a fairly complicated wood working project they weren't interested in building a rocket in two hours that would fly for 30 seconds.  So the ROV came up.  It has a lot to offer them.  To complete it, they will learn more basic building techniques, they'll learn physics (buoyency, thrust), basic electronics (wiring of the motors), and basic embedded programming.  And they'd learn to type.  It has all the components.

However, they mandated that it had to be painted pink not yellow!

## The Arduino Link

The ROV will be constructed with PVC pipe in a more or less cube shape.  It will be manuevered by 6 small marine bilge pumps.  Four pumps will be mounted roughly on the corners pointing outward and backwards at a 45 degree angle.

The diagram below roughly outlines how this will work.  Each number represents a bilge pump connected to an output pin
on the Arduino board.  The slashed indicate what direction the pump will pump.

     ____________________
    |                     |
    |    /           \    |
    | | /  2       3  \ | |
    | |__             __| |
    |                     |
    |                     |
    |        6 - 7        |
    |                     |
    |  __             __  |
    | |\               /| |
    | | \  4        5 / | |
    |_____________________|

## Thrust Vectors

Given the arrangement of the bilge pumps the directional control is as follows.

* forward - pumps 2 and 3 on
* reverse - pumps 4 and 5 on
* rotate right - pumps 2 and 5 on
* rotate left - pumps 3 and 4 on
* up - pump 4 on
* down - pump 5 on
* stop - all pumps off

## Arduino Project

The Arduino IDE installer creates a directory in your user's home document directory name "Arduino".

Clone this repository there so you end up with the following directory structure.

    <user_home>/Documents/Arduino/readme.md
    <user_home>/Documents/Arduino/pink_submarine
    <user_home>/Documents/Arduino/pink_submarine/pink_submarine.ino
    <user_home>/Documents/Arduino/libraries/PinkSubmarineLib/PinkSubmarine.h
    <user_home>/Documents/Arduino/libraries/PinkSubmarineLib/PinkSubmarine.cpp
    <user_home>/Documents/Arduino/libraries/WiiChuck/WiiChuck.h
    <user_home>/Documents/Arduino/libraries/WiiChuck/WiiChuck.cpp

Launch your Arduino IDE, load the file named pink_submarine, install and run on your Arduino Uno Rev 3.
    
    