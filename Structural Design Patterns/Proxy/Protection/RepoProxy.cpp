#include "RepoProxy.h"
#include "Repository.h"
//#include <valarray>
#include "Employee.h"
#include <iostream>

bool RepoProxy::isAuthorized() const
{
    if(m_AuthorizedRoles.empty())
    {
        throw std::runtime_error{ "Authorized roles not set" };
    }
    return std::any_of(std::begin(m_AuthorizedRoles), std::end(m_AuthorizedRoles), 
                       [this](const std::string& role)
    {
        return GetUser()->getMRole() == role;
    });
    
}

Employee* RepoProxy::GetUser() const
{
    return m_pRepo->GetUser();
}

void RepoProxy::setEmployee(Employee* emp)
{
    m_pRepo->setEmployee(emp);
}

void RepoProxy::SetAuthorizedRoles(std::initializer_list<std::string> authorizedRoles)
{
    m_AuthorizedRoles.assign(authorizedRoles);
}

RepoProxy::RepoProxy(const std::string& path) : m_pRepo{ new Repository{path} }
{
}

void RepoProxy::CreateFile(const std::string& fileName)
{
    if(isAuthorized())
    {
        m_pRepo->CreateFile(fileName);
    }
    else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to create a file\n";
    }
}

void RepoProxy::DeleteFile(const std::string& fileName)
{
    if(isAuthorized())
    {
        m_pRepo->DeleteFile(fileName);
    }
    else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to delete a file\n";
    }
}

void RepoProxy::UpdateFile(const std::string& fileName)
{
    if(isAuthorized())
    {
        m_pRepo->UpdateFile(fileName);
    }
    else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to update a file\n";
    }
}

void RepoProxy::ViewFile(const std::string& fileName)
{
    if(isAuthorized())
    {
        m_pRepo->ViewFile(fileName);
    }
    else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to view a file\n";
    }
}

RepoProxy::~RepoProxy()
{
    delete m_pRepo;
}
