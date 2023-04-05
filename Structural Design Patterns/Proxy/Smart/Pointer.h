#pragma once
template<typename T>
class Pointer
{
    T* m_ptr;
public:

    explicit Pointer(T* ptr)
        : m_ptr(ptr)
    {
    }

    ~Pointer()
    {
        delete m_ptr;
    }

    T* Get()
    {
        return m_ptr;
    }
};

