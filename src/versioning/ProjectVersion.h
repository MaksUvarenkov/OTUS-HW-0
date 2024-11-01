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


	class ProjectVersion {

		friend class Singleton<ProjectVersion>;

	private:

		const std::string_view _projectVersionMajor = "1";
		const std::string_view _projectVersionMinor = "2";
		const std::string_view _projectVersionBuild = "3";

	public:

		[[nodiscard]] std::string GetVersion() const {
			return {std::string(_projectVersionMajor) + "." + std::string(_projectVersionMinor) + "." +
					std::string(_projectVersionBuild)};
		}


	};

	typedef Singleton<otus_hw::ProjectVersion> VersionProvider;
}


#endif // VERSION_H_IN