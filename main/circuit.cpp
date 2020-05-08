#include <circuit.hpp>
#include <bitset>
#include <iostream>
#include <cassert>


Circuit::Circuit( u32 num_qubits )
  : m_num_qubits(num_qubits)
{
    assert( 32 >= num_qubits );

    u64 num_phases = 1 << num_qubits;

    std::cout << "DEBUG : " << num_phases << " phases in circuit" << std::endl;

    m_phases = vector<f64>( num_phases, 0 );
    m_phases[0] = 1; // initial state is |0...0>
}


void
Circuit::PrintState()
{
    for ( u64 i=0; i<m_phases.size(); ++i )
    {
        if ( 0 != i ) std::cout << " + ";

        std::bitset<32> ket( i );

        std::cout << m_phases[i] << " |";
        for ( u32 b=0; b<m_num_qubits; ++b )
        {
            std::cout << ket[m_num_qubits-b-1];
        }
        std::cout << ">";
    }

    std::cout << std::endl;
}
