#include <codecvt>
#include "contract/exception.hpp"

CONTRACT_BEGIN

#ifdef CONTRACT_UNICODE
static std::string WideToUtf8(const wchar_t* string)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(string, string + wcslen(string));
}
#endif

ContractViolationException::ContractViolationException(const ContractInfo& contract) :
    _contract(contract)
{
}

const char* ContractViolationException::what() const noexcept
{
#ifdef CONTRACT_UNICODE
    if (_message.empty())
    {
        _message = WideToUtf8(_contract.Comment());
    }

    return _message.c_str();
#else
    return _contract.Comment();
#endif
}

CONTRACT_END
