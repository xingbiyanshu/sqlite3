#ifndef BLOC_H
#define BLOC_H

#include <list>
#include <string>


using namespace std;

namespace organization {

/**集团
集团的概念就像是一个集装箱，把用户域和群组打包在一起。
这种组织是松散的，业务需要也可以新加用户域群组进来或删除已有的。
*/
class Bloc
{
private:
    string id;
    string name;
    list<string> topleveldomains;
    list<string> toplevelgroups;

public:
    Bloc();
};

} // namespace organization

#endif // BLOC_H
