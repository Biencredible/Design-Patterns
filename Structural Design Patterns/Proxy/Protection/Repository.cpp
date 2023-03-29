#include "Repository.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "Employee.h"

Employee* Repository::GetUser() const
{
    return m_pEmp;
}

void Repository::setEmployee(Employee* p)
{
    m_pEmp = p;
}

Repository::Repository(const std::string& repoPath) : m_CurrentPath(repoPath)
{
}

void Repository::CreateFile(const std::string& fileName)
{
    auto path = m_CurrentPath;
    path /= fileName;
    std::ofstream out{ path };
    if(!out.is_open())
    {
        throw std::runtime_error{ "Could not create file" };
    }
    std::cout << GetUser()->GetInfo() << " is creating a file\n";
    std::string fileData;
    std::cout << "[CREATE] Enter data:";
    getline(std::cin, fileData);
    out << fileData;
    std::cout << "File created successfully!";
}

void Repository::DeleteFile(const std::string& fileName)
{
    auto path = m_CurrentPath;
    path /= fileName;
    if(!exists(path))
    {
        throw std::runtime_error{ "File does not exist" };
    }
    std::cout << GetUser()->GetInfo() << " is deleting a file\n";
    if(remove(path))
    {
        std::cout << "File deleted successfully!"; 
    }    
}

void Repository::UpdateFile(const std::string& fileName)
{
    auto path = m_CurrentPath;
    path /= fileName;
    std::ofstream out{ path };
    if(!out.is_open())
    {
        throw std::runtime_error{ "Could not create file" };
    }
    std::cout << GetUser()->GetInfo() << " is updating a file\n";
    std::string fileData;
    std::cout << "[UPDATE] Enter data:";
    getline(std::cin, fileData);
    out << "\n ##### UPDATE #####\n" << fileData;
    std::cout << "File updated successfully!";
}

void Repository::ViewFile(const std::string& fileName)
{
    auto path = m_CurrentPath;
    path /= fileName;
    std::ifstream in{ path };
    if(!in.is_open())
    {
        throw std::runtime_error{ "Could not open file" };
    }
    std::cout << GetUser()->GetInfo() << " is viewing a file\n";
    std::string line;
    while(std::getline(in, line))
    {
        std::cout << line << '\n';
    }
}
