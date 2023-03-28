#pragma once
#include "Storage.h"
#include <filesystem>
class Employee;

class Repository :
    public Storage
{
    Employee* m_pEmp;
    std::filesystem::path m_CurrentPath{};
public:
    Employee* GetUser() const;
    void setEmployee(Employee* p);

    Repository(const std::string &repoPath);

    void CreateFile(const std::string& fileName) override;
    void DeleteFile(const std::string& fileName) override;
    void UpdateFile(const std::string& fileName) override;
    void ViewFile(const std::string& fileName) override;
};

