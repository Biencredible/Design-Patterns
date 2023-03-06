#include "Facade.h"

/**
Facade provides convenient acces to a particluar part of the subsystem's functionality. It knows where to direct 
client's requests and how to operate all moving parts.
An Additional Facade class can be created to prevent polluting a single facade with unrelated features that might make 
it yet another compljex structure.
Additional facades can be used by both clients and other facades.
*/
Facade::Facade()
{
    A_ = new A{};
    B_ = new B{};
    C_ = new C{};
}

Facade::~Facade()
{
    delete A_;
    delete B_;
    delete C_;
}

void Facade::Use()
{
    A_->callA();
    B_->callB();
    C_->callC();
}
