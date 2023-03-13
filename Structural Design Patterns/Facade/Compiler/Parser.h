#include "Scanner.h"
#include "ProgramNodeBuilder.h"

/**
 * Takes a token from Scanner and a ProgramNodeBuilder to Create a Parse-Tree
 */
class Parser
{
public:
    Parser();
    virtual ~Parser();
    virtual void Parse(Scanner&, ProgramNodeBuilder&);
};