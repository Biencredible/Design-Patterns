#include "FileInputStream.h"
#include <iostream>
#include "FileOutputStream.h"
#include "BufferedOutputStream.h"
#include "BufferedInputStream.h"
#include "DecryptedStream.h"
#include "EncryptedStream.h"
#include "CompressedOutputStream.h"
#include "DecompressedInputStream.h"

void BufferedRead()
{
    BufferedInputStream input{ "test.txt" };
    std::string text{};
    while(input.Read(text))
    {
        std::cout << text << std::endl;
    }
}

void BufferedWrite()
{
    BufferedOutputStream output{ "test.txt" };
    output.Write("First line");
    output.Write("Second line");
    output.Write("Third line");
}

void Encrypt()
{
    EncryptedStream output{ "encryption.txt" };
    output.Write("First line");
    output.Write("Second line");
    output.Write("Third line");
}
void Decrypt()
{
    DecryptedStream input{ "encryption.txt" };
    std::string text{};
    while(input.Read(text))
    {
        std::cout << text << std::endl;
    }
}

void Operate(OutputStream *pOS)
{
    pOS->Write("Some text");
    pOS->Close();
}

void Compress()
{
    FileOutputStream fs{ "compression.txt" };
    CompressedOutputStream output{&fs};
    Operate(&output);
    /*output.Write("First line");
    output.Write("Second line");
    output.Write("Third line");*/
}

void Decompress()
{
    FileInputStream fs{ "compression.txt" };
    DecompressedInputStream input{ &fs };
    std::string text{};
    while(input.Read(text))
    {
        std::cout << text << std::endl;
    }
}



int main()
{
    //BufferedWrite();
    //BufferedRead();
    /*Encrypt();
    Decrypt();*/
   /* Compress();
    Decompress();*/

    FileInputStream fsInput{ "mix.txt" };
    BufferedInputStream bsInput{ &fsInput };
    DecompressedInputStream decInput{ &bsInput };

}
