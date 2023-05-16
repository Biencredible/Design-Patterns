#include "Frame.h"
#include "Button.h"
#include <iostream>

int main()
{
    Frame mainWindow{};
    Button btnOK{};

    mainWindow.Add(&btnOK);
    mainWindow.Paint();

    Frame childWindow{};
    Button btnFind{};
    childWindow.Add(&btnFind);

    mainWindow.Add(&childWindow);

    mainWindow.Paint();

    std::cout << "Changing Visibility\n";
    mainWindow.SetVisibility(false);
    mainWindow.Paint();
}
