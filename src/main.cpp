#include <iostream>
#include <versioning/ProjectVersion.h>

//git config --add --local core.sshCommand 'ssh -i [SECRET_SSH_KEY_PATH]'

//Logger notes
//https://github.com/log4cplus/log4cplus
//https://stackoverflow.com/questions/6692238/better-logging-library-for-c

//I don't like to put Boost in all the projects.

//Implementing Boost tests
//https://github.com/starokurov/otus-cpp/blob/master/CMakeLists.txt


int main() {

	std::cout << "Hello, OTUS World!" << std::endl;
	std::cout << "Version is: " << otus_hw_0::ProjectVersion::GetVersion() << std::endl;

	return 0;
}
