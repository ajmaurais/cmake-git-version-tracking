#include <cstdlib>
#include <iostream>

#include <git.h>

int main() {
    // Demo that our macros work.
    if(GIT_RETRIEVED_STATE) {
        std::cout << "INFO: " << GIT_HEAD_SHA1 << std::endl;
        if(GIT_IS_DIRTY) std::cerr << "WARN: there were uncommitted changes." << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "WARN: failed to get the current git state. Is this a git repo?" << std::endl;
        return EXIT_FAILURE;
    }
}
