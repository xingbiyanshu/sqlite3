#include "department.h"


namespace organization {

Department::Department() {}

int Department::getId() const
{
    return id;
}

void Department::setId(int newId)
{
    id = newId;
}

std::string Department::getName() const
{
    return name;
}

void Department::setName(const std::string &newName)
{
    name = newName;
}

int Department::getSuperiorDepartmentid() const
{
    return superiorDepartmentid;
}

void Department::setSuperiorDepartmentid(int newSuperiorDepartmentid)
{
    superiorDepartmentid = newSuperiorDepartmentid;
}

}
