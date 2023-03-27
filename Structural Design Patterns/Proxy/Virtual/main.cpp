#include "Bitmap.h"
#include "BitmapProxy.h"

int main()
{
    Image* p = new BitmapProxy{ "Smiley.txt" };
    p->Load();
    p->Display();
    delete p;
}
