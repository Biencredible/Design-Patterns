#include "DecompressedInputStream.h"
//#include "comp_util.h"

bool DecompressedInputStream::Read(std::string& text)
{
    //std::string compText{};
    auto result = m_pIS->Read(text);
    //text = Decompress(compText);
    return result;
}

void DecompressedInputStream::Close()
{
    m_pIS->Close();
}
