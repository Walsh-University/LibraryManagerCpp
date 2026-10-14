#include "library_manager/SecureString.h"
#include <algorithm>
#include <random>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace library_manager {
    SecureString::SecureString(const std::string_view value) : value_(value.begin(), value.end()) {}

    SecureString::~SecureString() { clear(); }

    SecureString::SecureString(SecureString&& other) noexcept : value_(std::move(other.value_)) {
        other.clear();
    }

    SecureString& SecureString::operator=(SecureString&& other) noexcept {
        if (this != &other) {
            clear();
            value_ = std::move(other.value_);
            other.clear();
        }
        return *this;
    }

    std::string SecureString::reveal() const { return {value_.begin(), value_.end()}; }

    void SecureString::clear() noexcept {
        volatile char* data = value_.data();
        for (std::size_t index = 0; index < value_.size(); ++index) {
            data[index] = '\0';
        }
        value_.clear();
    }

}
