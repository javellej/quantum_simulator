#include <circuit.hpp>
#include <constants.hpp>
#include <bitset>
#include <iostream>
#include <cstring>
#include <cassert>


// amplitudes are global to emulate the fact that physical registers exist in only one copy,
// independently from software.
std::vector<Amplitude> g_amplitudes( k_num_amplitudes );


Circuit::Circuit()
{
    // initialise amplitudes to represent the state |0...0>
    g_amplitudes = std::vector<Amplitude>( k_num_amplitudes, 0 );
    g_amplitudes[0] = Amplitude( 1, 0 );
}


void
Circuit::PrintState() const
{
    for ( u64 i=0; i<k_num_amplitudes; ++i )
    {
        if ( 0 != i ) std::cout << " + ";

        std::bitset<32> ket( i );

        std::cout << "(" << g_amplitudes[i].Re() << " + " << g_amplitudes[i].Im() << "i) |";
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


void
Circuit::ResetReg() const
{
    g_amplitudes = std::vector<Amplitude>( k_num_amplitudes, 0 );
    g_amplitudes[0] = Amplitude( 1, 0 );
}
