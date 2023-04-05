# Intent:
Provide a surrogate or placeholder for another object to control access to it.
## Proxy Types:
- Virutal: creates expensive objects on demand
- Cache: chaches expensive calls
- Remote: simplifies client implementation
- Protection: provides access management
- Smart: -performs additional actions

# Example Problem:
You have a massive object that cinsumees avast amount of system resources. You need it from time to time, but not 
always. Only creating the object when it is needed, would need each clinet to run the initialization steps, which leads 
to code duplication.

# Solution: 


# Components:

# Pros & Cons
## Pros:


## Cons:


# Applicability(When to use):

# How to implement:
- Proxy should have the same interface as that of the real object.
- This is important because the client should not distinguish between the real subject and the poxy.
- One way to achieve this is to inherit the poxy from the same class that he real subject inherits from.
- This allows us to replace an object with proxy without significant changes.
- In C++, we can overload * and -> operator without having to implement all the methods of the real subject.
- A proxy ma create instance of the real subject.
    * it may create the object on demand
- One proxy can work with multiple subjects through an abstract interface
    * reduces coupling between classes.
    * used when the proxy provides a common implementation for all the classes.
# Relations with other patterns
