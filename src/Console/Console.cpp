#include "Console.hpp"

namespace AWE::Console
{
    static std::tuple<std::string, const char*> ParseString(const char* input)
    {
        char prefix;
        switch(input[0])
        {
            [[likely]]
            default:
                prefix = '\0';
                break;

            [[unlikely]]
            case '\0': // Empty input
                return {
                    std::string(),
                    input // Same character, \0
                };

            case '\'':
            case '\"':
                prefix = input[0];
                break;
        }

        if(prefix == '\0')
        {
            while(input[0] == ' ' || input[0] == '\t')
                input++;
        }

        for(std::size_t i = prefix == '\0' ? 0 : 1; true; i++)
        {
            char c = input[i];
            if(c == prefix && prefix != '\0')
            {
                if(i == 1)
                {
                    return {
                        std::string(),
                        input // Same character, \0
                    };
                }
                return {
                    std::string(input + 1, i - 1),
                    input + (i + 1) // Next character, \0 or any valid
                };
            }
            switch(c)
            {
                [[likely]]
                default:
                    continue;

                case '\0':
                    return {
                        std::string(input, i),
                        input + i // Same character, \0
                    };

                case ' ':
                case '\t':
                    if(prefix == '\0')
                    {
                        return {
                                std::string(input, i),
                                input + (i + 1) // Next character, \0 or any valid
                        };
                    }
                    else
                        continue;
            }
        }

        // Function never reaches this comment
    }

    [[nodiscard]] CommandResult Console::Call(const char* input) const
    {
        auto [ command, argInput ] = ParseString(input);
        if(*argInput == '\0') // Input ends after command
            return Call(command, std::vector<std::string>());

        std::vector<std::string> args;
        {
            while(true)
            {
                auto [ arg, nextArgInput ] = ParseString(argInput);
                if(*nextArgInput == '\0')
                {
                    if(arg.length() > 0)
                        args.emplace_back(arg);
                    break;
                }

                argInput = nextArgInput;

                args.emplace_back(arg);
            }
        }

        return Call(command, args);
    }
}
