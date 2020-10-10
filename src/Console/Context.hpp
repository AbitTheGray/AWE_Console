#pragma once

#include <memory>
#include <map>
#include <string>
#include <vector>

#include "Command.hpp"

namespace AWE::Console
{
    typedef std::map<std::string, std::shared_ptr<Command>> Context;
}
