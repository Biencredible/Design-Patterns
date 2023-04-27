#include "CompressedOutputStream.h"
//#include "comp_util.h"

void CompressedOutputStream::Write(const std::string& text)
{
    auto cmpText = text;//Compress(text);
    m_pOS->Write(cmpText);
}

void CompressedOutputStream::Close()
{
    m_pOS->Close();
}
