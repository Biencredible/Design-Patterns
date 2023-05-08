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
