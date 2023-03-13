#include "Codegenerator.h"

/**
 * Parse tree consists of instances of program nodes. The program node hirarchy is an example for 
 * the design pattern composite. Provides an interface gor manipulating program nodes.
 */
class ProgramNode
{
public:
    virtual void GetSourcePosition(int& line, int& index);
    // ...

    virtual void Add(ProgramNode*);
    virtual void Remove(ProgramNode*);

    virtual void Traverse(CodeGenerator&);

protected:
    ProgramNode();
};