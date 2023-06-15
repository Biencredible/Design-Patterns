# Intent:
Lets you split a large class or a set of closely related classes into two separate hierachies-abstraction and 
implementation- which can be developed independently of each other.


# Example Problem:
You have a generic *Shape* class with a pair of subclasses: *Circle* and *Square*. This class hierachy has to be 
extended to incorporate colors, so *Red* and *Blue* subclasses are created. However, since there are already two 
subclasses, class combinations need to be created like *BlueCircle* and *RedSquare*. The hierarchy will grow 
exponentially by adding a range of subclasses for each color and each shape.

# Solution: 
Bridge pattern solves this by switching from inheritance to object composition. The color-related code can be extracted 
into its own class with two subclasses: *red* and *Blue*. The *SHape* class then gets a reference field pointing to one 
of the color objects. Now the shape can delegate any color-related work to the linked color object. That reference will 
act as a bridge between *Shape* and *Color* classes. From now on, adding new colors won't require changing the shape 
hierarchy, and vice versa.


# Components:
![image info](./structure-en.png)
* **Abstraction**: Provides high-level control logic. It relies on the implementation object to do the actual low-level
work.
* **Implementation**: declares the interface that's common for all concrete implementations. An abstraction can only 
communicate with an implementation object via methods that are declared here. 
The abstraction may list the same methods as the implementation, but usually the abstraction declares some complex 
behaviors that rely on a wide variety of primitive operations declared by the implementation.
* **Concrete Implementation**: contains platform specific code.
* **Refined Abstraction**: provides variants of control logic. Like their parent, they work with different 
implementations via the general implementation interface. 

# Pros & Cons
## Pros:


## Cons:


# Applicability(When to use):



# How to implement:

 
# Relations with other patterns


# Pseudocode Example

This example illustrates how the **Bridge** design pattern can help divide the monolithic code of an app that manages 
devices and their remote controls. The device classes act as the implementation, whereas the Remotes act as the 
abstraction.

![image info](./example-en.png)

The base remote control class declares a reference field that links it with a device object. All that's needed is to 
create a new remote subclass. For example, a basic remote control might only have two buttons, but you courld extend it 
with additional features, such as an extra battery or touchscreen.

The client code linkes the desired type of remote control with a specific device object via the remote's constructor.

    // The "abstraction" defines the interface for the "control" part of the two class hierachies. It maintains a
    // reference to an object of the "implementation" hierachy and delegates all of the ral work to this object.
    class RemoteControl is
        protected field device: Device
        constructor field RemoteControl(device: Device) is
            this.device = device
        method togglePower() is
            if(device.isEnabled()) then
                device.disable()
            else
                device.enable()

        method volumeDown() is
            device.setVolume(device.getVolume() - 10)
        method volumeUp()
            device.setVolume(device.getVolume() + 10)
        method channelDown() is
            device.setChannel(device.getChannel() - 1)
        method channelUp() is
            device.setChannel(device.getCHannel() + 1)

    // You can extend classes from the abstraction hierarchy independently from device classes.
    class AdvancedRemoteControl extends RemoteControl is 
        method mute() is
            device.setVolume(0)

    // The "implementation" interface declares methods common to all concrete implementation classes. It doesn't have
    // to match the abstraction's interface. In fact, the two interfaces can be entirely different. Typically the 
    // implementation interface provides only primitive operations, while the abstraction defines higher-level 
    // operations based on those primitives.
    interface Device is
        method isEnabled()
        method enable()
        method disable()
        method getVolume()
        method setVolume(percent)
        method getChannel()
        method setChannel(percent)

    // All devices follow the same interface.
    class Tv implements Device is
        // ...

    class Radio implements Device is
        // ...

    // Somewhere in client code
    tv = new Tv()
    remote = new RemoteControl(tv)
    remote.togglePower()

    radio = new Radio()
    remote = new AdvancedRemoteControl(radio)


