#include <catch.hpp>
#include <circuit.hpp>
#include <gate.hpp>
#include <constants.hpp>
#include <vector>


extern std::vector<Amplitude> g_amplitudes;


TEST_CASE("Gates")
{
    Circuit circuit;

    SECTION("Hadamard gate")
    {
        // create uniform superposition
        GateH gate_1( 0 );
        circuit.AddGate( &gate_1 );
        GateH gate_2( 1 );
        circuit.AddGate( &gate_2 );
        GateH gate_3( 2 );
        circuit.AddGate( &gate_3 );
        GateH gate_4( 3 );
        circuit.AddGate( &gate_4 );
        GateH gate_5( 4 );
        circuit.AddGate( &gate_5 );

        circuit.Run();

        // check that all amplitudes are the same and with the correct value
        for ( const auto& amp : g_amplitudes )
        {
            REQUIRE( Amplitude( pow( k_sqrt_2_inv, k_num_qubits ) ).IsIdentical( amp ) );
        }
    }

    SECTION("Pauli X gate")
    {
        GateX gate_x( 2 );
        circuit.AddGate( &gate_x );
        circuit.Run();

        REQUIRE( Amplitude( 0 ).IsIdentical( g_amplitudes[0] ) );
        u32 qreg_index = 0x1 << (k_num_qubits-1) >> 2;
        REQUIRE( Amplitude( 1 ).IsIdentical( g_amplitudes[qreg_index] ) );
    }

    SECTION("Pauli Y gate")
    {
        GateY gate_y( 2 );
        circuit.AddGate( &gate_y );
        circuit.Run();

        REQUIRE( Amplitude( 0 ).IsIdentical( g_amplitudes[0] ) );
        u32 qreg_index = 0x1 << (k_num_qubits-1) >> 2;
        REQUIRE( g_amplitudes[qreg_index].IsIdentical( -k_i ) );
    }

    SECTION("Pauli Z gate")
    {
        // prepare the state |00100> first, then apply Z on register 2
        GateX gate_x( 2 );
        GateZ gate_z( 2 );
        circuit.AddGate( &gate_x );
        circuit.AddGate( &gate_z );
        circuit.Run();

        REQUIRE( Amplitude( 0 ).IsIdentical( g_amplitudes[0] ) );
        u32 qreg_index = 0x1 << (k_num_qubits-1) >> 2;
        REQUIRE( Amplitude( -1 ).IsIdentical( g_amplitudes[qreg_index] ) );
    }

    circuit.ResetReg();
}
