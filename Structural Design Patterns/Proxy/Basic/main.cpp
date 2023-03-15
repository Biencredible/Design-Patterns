#include "Subject.h"
#include "RealSubject.h"
#include "Proxy.h"

void Operate(Subject* s)
{
    s->Request();
}

int main()
{
    Subject* sub = new Proxy{};
    Operate(sub);
}
