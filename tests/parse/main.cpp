#include <iostream>

#include <Console/Console.hpp>

#include "TestCommand.hpp"

static AWE::Console::Context CreateContext(const std::map<std::string, std::vector<std::string>>& testCases)
{
    auto context = AWE::Console::Context();

    for(const auto& it : testCases)
        context[it.first] = std::make_shared<TestCommand>(it.second);

    return context;
}

int main(int argc, const char** argv)
{
    AWE::Console::Context context = CreateContext(
            std::map<std::string, std::vector<std::string>>{
                    {
                            "test1",
                            {
                            }
                    },
                    {
                            "test2",
                            {
                                    "2"
                            }
                    },
                    {
                            "test3",
                            {
                                    "3"
                            }
                    },
                    {
                            "test4",
                            {
                                    "4 3 2 1"
                            }
                    },
                    {
                            "test5",
                            {
                                    "5",
                                    "5"
                            }
                    },
                    {
                            "test6",
                            {
                                    "6",
                                    "6"
                            }
                    },
                    {
                            "test7",
                            {
                                    "1 2 3",
                                    "4",
                                    "5 6",
                                    "7"
                            }
                    },
                    {
                            "test8",
                            {
                                    "1 2 3",
                                    "4\"5",
                                    R"(6"7'"'8"'")"
                            }
                    },
                    {
                            "test9",
                            {
                                    "1 2 3",
                                    "4",
                                    "5 6",
                                    "7",
                                    "\"",
                                    "8",
                                    "\'"
                            }
                    }
            }
    );

    AWE::Console::Console console = AWE::Console::Console(context);

#define TEST_CALL(input)\
    std::cout << "Input: " << input << std::endl;\
    if(console.Call(input) == AWE::Console::CommandResult::Command_OK)\
        std::cout << "    OK" << std::endl;\
    else\
    {\
        std::cout << "    TEST FAILED" << std::endl;\
        allOK = false;\
    }

    bool allOK = true;

    TEST_CALL("test1");
    TEST_CALL("test2 2");
    TEST_CALL("test3 '3'");
    TEST_CALL("test4 '4 3 2 1'");
    TEST_CALL("test5 5 5");
    TEST_CALL("test6 6 6 ");
    TEST_CALL(R"(test7 '1 2 3' 4 "5 6"7)");
    TEST_CALL(R"(test8 '1 2 3'4"5 6"7'"'8"'")");
    TEST_CALL(R"(test9 '1 2 3'4 "5 6"7 '"'8 "'")");

    std::cout << std::endl;
    if(allOK)
    {
        std::cout << "All tests finished successfully" << std::endl;
        return 0; // OK
    }
    else
    {
        std::cout << "All tests finished but there was a problem" << std::endl;
        return 1; // Problem
    }
}
