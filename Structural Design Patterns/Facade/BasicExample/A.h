#pragma once

/*
The Complex Subsystem consists of dozens of various objects. To make them all do something meaningful, you have to dive 
deep into the subsystem's impöementation details, such as initializing objects in the correct order and supplying them
with data in the proper format.
Subsystem classes arent't aware of the facade's existence. They operate within the subsystem and work with each other 
directly.
*/
class A
{
public:
    void callA();
};

