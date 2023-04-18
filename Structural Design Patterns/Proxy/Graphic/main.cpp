
#include "Textdocument.h"
#include "ImageProxy.h"

int main()
{
    TextDocument* text = new TextDocument;
    // ...
    text->Insert(new ImageProxy("anImageFileName"));
}
