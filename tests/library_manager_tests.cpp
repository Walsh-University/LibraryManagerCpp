#include "library_manager/SecureString.h"

#include <utility>

int main() {
    using library_manager::SecureString;

    SecureString value{"library-card"};
    if (value.empty() || value.size() != 12 || value.reveal() != "library-card") {
        return 1;
    }

    SecureString moved{std::move(value)};
    if (!value.empty() || moved.reveal() != "library-card") {
        return 1;
    }

    return 0;
}
