#include <circuit.hpp>
#include <bitset>
#include <iostream>
#include <cstring>
#include <cassert>


Circuit::Circuit()
{
    // initialise phases to represent the state |0...0>
    //memset( &g_phases, 0, g_phases.size() * sizeof( Phase ) );
    g_phases[0] = Phase( 1, 0 );
}


void
Circuit::PrintState()
{
    for ( u64 i=0; i<g_phases.size(); ++i )
    {
        if ( 0 != i ) std::cout << " + ";

        std::bitset<32> ket( i );

        std::cout << "(" << g_phases[i].Im() << "i + " << g_phases[i].Re() << ") |";
        for ( u32 b=0; b<k_num_qubits; ++b )
        {
            std::cout << ket[k_num_qubits-b-1];
        }
        std::cout << ">";
    }

    std::cout << std::endl;
}
