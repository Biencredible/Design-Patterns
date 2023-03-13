#include "Codegenerator.h"

/**
 * Tkaes a COdeGenerator object that is used by program node child classes to produce machine code 
 * as bytecode objects of a bytecode stream
 */
void ExpressionNode::Traverse(CodeGenerator& cg)
{
    cg.Visit(this);
    ListIterator<ProgramNode*> i (_children);

    for(i.First(); !i.IsDone(); i.Next())
    {
        iCurrentItem()->Traverse(cg);
    }
}
