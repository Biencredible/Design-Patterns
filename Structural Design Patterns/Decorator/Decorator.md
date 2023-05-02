# Intent:
Attach additional responisbilities an behaviours to an object dynamically. Decorators provide a flexible alternative to 
subclassing for extending functionality

## Decorator Types:
- **Dynamic Decorator**: Behaviour is added dynamically, at runtime
- **Static Decorator**: Decorator is chosen at compile-time
- **Functional Decorator**: decorate a function instead of an object

# Example Problem:
Imagine your are working on a notification library which lets other programs notify their users about important events.
The initial version of the library was based on the *notifier* class that had only a few fields, a constructor and a 
single *send* method. The method could accept a message argument from a client and send the message to a list of emails 
that were passed to the notifier via its constructor. A third-party app which acted as a client was supposed to create 
and configure the notifier object once, and then use it each time something important happened.
At some point, you realize that users of the library expect more than just email notifications. Many of them would like 
to receive an SMS about critical issues. Others would like to be notified on facebook and, of course, the corporate 
would love to get Slack notifications.
You extended the *Notifier* class and put the additional notification methods into new subclasses. Now the client was 
supposed to instantiate the desired notification class and use it for all further notifications.
Sending an SMS and Facebook notification is not possible at the same time, so it would be necessary to create a
SMS + Facebook notifier and so on. This would lead to an extensive amount of classes if each possible combination would 
be handled that way.
# Solution: 
Extending a class is waht first comes to mind. But
* Inheritance is static. You can't alter the behavior of an existing object at runtime. You can only replace the whole 
object with another one that's created from a different subclass.
* Subclasses can have just one parent class. In most languages, inheritance doesn't let a class inherit behaviors of 
multiple classes at the same time.
One of the ways to overcome these caveats is by using *Aggregation* or *Composition*. instead of *Inheritance*. Bothe of 
the alternatives work almost the same way: one object has areference to another and delegates it some work, wheras with
inheritance, the object itself is able to do that work, inheriting the behavior from its superclass.


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