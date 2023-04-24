#include "FileInputStream.h"
#include <iostream>
#include "FileOutputStream.h"
#include "BufferedOutputStream.h"
#include "BufferedInputStream.h"

void Read()
{
    BufferedInputStream input{ "test.txt" };
    std::string text{};
    while(input.Read(text))
    {
        std::cout << text << std::endl;
    }
}

void Write()
{
    BufferedOutputStream output{ "test.txt" };
    output.Write("First line");
    output.Write("Second line");
    output.Write("Third line");
}

int main()
{
    Write();
    Read();
}
