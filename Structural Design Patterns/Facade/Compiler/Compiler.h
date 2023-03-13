
/**
* Facade for the compiler subsystem.
*/
class Compiler
{
public:
    Compiler();
    virtual void Compile(iStream&, BytecodeStream&);
};