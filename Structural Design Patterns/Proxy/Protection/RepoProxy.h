#pragma once
#include "Repository.h"
class RepoProxy :
    public Repository
{
    Repository* m_pRepo{};
    bool isAuthorized() const;
    std::vector<std::string>m_AuthorizedRoles;
public:
    Employee* GetUser() const;
    void SetEmployee(Employee* emp);
    void SetAuthorizedRoles(std::initializer_list<std::string> authorizedRoles);
    RepoProxy(const std::string &path);


    void CreateFile(const std::string& fileName) override;
    void DeleteFile(const std::string& fileName) override;
    void UpdateFile(const std::string& fileName) override;
    void ViewFile(const std::string& fileName) override;
    ~RepoProxy() override;
};

