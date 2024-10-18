#ifndef GROUP_H
#define GROUP_H

#include "node.h"


namespace organization {

class Group : private Node
{
private:
    int version;
    string bloc;

public:
    Group();
};

} // namespace organization

#endif // GROUP_H
