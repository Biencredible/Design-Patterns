
#include "Component.h"
#include <iostream>
#include "Leaf.h"
#include "Composite.h"

/**
* The client code works with all of the components via the base interface.
*/
void ClientCode(Component* component)
{
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

/**
 * Thanks to the fact the chield-management operations are declared in the base component class, 
 * the client code can work with any component, simple or complex, without depending on their 
 * concrete classes.
 */
void ClientCode2(Component* component1, Component* component2)
{
    // ...
    if (component1->IsComposite())
    {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
    // ...
}

/**
 * This way the client code can support the simple leaf components...
 */
int main()
{
    Component* simple = new Leaf;
    std::cout << "Client: I've got a simple component: \n";
    ClientCode(simple);
    std::cout << "\n\n";
    /*
     * ... as well as the complex composites.
     */

    Component* tree = new Composite;
    Component* branch1 = new Composite;

    Component* leaf_1 = new Leaf;
    Component* leaf_2 = new Leaf;
    Component* leaf_3 = new Leaf;
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    Component* branch2 = new Composite;
    branch2->Add(leaf_3);
    tree->Add(branch1);
    tree->Add(branch2);
    std::cout << "Client: Now I've got a composite tree:\n";
    ClientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes when managing the tree:\n";
    ClientCode2(tree, simple);
    std::cout << "\n";

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}

