#ifndef DOMAIN_H
#define DOMAIN_H

#include "node.h"

using namespace std;

namespace organization {

class Domain : private Node
{
private:
    int version;
    string bloc;

public:
    Domain();
};

} // namespace organization

#endif // DOMAIN_H
