# Intent:
Attach additional responisbilities to an object dynamically. Decorators provide a flexible alternative to subclassing 
for extending functionality

## Proxy Types:

# Example Problem:

# Solution: 

# Components:

# Pros & Cons
## Pros:

## Cons:

# Applicability(When to use):

# How to implement:
- A Decorator's interface must conform to the interface of the object it decorates
    * must inherit from common base class
- Abstract decorator is not required if only one responsibility has to be added
    * the decorator can itself forward the calls to the object.
- Abstrat Decorator & its base class should be lightweight
    * should focus on defining interface, not storing data
    * avoid adding concrete implementation as not all subclasses may require it
    * these objects are part of every decorator and will make the decorators bulky to use
- Decorator changes the skin; alternative is to change the guts (through Strategy Pattern)
# Relations with other patterns

# Pseudocode Example