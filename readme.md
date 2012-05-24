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

     _________________
    |                 |
    | /0           1\ |
    |                 |
    |                 |
    |                 |
    |      4 - 5      |
    |                 |
    |                 |
    |                 |
    | \2           3/ |
    |_________________|

## Thrust Vector

Given the arrangement of the bilge pumps the directional control is as follows.

* forward - pumps 0 and 1 on
* reverse - pumps 2 and 3 on
* rotate right - pumps 0 and 3 on
* rotate left - pumps 1 and 2 on
* up - pump 4 on
* down - pump 5 on
* stop - all pumps off

## Arduino Project

Coming soon.  
    