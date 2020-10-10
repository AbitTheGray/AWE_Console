#pragma once

#include <utility>
#include <iostream>

#include "CommandResult.hpp"
#include "Context.hpp"

namespace AWE::Console
{
    class Console
    {
    public:
        explicit Console() : m_Context()
        {
        }
        explicit Console(const AWE::Console::Context& context) : m_Context(std::make_shared<AWE::Console::Context>(context))
        {
        }
        explicit Console(std::shared_ptr<AWE::Console::Context> context) : m_Context(std::move(context))
        {
        }

    private:
        std::shared_ptr<AWE::Console::Context> m_Context;
    public:
        [[nodiscard]] inline std::shared_ptr<const AWE::Console::Context> Context() const noexcept { return m_Context; }
        [[nodiscard]] inline const std::shared_ptr<AWE::Console::Context>& Context() noexcept { return m_Context; }

    public:
        /// Call specified command.
        /// Returns
        ///  - `true`
        ///    - Command was found (and executed)
        ///  - `false`
        ///    - Command not found
        ///    - Executing command threw exception
        /// Returns `false` if the command was found but threw exception.
        [[nodiscard]] CommandResult Call(const std::string& command, const std::vector<std::string>& args) const
        {
            auto it = m_Context->find(command);
            if(it != m_Context->end())
            {
                auto& cmd = it->second;
                try
                {
                    return cmd->Call(args) ? CommandResult::Command_OK : CommandResult::Command_Fail;
                }
                catch(std::runtime_error& ex)
                {
                    std::cerr << "Executing command " << command << " threw exception: " << ex.what() << std::endl;
                    return CommandResult::Exception;
                }
            }

            return CommandResult::Not_Found;
        }
        [[nodiscard]] CommandResult Call(const char* input) const;

    };
}
