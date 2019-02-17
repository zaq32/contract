#ifndef CONTRACT_EXCEPTION_HPP
#define CONTRACT_EXCEPTION_HPP

#pragma once

#include <stdexcept>
#ifdef CONTRACT_UNICODE
#include <string>
#endif
#include "contract/contract.hpp"

CONTRACT_BEGIN

class ContractViolationException : public std::exception
{
public:
    ContractViolationException(const ContractInfo& contract);

    const char* what() const noexcept override;

    unsigned int Line() const;

    const tchar* File() const;

    const tchar* Function() const;

    const tchar* Comment() const;

private:
    ContractInfo _contract;
#ifdef CONTRACT_UNICODE
    mutable std::string _message;
#endif
};

inline unsigned int ContractViolationException::Line() const
{
    return _contract.Line();
}

inline const tchar* ContractViolationException::File() const
{
    return _contract.File();
}

inline const tchar* ContractViolationException::Function() const
{
    return _contract.Function();
}

inline const tchar* ContractViolationException::Comment() const
{
    return _contract.Comment();
}

[[noreturn]] inline void ThrowContactViolatedException(const ContractInfo& contract)
{
    throw ContractViolationException{contract};
}

CONTRACT_END


#endif
