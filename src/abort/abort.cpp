#include <cstdlib>
#include "contract/base.hpp"

CONTRACT_BEGIN

void OnContractViolated(const ContractInfo& /*contract*/)
{
    std::abort();
}

CONTRACT_END
