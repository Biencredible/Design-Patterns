#include "IAnimate.h"
#include "Sprite.h"

void Draw(IAnimate* p)
{
    p->SetImage('#');
    p->Animate(5);
    
}

int main()
{
    Sprite s;
    Draw(&s);
    
}
