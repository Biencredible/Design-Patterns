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
* Use the Factory Method when you don't know beforehand the exact types and dependencies of the 
object your code should work with.
    * The Factory Method separates product construction from the code that actually uses
    the product. Therefore it's easier to extend the product construction code independently
    from the rest of the code.
    For example, to add a new product type tp the app, you'll only need to create a new 
    crator subclass and override the factory method in it.
* Use Factory Method when you want to provide users of your library or framweork with a way to 
extend its internal components.
    * Inheritance is probably the easiest way to extend the default behavior of a library or 
    framework recognize that your subclass should be used instead of a standard component?
    The solution is to reduce the codethat constructs components across the framework into a
    songle factory method and let anyone override thos method in addition to extending the component
    itself.
    Imagine that you write an open source UI framework. Your app shiuld have round buttons, but the 
    framework only provides square ones. You extend the standard *Button* class with a clorious 
    *RoundButton* subclass. But now you need to tell the main *UIFramework* class to use the new 
    button subclass instead of a default one.
    To achieve this, you create a subclass *UIWithRoundButtons* from a base framewrok class and 
    override its *CreateButton* method. While this method returns *Button* objects in the base 
    class, you make your subclass return *RoundButton* objects. Now use the *UIWithRoundButtons* 
    class instead of *UIFramework*.
* Use the Factory Method when you want to save system resources by reusing existing objects instead 
of rebuilding them each time.
    * You often experience this need when dealing with large, resource-intensive objects such as 
    database connections, file systems, and network resources.
    Let's think about what has to be done to reuse an existing object:
    1. First, you need to create some storage to keep track of the created objects.

# How to implement:


 
# Relations with other patterns



# Pseudocode Example
Creating cross-platform UI elements without coupling the client code to concrete UI classes.
![image info](./example.png)
The base DIalog class uses different UI elements to render its window. Under various operating 
systems, these elements may look a different, but they should still behave consistently. A button
in WIndows is still a button in Linux.

When the factory method comes into play, you don't need to rewrite the logic of the *Dialog* class
for each operating system. If we declare a factory method that produces buttons inside the base 
*Dialog* classe, we can later create a subxlass that returns Windows-styled buttons from the factory 
method. The subclass then inherits most of the code from the base class, but, thanks to the factory 
method, can render Windows-looking buttons on the screen.

For this pattern to work, the base *Dialog* class must work with abstract buttons: a base class or 
an interface that all concrete buttons follow. This way the code within Dialog remains functional, 
whichever type of buttons it works with.

Of course, you can apply this approach to other UI elements as well. However, with each new factory
method you add to the *Dialog*, you get closer to the **Abstract Factory** pattern. Fear not, we'll 
talk about this pattern later.

    // The creator class declares the factory method that must 
    // return an object of a product class . The creator's subclasses
    // usually provide the implementation of this method.
    class Dialog is
        // The creatro may also provide some default implementation
        // of the factory method.
        abstract method createButton():Button

        // NOte that, despite its name, the creator's primary 
        // responsibility isn't creating products. It usually
        // contains some core business logic that relies on product
        // objects returned by the factory method. Subclasses can 
        // indirectly change that business logic by overriding the 
        // factory method and returning a different type of product
        // from it.
        method render() is
            // Call the factory method to create a product object.
            Button okButton = createButton()
            // Now use the product.
            okButton.onClick(closeDialog)
            okButton.render()

    // Concrete creators override the factory method to change the 
    // resulting product's type.
    class WindowsDialog extends Dialog is
        method createButton():Button is
            return new WindowsButton

    class WebDialog extends Dialog is
        method createButton(): is
            return new WindowsButton

    // The product interface declares the operations that all 
    // concrete products must implement.
    interface Button is
        method render()
        onClick(f)

    // Concrete products provide various implementations of the 
    // product interface.
    class WindowsButton implements Button is 
        method render(a, b) is
            // Render a button in Windows style.
        method on Click(f) is
            // Bind a native OS click event.
        
    class HTMLButton implements Button is
        method render(a,b) is
            // Return an HTML representation of a button.
        method onClick(f) is
            // Bind a web browser click event.

    class Application is 
        field dialog: Dialog

        // The application picks a creator's type dependeing on the 
        // current configuration or environment settings.
        method initialize() is
            config = readApplicationConfigFile()

            if (config.OS == "Windows") then
                dialog = new WindowsDialog()
            else if (config.OS == "Web") then
                dialog = new WebDialog()
            else
                throw new Exception("Error! Unknown operating system.")

        // The client code works with an instance of a concrete
        // creator, albeit through its base interface. As long as
        // the client keeps working with the creator via the base
        // interface, you can pass it any creator's subclass.
        method main() is
            this.initialize()
            dialog.render()




