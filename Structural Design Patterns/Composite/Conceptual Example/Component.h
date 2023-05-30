#pragma once
/**
 * The base Component class declares common operations for both simple and complex objects of a
 * composition.
*/
class Component
{
    /**
     * @var Component
    */
protected:
    Component* parent_;
    /**
     * Optionally, the base Component can declare an interface for setting and accessing a parent
     * of the component in a tree structure. It can also provide some default implementation for 
     * these methods.
    */
};

