class Compiler
{
public:
    Compiler();
    virtual void Compile(iStream&, BytecodeStream&);
};