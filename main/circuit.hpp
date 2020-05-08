#pragma once

#include <types.hpp>
#include <gate.hpp>
#include <vector>

template<class T> using vector = std::vector<T>;

/**
 * A circuit is composed of gates between available registers placed sequentially.
 * Parallel gates are appended in no definite order as gates that act on exclusive
 * registers commute.
 */
class Circuit
{
public:
    // TODO maybe registers could be global to allow compile-time type resolution?
    Circuit( u32 num_qubits );

    /**
     * Display current state of the system at some point in the execution
     * NOTE : for Debug only, violates uncertainty principle :)
     */
    void
    PrintState();

private:
    u32 m_num_qubits;
    vector<f64>  m_phases;
    vector<Gate> m_gates;
};
