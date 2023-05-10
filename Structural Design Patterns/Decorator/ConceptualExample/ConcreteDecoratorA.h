#pragma once
/**
 * Concrete Decorators call the wrapped object and alter its result in some way.
*/
class ConcreteDecoratorA : public Decorator
{
    /**
     * Decorators may call parent implementation of the operation, instead of calling the wrapped 
     * object directly. This approach simplifies extension of decorator classes.
    */
public:

};

