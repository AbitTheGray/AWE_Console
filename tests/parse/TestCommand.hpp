#pragma once

#include <Console/Command.hpp>

class TestCommand : public AWE::Console::Command
{
public:
    explicit TestCommand(std::vector<std::string> expectedValues) : m_ExpectedValues(std::move(expectedValues))
    {
    }

private:
    const std::vector<std::string> m_ExpectedValues;

public:
    bool Call(const std::vector<std::string>& args) override;
    [[nodiscard]] std::string Value() const noexcept override { return "Test Command"; }
};
