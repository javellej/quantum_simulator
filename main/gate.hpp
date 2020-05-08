#pragma once

#include <types.hpp>

/**
 * A gate corresponds to a unitary operation between a certain amount of registers.
 * The reversibility of unitary gates makes it such that the number of inputs is the
 * same as the number of output links.
 */
class Gate
{
public:
    /**
     * Create gate with 'num_qubits' inputs and the same number fo outputs
     */
    Gate( u32 num_qubits );
};
