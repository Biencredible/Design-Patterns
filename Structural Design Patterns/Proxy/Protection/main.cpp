#include "Repository.h"
#include "Employee.h"
#include "Storage.h"
#include <iostream>
#include "RepoProxy.h"

int main()
{
    try
    {
        RepoProxy repo{ R"(./)" };
        repo.SetAuthorizedRoles({ "RD-Leader", "Sales" });
        Employee e1{ "Fabian", "Programmer" };
        Employee e2{ "Marco", "RD-Leader" };
        Employee e3{ "Mario", "Sales" };

        repo.setEmployee(&e1);
        repo.CreateFile("data.txt");

        repo.setEmployee(&e2);
        repo.ViewFile("data.txt");
    }
    catch (std::exception &ex)
    {
        std::cout << "Exception:" << ex.what() << std::endl;
    }
}
