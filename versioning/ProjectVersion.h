#ifndef VERSION_H_IN
#define VERSION_H_IN

#include <string>
#include <string_view>
#include <templates/singleton/Singleton.h>

namespace otus_hw {

//https://community.gigperformer.com/t/getting-cmake-variables-from-c/17711
//https://www.modernescpp.com/index.php/thread-safe-initialization-of-a-singleton/

//clang
//static analyzers


class ProjectVersion  : public Singleton<ProjectVersion>
{
    private:

        const std::string_view PROJECT_VERSION_MAJOR = "@PROJECT_VERSION_MAJOR@";
        const std::string_view PROJECT_VERSION_MINOR = "@PROJECT_VERSION_MAJOR@";
        const std::string_view PROJECT_VERSION_BUILD = "@PROJECT_VERSION_MINOR@";
    
    public:

        std::string GetVersion() const { return ""; }


};





}


#endif // VERSION_H_IN