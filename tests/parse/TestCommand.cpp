#include "TestCommand.hpp"

#include <iostream>

bool TestCommand::Call(const std::vector<std::string>& args)
{
    if(args.size() != m_ExpectedValues.size())
    {
        std::cerr << "Invalid argument count. Expected " << m_ExpectedValues.size() << " but got " << args.size() << std::endl;
        return false;
    }

    for(std::size_t i = 0; i < m_ExpectedValues.size(); i++)
    {
        const std::string& expected = m_ExpectedValues[i];
        const std::string& arg = args[i];

        if(expected != arg)
        {
            std::cerr << "Invalid argument. Expected '" << expected << "' but got '" << arg << "'" << std::endl;
            return false;
        }
    }

    return true;
}
