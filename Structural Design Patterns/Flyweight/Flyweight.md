# Intent:
Use sharing to support large numbers of fine-grained objects efficiently.


# Example Problem:


# Solution: 



# Components:
![image info](./structure-en.png)


# Pros & Cons
## Pros:



## Cons:



# Applicability(When to use):



# How to implement:
* In most cases, the client does not create the flywieght itself.
* It is requested from a pool.
* Typically a factory that may use associative container to store the flywieghts.
* A client requests a fly weight through its key.
* Th epool will either create it with intrinsic state or supply an existing one.
* THe extrinsic state should be computed separately.
* The interface of the flyweight does not enforce sharing. Some objects may be unshare.
* THe pool can instantiate all flyweights and keep them around permanently if their count is low.
* The flywieghts ar immutable, and their behavior depends on the extrinsic state.

 
# Relations with other patterns



# Pseudocode Example
