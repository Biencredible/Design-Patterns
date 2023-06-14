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





# Pros & Cons
## Pros:


## Cons:


# Applicability(When to use):



# How to implement:

 
# Relations with other patterns


# Pseudocode Example

