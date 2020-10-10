#pragma once

#include <vector>
#include <string>

namespace AWE::Console
{
    class Command
    {
    public:
        virtual ~Command() = default;

    public:
        /// Command called from console.
        virtual bool Call(const std::vector<std::string>& args) { return false; }

        /// Command listed in the Console Intellisence.
        /// Preview of current value.
        /// Can be empty string.
        [[nodiscard]] virtual std::string Value() const noexcept { return "Not Implemented"; }
    };
}
