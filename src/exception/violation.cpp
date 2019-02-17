#include "contract/exception.hpp"

CONTRACT_BEGIN

void OnContractViolated(const ContractInfo& contract)
{
    ThrowContactViolatedException(contract);
}

CONTRACT_END
