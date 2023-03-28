#include "Employee.h"
#include <sstream>

Employee::Employee(const std::string& name, const std::string& role)
    : m_Name(name),
    m_Role(role)
{
}

std::string Employee::GetInfo() const
{
    std::ostringstream out;
    out << '[' << m_Role << '[' << m_Name << ' ';
    return out.str();
}

std::string Employee::getMName() const
{
    return m_Name;
}


std::string Employee::getMRole() const
{
    return m_Role;
}
