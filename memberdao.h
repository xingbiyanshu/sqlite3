#ifndef MEMBERDAO_H
#define MEMBERDAO_H

#include "member.h"

#include <list>


namespace organization {

class MemberDao
{
public:
    MemberDao();

    virtual int add(const Member& member);
    virtual int del(std::string memberid);
    virtual int update(const Member& member);
    virtual Member& retrieve(std::string memberid);
    virtual std::list<Member&> retrieveByAcronym(std::string memberid);
};

} // namespace organization

#endif // MEMBERDAO_H
