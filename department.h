#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "node.h"

#include <string>

using namespace std;

namespace organization {

class Department : private Node
{
private:
    string domainid;

public:
    Department();

};

}
#endif // DEPARTMENT_H
