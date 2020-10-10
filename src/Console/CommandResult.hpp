#pragma once

namespace AWE::Console
{
    enum class CommandResult
    {
        Command_OK = 0,
        Command_Fail,
        Exception,
        Not_Found
    };
}
