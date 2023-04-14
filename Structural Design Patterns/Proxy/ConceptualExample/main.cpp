#include <iostream>
#include "Subject.h"
#include "RealSubject.h"
#include "Proxy.h"

/**
* The client code is supposed to work with all objects (both subjects and proxies) via the subject 
* interface in order to support both real subjects and proxies. In real life, however, clients 
* mostly work with their real subjects directly. In this case, to implement the pattern more 
* easily, you can extend your proxy from the real subject's class.
*/
void ClientCode(const Subject &subject)
{
    // ...
    subject.Request();
    // ...
}

int main()
{
    std::cout << "Client: Executing the client code with real subject:\n";
    RealSubject* real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with proxy:\n";
    Proxy* proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}