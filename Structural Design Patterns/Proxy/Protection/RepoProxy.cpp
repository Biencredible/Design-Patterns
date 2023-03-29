#include "RepoProxy.h"
#include "Repository.h"

bool RepoProxy::isAuthorized() const
{
}

Employee* RepoProxy::GetUser() const
{
    return m_pRepo->GetUser();
}

void RepoProxy::SetEmployee(Employee* emp)
{
    m_pRepo->setEmployee(emp);
}

void RepoProxy::SetAuthorizedRoles(std::initializer_list<std::string> authorizedRoles)
{
}

RepoProxy::RepoProxy(const std::string& path) : m_pRepo({new Repository{path}})
{
}

void RepoProxy::CreateFile(const std::string& fileName)
{
}

void RepoProxy::DeleteFile(const std::string& fileName)
{
}

void RepoProxy::UpdateFile(const std::string& fileName)
{
}

void RepoProxy::ViewFile(const std::string& fileName)
{
}

RepoProxy::~RepoProxy()
{
    delete m_pRepo;
}
