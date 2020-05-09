#pragma once

#include <gate.hpp>
#include <phase.hpp>
#include <types.hpp>
#include <vector>


/**
 * A circuit is composed of gates between available registers placed sequentially.
 * Parallel gates are appended in no definite order as gates that act on exclusive
 * registers commute.
 *
 * We represent a circuit as a list of gates in a specific order and we leave the registers
 * out of the circuit representation.
 */
class Circuit
{
public:
    Circuit();

    /**
     * Display current state of the system at some point in the execution
     * NOTE : for Debug only, violates uncertainty principle :)
     */
    void
    PrintState();

    /**
     * Put the input gate at the end of the circuit.
     */
    void
    AddGate( const Gate * gate );

    /**
     * Run the circuit following the gates in order.
     * NOTE : Side effect : affects the global phases (as expected)
     */
    void
    Run() const;

private:
    std::vector<const Gate *> m_gates;
};
