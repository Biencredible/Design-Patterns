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
Create a **Proxy** class with the same interface as the original class. Then update your code so that it passes the 
proxy to all the clients that used the original object. This way, if something needs to be done before or after the 
primary logic of the original class, you can do this in the proxy without changing hte original class.

# Components:
- Service Interface: declares the interface of the service. The proxy must follow this interface to be able to disguise 
itself as a service object.
- Service: is a class that provides some useful buisiness logic.
- Proxy: has a reference to the service object. After the proxy finishes its processing, it passes the request to the 
service object.
- Client: should work with bothe services and proxies via the same interface. This way you can pass a proxy into any 
code that expexts a service object.

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

# Pseudocode Example
This example illustrates how the **Proxy** pattern can help to introduce lazy initialization and caching to a 3rd party 
Youtube integration library.  
The library provides us with the video downloading class. However, it's very inefficient. If the client application 
requests the same video multiple times, the library just downloads it over and over, instead of caching and reusing the 
first downloaded file.
The poxy class implements the same interface ass the original downloader and delegates it all the work. However, it 
keeps track of the doenloaded files and returns thechachedresult when the app requests the same video multiple times.
