# Intent:
Convert the interface of a class into another interface clients expect. **Adapter** lets class work together that couldn't
otherwise because of incompatible interfaces.

# Example Problem:
Stock market monitoring app downloads sources in XML format and displays them as diagrams and charts. Improvements
are possible by sing a 3rd-party analytics library, but that provides its data in JSON format. Changing the 3rd-party
library might not wirk, because you might break the existing code or you might not have access.

## Solution: 
Write an **Adapter**, that converts JSON files into XML files and vice versa, to make communication between your app and 
the 3rd party library possible.

# Implement through Composition or Inheritance
## Composition:
**Adapter** composes adaptee and calls its method through a reference/pointer

## Inerhitance:
**Adapter** inherits from the adaptee and calls the methods directly

# Components:
![image info](./structure-object-adapter.png)
* **Target**: The interface the client is using.
* **Client**: Works with objects, which interfaces are the same as target.
* **Adaptee**: Class with incompatible interface
* **Adapter**: Adapts interface of adaptee to the interface of target.

# Pros & Cons
## General Pros:
- Sinngle Responsibility. The interface or data conversion can be separated from the business logic.
- Open/Closed Principle. New types can be introduced into the program without breaking existing client code.

## General Cons:
- Overall complexity increases, because new interfaces and classes need to be introduced. Sometimes it's simpler to 
    change the adaptee to match the rest of the code.

## Object Adapter
### Pros:
- One **Adapter** can work with multiple classes (even subclasses of adaptee).
- Can always adapt to an existing class.

### Cons:
- Cannot override adaptee's behavior.
- Methods are invoked through a pointer.

## Class Adapter
### Pros:
- Method calls are direct as they're inherited (no pointer indirection)
- can override adaptee's behavior.

### Cons:
- Won't work if the adaptee is final or sealed.
- Use multiple class inheritance (may not be possible in all languages).
- Won't work with subclasses of adaptees.

# Applicability(When to use):
- You want to use an existing class, and its interface isn't compatible with the rest of your code. The **Adapter** pattern
lets you create a middle-layer class that serves as a translator between your code and a 3rd-party class with an 
incompatible interface.
- You need to use classes from existing hierarchy, but they've incompatible interface.
- You need to reuse an existing class with incompatible interface, but want to modify some behavior.

# How to implement:
1. Identify the two classes with incompatible interfaces. A Client class that wants to use a 3rd-party class.
2. Declare the client interface and describe how clients communicate with the Adaptee.
3. Create the **Adapter** class and make it follow ht client interface. Leave all Methods empty for now.
4. Add a field to hte **Adapter** class to store a reference to the adaptee. the common practice is to initialize this field 
via the constructor, bur sometimes it's more convenient to pass it to the **Adapter** when calling its methods.
5. One by one, implement all methods of hte client interface in the **Adapter** class. The **Adapter** should delegate most of 
the real work to the adaptee, handling only the interface or data format conversion.
6. Clients should use the **Adapter** via the client interface. This will let you change or extend the **Adapter**s without 
affecting the client code.

# Relations with other patterns
* **Bridge** is usually designed uo-front, letting you develop parts of an application independently of each other. On the 
other hand **Adapter** is commonly used with an existing app to make some otherwise-incompatible classes work together 
nicely.

* **Adapter** changes the interface of an existing object, while **Decorator** enhances an object without changing its interface.  
In addition, **Decorator** supports recursive composition, which  isnt possible when you use **Adapter**.

* **Adapter** provides a diffrent interface to the wrapped object, **Proxy** provides it with the same interface, and **Decorator** 
provides it with an enhanced interface.

* **Facade** defines a new interface for existing objects, whereas **Adapter** tries to make the existing interface usable. 
**Adapter** usually wraps just one object, while **Facade** works with an entire subsystem of objects.

* **Bridge**, **State**, **Strategy** (and to some degree **Adapter**) have similar structures. Indeed all of these 
patterns ate based on composition, which is delegating work to other objects. However, they all solve different problmes. 
A pattern isn't just a recipe for structuring your code in aspecific way. It can also communicate to other developers 
the problem the pattern solves.




