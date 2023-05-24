# Intent:
Attach additional responisbilities an behaviors to an object dynamically. Decorators provide a flexible alternative to 
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
With this new approach you can easily the linked "helper" object with another, changing the behavior of the container 
at runtime. An object can use the behavior of various classes, having references to multiple objects and delegating them 
all kind of work.


# Components:
![image info](./structure.png)
Image by https://refactoring.guru
* Component: Declares common interface for both wrappers and wrapped objects.
* Concrete Component: is a class of objects being wrapped. It defines the basic behavior, which can be altered by 
decorators.
* Base Decorator: has a field for referencing a wrapped object. The field's type should be declared as the component 
interface so it can contain both concrete components and decorators. The base decorator delegates all operattons to the
wrapped object.
* Concrete Decorators: defines extra behaviors that can be added to components dynamically. Concrete decorators override 
methods of the base decorators and execute their behavior either before or after calling the parent method.
* Client: can wrap components in multiple layers of decorators, as long as it works with all objects via the component 
interface.

# Pros & Cons
## Pros:
- Flexible way of adding responsiblilities to an object rather than inheritance
    * uses composition
    * dynamic unlike inheritance
- Features are added incrementally as the code progresses 
    * no need to spport every feature in one big class
- You pay for the features only when you use them
- Easy to add a combination of capabilities
    * same capabilitiy can be added twice
    * not possible with inheritance
- Components don't have to know about their decorators
    * decorators are transparent to their components
    * loose coupling between the component and its decorators
- You can add or remove responsibilities from an object at runtime.
- You can combine several behaviors by wrapping an object into multiple decorators.

## Cons:
- A decoratred component is not identical to the component itself
    * don't write code that relies on object identity
- Lot's o small objects are created
    * Code becomes harder to understand & debug
- It's hard to remove a specific wrapper from the wrappers stack.
- It's hard to implement a decorator in such a way that its behavior doesn't depend on the order in the decorators 
stack.

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
- Use **Decorator** when you need to be able to add assign exta behavior to objects at runtime without breaking the code 
that uses these objects.
    * The **Decorator** lets you structure your business logic into layers, create a decorator for each layer and 
    compose objects with various combinations of this logic at runtime. The client code can treat all these objects in 
    the same way, since they all follow a common interface.
- Use **Decorator** when it is awkward or not possible to extend an object's behavior using inheritance.
    * Many programming languages have the final keyword that can be used to prevent further extension of a class. For
    a final class, the only way to reuse the existing behavior would be to wrap the class with your own wrapper, using
    the **Decorator** pattern.
- Only add new functionality to single objects instead of whole classes.

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

1. Make sure your business domain can be represented as a primary **component** with multiple optional layers over it. 
2. Figure out what methods are common to both the primary **component** and the optional layers. Create a **component
interface** and declare those methods there.
3. Create a **concrete component** class and define the base behavior in it.
4. Create a **base decorator** class. It should have a field for storing a reference to wrapped object. The field should be 
declared with the **component interface** type to allow linking to **concrete components** as well as **decorators**. The 
**base decorator** must delegate all work to the wrapped object.
5. Make sure all classes implement the **component interface**.
6. Create **concrete decorators** by extending them from the **base decorator**. A **concrete decorator** must execute its behavior 
beffore or after the class to the parent method (which always delegates to the wrapped objects).
7. The **client** code must be responsible for creating **decorators** and composing them inthe way the client needs.  
# Relations with other patterns
* **Adapter** changes the interface of an existing object, while **Decorator** enhances an object without changing its 
interface. In addition, **Decorator** supports recursive composition, which isn't possible when you use **Adapter**.
* **Adapter** provides a different interface to the wrapped object, **Proxy** provides it with the same interface, and
**Decorator** provides it wiht an enhanced interface.
* **Chain of Responsibility** and **Decorator** have similar class structures. Both patterns rely on recursive 
composition to pass the execution through a series of objects. However, there are several crucial differences.
The **Chain of Responsibility** handlers can execute arbitrary operations independently of each other. THey can also 
stop passing the request further at any point. on the other hand, varios **Decorators** can extend the object's
behavior while keeping it consistent with the base interface. In additon, decorators aren't allowed to break the flow
of the request.
* **Composite** and **Decorator** have similar structure diagrams since they both rely on recursive composition to 
organize an open-ended number of objects.
A **Decorator** is like a **Composite** but only has one child component. There's another significant difference: 
**Decorator** adds additional responsibilities to the wrapped behavior of a specific object in the **Composite** tree.
* Designs that make heavy use of **Composite** and **Decorator** can often benefit from using **Pototype**. Applying the 
pattern lets you clone complex structures instead of reconstructing them from scratch.
* **Decorator** lets you change the skin of an object, while **Strategy** lets you change the guts.
* **Decorator** and **Proxy** have similar structures, but very different intents. Both patterns are built on the 
composition principle, where one object is supposed to delegate some of the work to another. The difference is that 
**Proxy** usually manages the life cycle of its service object on its own, whereas the composition of **Decorator** is 
always controlled by the client.

# Pseudocode Example
In this example, the **Decorator** pattern lets you compress and encrypt sensitive data independently from the code 
that actually uses this data.
The Application wraps the data source object with a pair of decorators. Both wrappers change the way the data is 
writtten to and read from the disk:
* Just before the data is written to disk, the decorators encrypt and and protected data to the file without knowing 
about the change. 
* Right after the data is read from disk, it goes through the same decorators, which decompress and decode it.
The decorators and the data source class implement the same interface, which makes them all interchangeable in the 
client code.
    // The component interface defines operations that can be alterd by decorators
    interface DataSource is
        method writeData(data)
        method readData():data
    // Concrete components provide default implementations for the operations. Threre might be several variations of 
    // these classes in a program.
    class FileDataSource implements DataSource is
        constructor FileDataSource(filename) {...}
        
        method writeData(data) is
            // Write data to file.

        method readData():data is
            // Read data from file.
    // The base decorator class folloes the same interface as the other components. The primary purpose of this class is
    // define the wrapping interface for all concrete decorators. The default implementation. of the wrapping code might 
    // include a field for storing a wrapped component and the means to initialize it.
    class DataSourceDecorator implements DtaSource is
        protected field wrappee: DataSource

        constructor DataSourceDecorator(source: DataSource) is
            wrappee = source

        // The base decorator simply delegates all work to the wrapped component. Exta behaviors can be added in 
        // concrete decorators.
        method writeData(data) is
            wrappee.writeData(data)

        // Concrete decorators may call the parent implementation of the operation instead of calling the wrapped object 
        // directly. THis approach simplifies extension of decorator classes.
        method readData();data is
            return wrappee.readData()

    // Concrete decorators ust call methods on the wrapped object, but may add smothing of their own to the result.
    // Decorators can execute the added behavior either before or after the call to a wrapped object.
    class EncryptionDecorator extends DataSourceDecorator is
        method writeData(data) is
            // 1. Encrypt passed data.
            // 2. Pass encrypted data tp the wrappee's writeData method

        method readData():data is
            // 1. Get data from the wrappee's readData method.
            // 2. Try to decrypt it if it's encrypted.
            // 3. Return the result.

    // You can wrap objects in several layers of decorators.
    class CompressionDecorator extends DataSourceDecorator is
        method writeData(data) is
            // 1. Compress passed data.
            // 2. Pass compressed data to the wrappee's writeData method.

        method readData():data is
            // 1. Get data from the wrappee's readData method.
            // 2. Try to decompress it if it's compressed.
            // 3. Return the result.

    // Option 1. A simple example of a decorator assembly.
    class Application is 
        method dumbUsageExample() is
            source = new FileDataSource("somefile.dat")
            source.writeData(salaryRecords)
            // The target file has been written with compressed data.

            source = new CompressionDecorator(source)
            source.writeData(salaryRecords)
            // The target file has been written with compressed data.

            source = new EncryptionDecorator(source)
            // The source variable now contains this:
            // Encryption > Compression > FileDataSource
            source.writeData(SalaryRecords)
            // The file has been written with compressed encrypted data.

    // Option 2. Client code that uses an extenral data source. SalaryManager objects neither know nor cate about data 
    // storage specifics. They work with pre-configured data source received from the app configurator.
    class SalaryManager is
        field source: DataSource

        constructor SalaryManager(source: DataSource) { ... }

        method load() is
            return source.readData()

        method save() is
            source.writeData(salaryRecords)
        // ... Other useful methods ...


    // THe app can assemble differennt stacks of decorators ata runtime, deprending on the configuration or environment.
    class ApplicationConfigurator is
        method configurationExample() is
            source = new FileDataSiurce("salary.data")
            if(enabledEncryption)
                source = new EnctryptionDecorator(source)
            if (enabledCompression)
                source = new CompressionDecorator(source)

            logger = new SalaryManager(source)
            salary = logger.load()

        // ...        
