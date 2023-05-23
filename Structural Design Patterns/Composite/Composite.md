# Intent:
Compose objects into tree structures to represent part-whole hierachies. Composite lets clients treat individual 
objects and compositions of objects uniformly.

# Example Problem:
Using the *Composite* pattern makes sense only when the core model of your app can be represented as tree.
For example, imagine that you have two types of objects: Products and Boxes. A Box can contain several Products as well 
as a number of smaller Boxes. These little Boxes can also hold some Products or even smaller Boxes, ans so on.
Say you decide  to create an ordering system that uses these classes. Orders could contain simple products without any 
wrapping, as well as boxes stuffed with products ... and other boxes. How would you determine the total price of such an 
order?
You could try the direct approach: unwrap all the boxes, go over all the products and then calculate the total. That 
would be doable in the real world; but in a program, it's not as simple as running a loop. You have to know the classes 
of Products and Boxes you're going through, the nesting level of the boxes and other nasty details beforehand. All of
this makes the direct approach either too awkward or even impossible.

# Solution: 
The *Composite* pattern suggests that you work with Products and Boxes through a common interface which declares a 
method for calculating the total price.
How would this mehtod work? For a product, it'd simply return the product's price. For a box, it'd go over each item
the box contains, ask its price and then return a total for this box. If one of these items were a smaller box, that box 
would also start going over its contents and so on, until the prices of all inner components were calculated. A box 
could even add some extra cost to the final price, such as packaging cost.
The greatest benefit of this approach is that ypu don't need to care about the concrete classes of objexts that compose
the tree. You don't need to know whether an object is a simple product or a sophisticated box. You can treat them all
the same via the common interface. When you call a method, the objects themselves pass the request down the tree.


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

        

