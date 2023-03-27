#include "Bitmap.h"

int main()
{
    Image* p = new Bitmap{ "Smiley.txt" };
    p->Load();
    p->Display();
    delete p;
}