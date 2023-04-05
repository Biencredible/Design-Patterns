#include "../Virtual/Bitmap.h"
#include "Pointer.h"

//int main()
//{
//    Bitmap* p = new Bitmap("Smiley.txt");
//    p->Load();
//    p->Display();
//}

int main()
{
    Pointer<Bitmap> p = new Bitmap("Smiley.txt");
    p.Get()->Load();
    p.Get()->Display();
}