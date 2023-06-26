
#include "FlyweightFactory.h"

int main()
{
    int extrinsicState = 1;
    FlyweightFactory factory;
    auto f1 = factory.GetFlyweight(1);
    auto f2 = factory.GetFlyweight(2);
    auto f3 = factory.GetFlyweight(3);

    f1->Operation(extrinsicState++);
    f2->Operation(extrinsicState++);
    f3->Operation(extrinsicState++);

    return 0;
}
