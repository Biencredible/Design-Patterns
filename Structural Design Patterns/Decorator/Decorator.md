# Intent:
Attach additional responisbilities to an object dynamically. Decorators provide a flexible alternative to subclassing 
for extending functionality

## Decorator Types:
- **Dynamic Decorator**: Behaviour is added dynamically, at runtime
- **Static Decorator**: Decorator is chosen at compile-time
- **Functional Decorator**: decorate a function instead of an object

# Example Problem:

# Solution: 

# Components:

# Pros & Cons
## Pros:
- Flexible way of adding responsiblilities to an object rather than inheritance
    * uses composition
    * dynamic unlike inheritance
- Features are added incrementally as the code progresses 
    * no need to spport every feature in one big class
- You pay for the features only when you uset them
- Easy to add a combination of capabilities
    * same capabilitiy can be added twice
    * not possible with inheritance
- Components don't have to know about their decorators
    * decorators are transparent to their components
    * loose coupling between the component and its decorators

## Cons:
- A decoratred domponent is not identical to the component itself
    * don't write code that relies on object identity
- Lot's o small objects are created
    * Code becomes harder to understand & debug

# Applicability(When to use):
- Responsiblities:
    * have to be added transparently & dynamically
    * have to be withdrawn
- Using inheritance for adding new behavior leads to explsion of classes
- You want to support combinations of behaviors
    * using inheritance is error-prone or impractical
- With legacy systems where you've to add new behaviour
    * you don't want to modify existing code
- When adding new functionality to existing UI components
    * scrollbars for windows, checkboxes ina list box, tooltips, etc.
- Class is hidden, final or sealed or not available for subclassing
    * You can add new features to such class through a decorator

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