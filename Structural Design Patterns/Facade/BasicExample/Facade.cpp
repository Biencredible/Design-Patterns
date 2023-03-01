#include "Facade.h"

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
