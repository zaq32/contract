#ifndef CONTRACT_HPP
#define CONTRACT_HPP

#pragma once

#include "base.hpp"

CONTRACT_BEGIN

class ContractInfo final
{
    public:

    constexpr ContractInfo() = default;

    constexpr ContractInfo(
        const tchar* file, 
        const tchar* function, 
        const tchar* comment, 
        unsigned int line
        );

    constexpr unsigned int Line() const;

    constexpr const tchar* File() const;

    constexpr const tchar* Function() const;

    constexpr const tchar* Comment() const;

    private:

    const tchar* _file = CONTRACT_TXT("");
    const tchar* _function = CONTRACT_TXT("");
    const tchar* _comment = CONTRACT_TXT("");
    unsigned int _line = 0;
};

constexpr ContractInfo::ContractInfo(
    const tchar* file, 
    const tchar* function, 
    const tchar* comment, 
    unsigned int line
    ) :
    _file(file),
    _function(function),
    _comment(comment),
    _line(line)
{
}

constexpr unsigned int ContractInfo::Line() const
{
    return _line;
}

constexpr const tchar* ContractInfo::File() const
{
    return _file;
}

constexpr const tchar* ContractInfo::Function() const
{
    return _function;
}

constexpr const tchar* ContractInfo::Comment() const
{
    return _comment;
}

void OnContractViolated(const ContractInfo& contract);

inline void VerifyContract(
    bool condition, 
    const tchar* file, 
    const tchar* function, 
    const tchar* comment, 
    unsigned int line
    )
{
    if (!condition)
    {
        OnContractViolated(ContractInfo{file, function, comment, line});
    }
}

#define contract_expect(condition) ::contract::VerifyContract(                                      \
    condition,                                                                                      \
    CONTRACT_TXT(__FILE__),                                                                         \
    CONTRACT_TXT(__func__),                                                                         \
    CONTRACT_PRECONDITION_NAME CONTRACT_TXT(CONTRACT_STRING(condition)) CONTRACT_VIOLATION_NAME,    \
    __LINE__                                                                                        \
    )

#define contract_ensure(condition) ::contract::VerifyContract(                                      \
    condition,                                                                                      \
    CONTRACT_TXT(__FILE__),                                                                         \
    CONTRACT_TXT(__func__),                                                                         \
    CONTRACT_POSTCONDITION_NAME CONTRACT_TXT(CONTRACT_STRING(condition)) CONTRACT_VIOLATION_NAME,   \
    __LINE__                                                                                        \
    )

#define contract_assert(condition) ::contract::VerifyContract(                                      \
    condition,                                                                                      \
    CONTRACT_TXT(__FILE__),                                                                         \
    CONTRACT_TXT(__func__),                                                                         \
    CONTRACT_ASSERTION_NAME CONTRACT_TXT(CONTRACT_STRING(condition)) CONTRACT_VIOLATION_NAME,       \
    __LINE__                                                                                        \
    )

CONTRACT_END

#endif