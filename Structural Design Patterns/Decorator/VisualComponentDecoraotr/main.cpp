#include "VisualComponent.h"
#include "TextView.h"
#include <iostream>
#include "ScrollDecorator.h"
#include "BorderDecorator.h"

void drawGui(VisualComponent* visualComponent)
{
    std::cout << visualComponent->draw();
    std::cout << "\n\n";
}

int main()
{
    VisualComponent* textView = new TextView;
    VisualComponent* scrollTextView = new ScrollDecorator(textView);

    drawGui(scrollTextView);

    VisualComponent* borderTextView = new BorderDecorator(textView);
    drawGui(borderTextView);

    VisualComponent* godTextView = new BorderDecorator(scrollTextView);
    drawGui(godTextView);
    

    delete textView;
    delete scrollTextView;
    delete borderTextView;
    delete godTextView;

    return 0;
}
