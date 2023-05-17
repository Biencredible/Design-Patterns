#include "Frame.h"
#include "Button.h"
#include <iostream>


void Display(Widget* pWidget)
{
    pWidget->Paint();
    auto pFrame = pWidget->GetFrame();
    if (pFrame)
    {
        pWidget->Add(new Button{});
    }
    else
    {
        std::cout << "Cannot add a child\n";
    }
}
    

int main()
{
    Frame* mainWindow = new Frame{};
    Button* btnOK = new Button{};

    mainWindow->Add(btnOK);
    mainWindow->Paint();

    Frame* childWindow = new Frame{};
    Button* btnFind = new Button{};
    childWindow->Add(btnFind);

    mainWindow->Add(childWindow);

    /*mainWindow->Paint();

    std::cout << "Changing Visibility\n";
    mainWindow->SetVisibility(false);*/
    //mainWindow->Paint();

    Display(btnOK);
    Display(mainWindow);

    delete mainWindow;

    _CrtDumpMemoryLeaks();
}
