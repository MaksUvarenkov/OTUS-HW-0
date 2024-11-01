#include <iostream>
#include <versioning/ProjectVersion.h>

//git config --add --local core.sshCommand 'ssh -i [SECRET_SSH_KEY_PATH]'


int main() {

	std::cout << "Hello, OTUS World!" << std::endl;

	std::cout << "Version is: " << otus_hw::VersionProvider::GetInstance().GetVersion() << std::endl;

	return 0;
}
