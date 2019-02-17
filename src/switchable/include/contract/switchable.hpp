#ifndef CONTRACT_CUSTOMIZABLE_HPP
#define CONTRACT_CUSTOMIZABLE_HPP

#pragma once

#include "contract/base.hpp"

CONTRACT_BEGIN

using HandlerType = void(*)(const ContractInfo& contract);

HandlerType SetContractViolationHandler(HandlerType handler);

CONTRACT_END

#endif
