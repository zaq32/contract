#include <atomic>
#include <cstdlib>
#include "contract/switchable.hpp"

CONTRACT_BEGIN

[[noreturn]] static void AbortOnViolation(const ContractInfo& /*contract*/)
{
    std::abort();
}

static std::atomic<HandlerType> handler = AbortOnViolation;

void OnContractViolated(const ContractInfo& contract)
{
    handler.load()(contract);
}

HandlerType SetContractViolationHandler(HandlerType newHandler)
{
    if (newHandler == nullptr)
    {
        handler.store(AbortOnViolation);
    }

    return handler.exchange(newHandler);
}

CONTRACT_END
