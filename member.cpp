#include "member.h"

namespace organization {

int Member::getId() const
{
    return id;
}

void Member::setId(int newId)
{
    id = newId;
}

std::string Member::getName() const
{
    return name;
}

void Member::setName(const std::string &newName)
{
    name = newName;
}

int Member::getBirthday() const
{
    return birthday;
}

void Member::setBirthday(int newBirthday)
{
    birthday = newBirthday;
}

Gender Member::getGender() const
{
    return gender;
}

void Member::setGender(Gender newGender)
{
    gender = newGender;
}

int Member::getDepartmentid() const
{
    return departmentids;
}

void Member::setDepartmentid(int newDepartmentid)
{
    departmentids = newDepartmentid;
}

Member::Member() {}

}
