#ifndef REPOSITORY_H
#define REPOSITORY_H

namespace organization {
// 封装数据的获取，从dao或者从缓存（缓存+数据库=数据全集。所以当缓存写入数据库后就删除。删除也包含在事务中）
class Repository
{
public:
    Repository();
};

} // namespace organization

#endif // REPOSITORY_H
