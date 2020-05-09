#include <circuit.hpp>
#include <constants.hpp>
#include <bitset>
#include <iostream>
#include <cstring>
#include <cassert>


std::vector<Phase> g_phases( k_num_phases );


Circuit::Circuit()
{
    // initialise phases to represent the state |0...0>
    //memset( &g_phases, 0, g_phases.size() * sizeof( Phase ) );
    g_phases[0] = Phase( 1, 0 );
}


void
Circuit::PrintState()
{
    for ( u64 i=0; i<k_num_phases; ++i )
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


void
Circuit::AddGate( const Gate * gate )
{
    m_gates.push_back( gate );
}


void
Circuit::Run() const
{
    for ( auto& gate : m_gates )
    {
        gate->Apply();
    }
}
