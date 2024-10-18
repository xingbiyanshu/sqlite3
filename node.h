#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

namespace organization {

class Node
{
protected:
    string id; // 对于部门是domainmoid+部门id（因为部门id仅在域内唯一），其余的情况均为moid
    string parentid; // 对于非顶级部门是id,对于顶级部门是domainmoid。对于member的情况呢，一个member可以任职于多个部门。删除parentid通过关系表来？
    string name;
    string namepinyin;
    string nameacronym;
    // int leafnum; // 关联事件，自动变更？trigger

protected:
    Node();
};

} // namespace organization

#endif // NODE_H
