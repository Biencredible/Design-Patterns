#include "ProgramNode.h"

/**
 * Is called by Parser and incrementally creates a parse tree (Builder Design Pattern).
 */
class ProgramNodeBuilder
{
public:
    ProgramNodeBuilder();

    virtual ProgramNode* NewVariable(const char* variableName) const;
    virtual ProgramNode* NewAsignment(ProgramNode* variable, ProgramNode* expression) const;
    virtual ProgramNode* NewReturnStatement(ProgramNode* value) const;
    virtual ProgramNode* NewCondition(ProgramNode* condition, ProgramNode* truePart, ProgramNode* falsePart) const;
    // ...
    ProgramNode GetRootNode();
private:
    ProgramNode* _node;
};