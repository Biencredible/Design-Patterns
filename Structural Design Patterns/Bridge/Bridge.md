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
* You can create platform-independent classes and apps.
* The client code works with high-level abstractions. It isn't exposed to the platform details.
* Open/Closed Principle. You can introduce new abstract implementations independently from each other.
* Single Responsibility Priciple. You can focus on high-level logic in the abstraction and on platform details in the 
implementation.


## Cons:
* You might make the code more complicated by applying the to a highly cohesive class.


# Applicability(When to use):
* Use the bridge design pattern when you want to divide and organize a monolithic class that has several variants of
some functionality.
The bigger a class becomes, the harder it is to figure out how it works, and the longer it takes to make a change. The
changes across the whole class, which often results in making errors or not addressing some critical side effects.
The Bridge pattern lets you split the monolithic class into several class hierarchies. After this, you can change the 
classes in each hierarchy independently of the classes in the others. This approach simplifies code maintenance and 
minimizes the risk of breaking existing code.
* Use the pattern when you need to extend a class in several orthogonal (independent) dimensions.
The bridge suggests that you extract a seperate class hierarachy for each of the dimensions. THe original class
delegates the related work to the objects belongiong to those hierarchies instead of doing everything on its own.
* Use the Bridge if you need to be able to switch implementation at runtime.
Although it's optional, the Bridge pattern lets you replace the implementation object inside the abstraction. It's as 
easy as assigning a new value to a field.
By the way, this last item is the main reason why so many people confuse the Bridge with the **Strategy** pattern. 
Remember that a pattern is more than just a certain way to structure your classes. It may also communicate intent and a
problem being addressed.


# How to implement:
1. Identify the orthogonal dimensions in your classes. These independent concepts could be: abstraction/platform,
domain/infrastructure, front-end/back-end, or interface/implementation.
2. See what operations the client needs and define them in the base abstraction class.
3. Determine the operations available on all platforms. Declare the ones that the abstraction needs in the general
implementation interface.
4. For all platforms in your domain create concrete implementation classes, but make sure they all follow the 
implementation interface.
5. Inside the abstraction class, add a refrence field for the implementation type. The abstraction delegates most of the
work to the implementation object that's referenced in that field.
6. If you have several variants of high-level logic, create refined abstraction for each variant by extending the base 
abstraction class.
7. The client code should pass an implementation object to the abstraction's constructor to associate one with the 
other. After that, the client can forget about the implementation and work with the abstraction object.

 
# Relations with other patterns
* **Bridge** is usually designed up-front, lettin you develop parts of an application independently of each other. On 
the other hand, **Adapter** is commonly used with an existing app tp make some otherwise-incompatible classes work 
together nicely.
* **Bridge**, **State**, **Strategy** (And to degree **Adapter**) have very similar structures. Indeed, all of these 
patterns are based on composition, which is delegating work to other objects. However, they all solve different 
problems. A pattern isn't just a recipe for structuring your code ina specific way. It can also communicate to other 
developers the problem the pattern solves.
* You can use **Abstract Factory** along with **Bridge**. This pairing is useful when some abstractions defined by 
*Bridge* can only encapsulate these relations and hide the complexity from the client code.
* You can combine **Builder** with **Bridge**: the director class plays the role of the abstraction, while different 
builders act as implementations.


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


