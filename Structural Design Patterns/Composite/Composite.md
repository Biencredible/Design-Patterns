# Intent:
Compose objects into tree structures to represent part-whole hierachies. Composite lets clients treat individual 
objects and compositions of objects uniformly.

# Example Problem:


# Solution: 


# Components:


# Pros & Cons
## Pros:
* Primitives can be composed into mmore complex objects & so on
* Clients that expect a primitive object can also work wit a composite
* Clients don't have to deal with multiple classes; this promotes loose coupling & makes the code flexible
* New kinds of components can be added
    - existing code does not need any modification & will still work

## Cons:
* Difficlut to restrict the type of components that can be composed in a composite
    - cannot create a composite made up of certain kinds of components.
* Not all operations in *Component* may be applicable to the *Leaf* classes

# Applicability(When to use):
* You want to create complex representations of objects using part-whole hierachy.
* You want the clients to treat all the objects in the Composite structure uniformly without relying on type of object.


# How to implement:
* The *Leaf* and *Composite* should be treated uniformly by the *Client*.
* The *Component* class should define as many common operations possible for all subclasses.
    - *Clients* should not have to differentiate between *Leaf* & *Composite*.
* Type of data structure to use for storage inside *Composite* depends on required efficiency.
    - In some cases it may not be required at all.
* In languages that don't suport garbage collection, *Composite* can be made responsible for destroying its children.
* Keep explicit parent pointer
    - Simplifies traversal
    - or use an iterator
* Maximize Component interface
    - putting all common operations
    - *Leaf* classes may inherit operations meant for *Composite*
    - where to put the child-management operations of the *Composite*
* *Leaf* ordering
* Data structure for children

    
# Relations with other patterns


# Pseudocode Example

        

