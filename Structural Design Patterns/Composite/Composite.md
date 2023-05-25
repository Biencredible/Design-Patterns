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
![image info](./structure-en.png)
Image by https://refactoring.guru
* **Component**: is an interface and describes operations that are common to both simple and complex elements of the 
    tree.
* **Leaf**: is a basic element of a tree that doesn't have subelements. Usually leaf components end up doing most of 
    the real work, since they don't have anyone to delegate the work to.
* **Composite**: is an element that has sub-elements: leaves or other composites. A composite doesn't know the concrete
    classes of its children. It works with all sub-elements only via the component interface. Upon receiving a request,
    a composite delegates the work to its sub-elements, processes intermediate results and then returns the final result 
    to the client.
* **Client**: works with all elements through the component interface. As a result, the client can work on the same way 
    with both simple or complex elements of the tree.


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
![image info](./example.png)
Image by https://refactoring.guru

The *CompoundGraphic* class is a composite that can comprise any number of sub-shapes, including other compound shapes. 
A compound shape has the same methods as a simple shape. However, instead of doing something on its own, a compound 
shape passes the request recurively to all its children and "sums up" the reslt.
The Client code works with all shapes through the single interface common to all shape classes. Thus, the client doesn't
know whether it's working with a simple shape or a compound one. The client can work with very complex object structures
without being coupled to concrete classes that form that structure.
    // The composite interface declares common operations for both somple and complex objects of a composition.
    interface Graphic is
        method move(x, y)
        method draw()

    // The leaf class represents end objects of acomposition. A leaf object can't have any sub-objects. Usually, it's 
    // leaf objects that do the actual work, while composite objects only delegate to their sub-components.
    class Dot implements Graphic is
        field x, y

        constructor Dot(x, y) { ... }
        method move(x, y) is
            this.x += x, this.y += y

        method draw() is
            // Draw a dot at X and Y.

    // All component classes can extend other components.
    class Circle extends Dot is
        field radius

        constructor Circle(x, y, radius) { ... }

        method draw() is
            // Draw a circle at X and Y with radius R

    // The composite  class represents complex components that may have children. Composite objects usually delegate the 
    // actual  work to their children and then "sum up" the result.
    class CompoundGraphic implements Graphic is
        field children: array of Graphic

        // A composite object cann add or remove other components (both simple or complex) to or from its child list.
        method add(child: Graphic) is
            // Add a child from the array of children

        method remove(child: Graphic) is
            // Remove a child from the array of children

        method move(x,y) is
            foreach (child in children) do
                child.move(x, y)

        // A composite executes its primary logic in a particular way. It traverses recursively through all its 
        // children, collecting and summing up their results. Since the composite's children pass these calls to their 
        // own children and so forth, the shole object tree is traversed as a result. 
        method draw() is 
            // 1. For each child component:
            //      - Draw component.
            //      - Update the bounding rectangle.
            // 2. Draw a dashed rectangle using the bounding coordinates.

    // The client coder works witha ll the components via their base interface, This way the client code can support 
    // simple leaf componnents as well as complex composites.
    class ImageEditor is
        field all: CompoundGraphic

        method load() is
            all = new CompoundGraphic()
            all.add(new Dot(1, 2))
            all.add(new Circle(5, 3, 10))
            // ...

        // Combine selected components into one complex composite component.
        method groupSelected(components: array of Graphic) is
            group = new CompoundGrapic()
            foreach (component in components) do
                group.add(component)
                all.remove(component)
            all.add(group)
            // All components will be drawn.
            all.draw()
