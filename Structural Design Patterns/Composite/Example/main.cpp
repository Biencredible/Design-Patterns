#include "Leaf.h"
#include "Composite.h"

int main()
{
    Leaf leaf1, leaf2, leaf3;
    Composite subroot;
    subroot.Add(&leaf3);

    Composite root;
    root.Add(&leaf1);
    root.Add(&leaf2);

    root.Add(&subroot);

    root.Operation();   
}
/*
 * root
 * |
 * |-leaf1
 * |-leaf2
 * |
 * |-subroot
 *      |-leaf3
*/