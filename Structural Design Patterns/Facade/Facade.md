# Intent:
Provide a unified or simplified interface to a set of interfaces in a subsystem. **Facade** defines a higher level interface 
that makes the subsystm easier to use.

# Example Problem:
Code must work with a broad set of  objects. Those objects need to be initialized, dependencies need to be kept track
of, methosds must be called in the correct order. Code becomes tightly coupled to the implementation of thrid party 
classes and hard to comprehend and maintain.

# Solution: 
**Facade** provides a simple interface to a complex subsystem. Might provide limited funcionality.

# Components:
![image info](./structure.png)
Image by https://refactoring.guru
# Pros & Cons
## Pros:
- **Facade** isolates the clients from components with complex interface
- reduces the number of objectrs the clients interact with.
- Leads to weak coupling.
- underlying components can change without impacting the clients
- reduces compilation dependencies in large systems
- **Facades** do not hide the underlying classes of the subsystem
- Clients can still use the classes if they need to
- Provides an object oriented interface to
    * low-level operating system functions or APIs
    * data structures, thereby reducing programming errors
## Cons:
- Overuse leads to too many layers
- Performance of the system may degrade
- Can become a god object

# Applicability(When to use):
- You want to provide a simple interface to a complex system 
    * this could be a default view for most clients
    * Other clients that need customization can use the underlying classes directly
- A system has evolved and gets more complex
    * early users might want to retain their views of the system
- Your Application depends on low-level OS APIs
    * You want to avoid coupling with a specific OS
    * ypu want to provide an object-oriented wrapper
- Team members with different level of experience use the system
    * your might want to provide a novice or power user interfaces
- Too many dependencies between clients and the implementation classes of a subsystem
- When you want to structure a subsystem into layers.

# How to implement:

1. Check whether it is possible to provide a simpler interface than what an existing subsystem already provides. 
You're on the right track if this interface makes the client code independent from many of the subsystem's classes.
2. Declare and implement this interface in a new **Facade** class. The **Facade** should redirect the calls from client 
code to appropriate objects of the subsystem. The **Facade** should be responsible for initializing the subsystem and 
managing its further life cycle unless the client code already does this.
3. To get the full benefit from the pattern, make all the client code communicate with the subsystem only via the 
**Facade**. Now the client code is protected from man changes in the dubsystem code. For example, when a subssystem gets 
upgraded to a new version, you will only need to modify the code in the **Facade**.
4. If the **Facade** becomes too big, consider extracting part of its behavior to a new, refined **Facade** class.

# Relations with other patterns
- **Facade** defines a new interface for existing objects, whereas **Adapter** tries to make the existing interface usable. 
**Adapter** usually wraps just one object, while **Facade** works with an entire subsystem of objects.
- **Abstract Factory** can serve as an alternative **Facade** when you only want to hide the way the subsystem objects are 
created the client code.
- **Flyweight** shows how to make lots of little objects, wheras **Facade** shows how to make a single object that represents
an entire subsystem.
- **Facade** and **Mediator** have similar jobs: they try to organize collaboration between lots of tightly coupled classes.
    * **Facade** defines a simplified interface to a subsystem of objects, but it doesn't introduce any new functionality.
    The subsystem itself is unaware of the **Facade**. Objects within the subsystem can communicate directly.
    * **Mediator** centralizes communication between components of the system. The components only know about the Mediator
    object and don't communicate directly.
- A **Facade** class can often be transformed into a **Singleton** since a single **Facade** object is sufficient in most 
cases.
- **Facade** is similar to **Proxy** in that both buffer a complex entity and initialize it on its own. Unlike 
**Facade**, **Proxy** has the same interface as its servicce object, which makes them interchangable.