#ifndef MEMBER_H
#define MEMBER_H

#include "node.h"

#include <string>

using namespace std;


/**
 * 范式：
 * 1）、符合1NF的关系中的每个属性都不可再分。
2）、2NF在1NF的基础之上，消除了非主属性对于码的部分函数依赖。
3）、3NF在2NF的基础之上，消除了非主属性对于码的传递函数依赖。
4）、BCNF在3NF的基础之上，消除主属性对于码的部分与传递函数依赖。
考虑符合BC范式。BC范式简单说就是“关系模式中存在的函数依赖的左侧只能是候选码”，所以非主属性不能出现在"->"左侧，主属性，如果它只是候选码的一部分，也不能出现在左侧。
分解的原则是将所有左侧依赖作为主码新建表

*
 *
部门人数单独建表？

索引；namexxx需要建立索引便于查询
外键；部门是member的外键
not null；namexxx不允许null
完整性约束：使用事务+initially defferred延迟完整性检查parentId。
parentId需要有。


视图；
事务；
权限；
内存数据库；
数据库自带递归查询；
用联系表示父子关系，而非parentId。一个表的主键一般不应该作为另一个表的属性，而应该用联系表关联起来。

多考虑使用数据库自带的特性实现。如递归、区间查询。

部门人数实现：1、增加字段membernum；2、即时查询。
1获取num方便直接获取即可，但维护麻烦，任何时候一个member添加或删除需更新其所有上级节点的num，不然会出现数据不一致问题（可以在每次启动时校准一次，但这又相当于把方案2的事情做了）。
num字段可否自动关联事件自动变更？trigger？第一次时不要trigger，先计算完了后再添加trigger

2获取num效率较低需要遍历计算出人数（可以只在展示时查一次，后续如果增删了人再修改），优点是不需要维护num字段。
*/
namespace organization {

class Member : private Node
{
private:
    // string moid; moid当做ID
    string e164;
    // string jid; 目前jid仅仅是在moid后面加了@kedacom.com，可以省略。
    string account;
    string landlinenumber;
    string mobilenumber;
    string email;
    string seat;
    string introduction;
    string portrait128;
    string portrait64;
    string portrait40;

public:
    Member();

};

}
#endif // MEMBER_H
