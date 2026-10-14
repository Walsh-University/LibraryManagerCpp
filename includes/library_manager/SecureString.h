#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace library_manager {
    class SecureString {
    public:
        SecureString() = default;
        explicit SecureString(std::string_view value);
        ~SecureString();

        SecureString(const SecureString&) = delete;
        SecureString& operator=(const SecureString&) = delete;
        SecureString(SecureString&& other) noexcept;
        SecureString& operator=(SecureString&& other) noexcept;

        [[nodiscard]] std::size_t size() const noexcept { return value_.size(); }
        [[nodiscard]] bool empty() const noexcept { return value_.empty(); }
        [[nodiscard]] std::string reveal() const;

    private:
        void clear() noexcept;
        std::vector<char> value_;
    };
}
