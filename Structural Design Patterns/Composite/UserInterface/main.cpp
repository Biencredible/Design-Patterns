#include "Frame.h"
#include "Button.h"
#include <iostream>


void Display(Widget* pWidget)
{
    //pWidget->Paint();
    if(auto pFrame = pWidget->GetFrame(); pFrame != nullptr)
    {
        pWidget->Add(new Button{});
    }
    else
    {
        std::cout << "Cannot add a child\n";
    }
    if(auto pFrame = pWidget->GetParent(); pFrame != nullptr) // C++ 2017
    {
        pFrame->Paint();
    }
    else
    {
        std::cout << "No parent\n";
    }
}
    

int main()
{
    Frame* mainWindow = new Frame{};
    Button* btnOK = new Button{};

    mainWindow->Add(btnOK);
    //mainWindow->Paint();

    Frame* childWindow = new Frame{};
    Button* btnFind = new Button{};
    childWindow->Add(btnFind);

    mainWindow->Add(childWindow);

    /*mainWindow->Paint();

    std::cout << "Changing Visibility\n";
    mainWindow->SetVisibility(false);*/
    //mainWindow->Paint();

    std::cout << "Operating on Button\n";
    Display(btnOK);
    std::cout << "\n\nOperating on Frame\n";
    Display(mainWindow);

    delete mainWindow;

    _CrtDumpMemoryLeaks();
}
