# Intent:
Provides an interface for creating objects in a superclass, but allows subclasses to alter the type 
of objecta that will be created.


# Components:
![image info](./structure.png)
* **Product**: declares the interface, which is common to all objects that can be produced by the
creator and its subclasses.
* **Concrete Products**: different implementations of the product interface.
* **Creator**: declares the factory method that returns new product objects. It's important that the
return type of this method matches the product interface.
You can declare the factory method as abstract to force all subclasses to implement their own 
versions of the method can return some default product type.
* **Concrete Creators**: override the base factory method so it returns a different type of product.
Note that the factory method doesn't have to create new instances all the time. It can also return 
existing objects from a cache, an object pool, or another source.

# Pros & Cons
## Pros:


## Cons:


# Applicability(When to use):

# How to implement:


 
# Relations with other patterns



# Pseudocode Example
Creating cross-platform UI elements without coupling the client code to concrete UI classes.




