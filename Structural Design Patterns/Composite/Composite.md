# Intent:
Compose objects into tree structures to represent part-whole hierachies. Composite lets clients treat individual 
objects and compositions of objects uniformly.

# Example Problem:


# Solution: 


# Components:


# Pros & Cons
## Pros:


## Cons:


# Applicability(When to use):


# How to implement:
* The *Leaf* and *Composite* should be treated uniformly by the *Client*.
* The *Component* class should define as many common operations possible for all subclasses.
    - *Clients* should not have to differentiate between *Leaf* & *Composite*.
* Type of data structure to use for storage inside *Composite* depends on required efficiency.
    - In some cases it may not be required at all.
* In languages that don't suport garbage collection, *Composite* can be made responsible for destroying its children.

    
# Relations with other patterns


# Pseudocode Example

        

