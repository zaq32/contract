#ifndef CONTRACT_BASE_HPP
#define CONTRACT_BASE_HPP

#pragma once

#define CONTRACT_BEGIN namespace contract {
#define CONTRACT_END }

CONTRACT_BEGIN

#define CONTRACT_CONCAT_(x, y) x ## y
#define CONTRACT_CONCAT(x, y) CONTRACT_CONCAT_(x, y)
#define CONTRACT_STRING_(x) #x
#define CONTRACT_STRING(x) CONTRACT_STRING_(x)

#ifdef CONTRACT_UNICODE
    using tchar = wchar_t;

#define CONTRACT_TXT(x) CONTRACT_CONCAT_(L, x)
#else
    using tchar = char;

#define CONTRACT_TXT(x) x
#endif


class ContractInfo;

CONTRACT_END

#ifndef CONTRACT_PRECONDITION_NAME
#define CONTRACT_PRECONDITION_NAME CONTRACT_TXT("Precondition '")
#endif

#ifndef CONTRACT_POSTCONDITION_NAME
#define CONTRACT_POSTCONDITION_NAME CONTRACT_TXT("Postcondition '")
#endif

#ifndef CONTRACT_ASSERTION_NAME
#define CONTRACT_ASSERTION_NAME CONTRACT_TXT("Assertion '")
#endif

#ifndef CONTRACT_VIOLATION_NAME
#define CONTRACT_VIOLATION_NAME CONTRACT_TXT("' violation")
#endif

#endif
