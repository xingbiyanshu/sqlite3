#include "memberbrief.h"

namespace organization {
int MemberBrief::getId() const
{
    return id;
}

void MemberBrief::setId(int newId)
{
    id = newId;
}

std::string MemberBrief::getName() const
{
    return name;
}

void MemberBrief::setName(const std::string &newName)
{
    name = newName;
}

int MemberBrief::getDepartmentid() const
{
    return departmentid;
}

void MemberBrief::setDepartmentid(int newDepartmentid)
{
    departmentid = newDepartmentid;
}

MemberBrief::MemberBrief() {}
}
