#include <constants.hpp>
#include <circuit.hpp>
#include <gate.hpp>
#include <amplitude.hpp>
#include <qreg.hpp>
#include <vector>
#include <iostream>


extern std::vector<Amplitude> g_amplitudes;


// this allows to save a copy of the state for analysis (non-quantum operation)
void
SaveState( std::vector<Amplitude> &state )
{
    state.clear();

    for ( const auto& amp : g_amplitudes )
    {
        state.push_back( amp );
    }
}


// checks equality between states
// TODO should be a swap test
bool
IsIdentical( std::vector<Amplitude> &state )
{
    for ( u32 i=0; i<k_num_amplitudes; ++i )
    {
        if ( !state[i].IsIdentical( g_amplitudes[i] ) ) return false;
    }

    return true;
}


// As a demonstration of the circuit simulator we use th following application: creation
// of a graph state and check that the resulting state is an eigenvector of the stabilisers
// defined by the adjacency matrix of the underlyong graph.
int
main()
{
    std::cout << "Creating circuit on " << k_num_qubits << " 1-qubit registers." << std::endl;

    Circuit circuit;


    // Step 1 : initialise registers to represent the C5 graph state (cycle of 5 vertices)

    // vertices
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

    // edges
    GateCZ gate_6( 0, 1 );
    circuit.AddGate( &gate_6 );
    GateCZ gate_7( 1, 2 );
    circuit.AddGate( &gate_7 );
    GateCZ gate_8( 2, 3 );
    circuit.AddGate( &gate_8 );
    GateCZ gate_9( 3, 4 );
    circuit.AddGate( &gate_9 );
    GateCZ gate_10( 4, 0 );
    circuit.AddGate( &gate_10 );

    circuit.Run();
    std::cout << "Graph state is :" << std::endl;
    circuit.PrintState();

    std::vector<Amplitude> state; // used to save a copy of the state for analysis
    SaveState( state );


    // Step 2 : apply stabilisers and check state is unchanged

    // XZIIZ stabiliser
    GateX gate_11( 0 );
    circuit.AddGate( &gate_11 );
    GateZ gate_12( 1 );
    circuit.AddGate( &gate_12 );
    GateZ gate_13( 4 );
    circuit.AddGate( &gate_13 );
    circuit.ResetReg();
    circuit.Run();
    if ( IsIdentical( state ) )
    {
        std::cout << "State is stabilised by XZIIZ" << std::endl;
    }
    SaveState( state );

    // ZXZII stabiliser
    GateZ gate_14( 0 );
    circuit.AddGate( &gate_14 );
    GateX gate_15( 1 );
    circuit.AddGate( &gate_15 );
    GateZ gate_16( 2 );
    circuit.AddGate( &gate_16 );
    circuit.ResetReg();
    circuit.Run();
    if ( IsIdentical( state ) )
    {
        std::cout << "State is stabilised by ZXZII" << std::endl;
    }
    SaveState( state );

    // IZXZI stabiliser
    GateZ gate_17( 1 );
    circuit.AddGate( &gate_17 );
    GateX gate_18( 2 );
    circuit.AddGate( &gate_18 );
    GateZ gate_19( 3 );
    circuit.AddGate( &gate_19 );
    circuit.ResetReg();
    circuit.Run();
    if ( IsIdentical( state ) )
    {
        std::cout << "State is stabilised by IZXZI" << std::endl;
    }
    SaveState( state );

    // IIZXZ stabiliser
    GateZ gate_20( 2 );
    circuit.AddGate( &gate_20 );
    GateX gate_21( 3 );
    circuit.AddGate( &gate_21 );
    GateZ gate_22( 4 );
    circuit.AddGate( &gate_22 );
    circuit.ResetReg();
    circuit.Run();
    if ( IsIdentical( state ) )
    {
        std::cout << "State is stabilised by IIZXZ" << std::endl;
    }
    SaveState( state );

    // ZIIZX stabiliser
    GateZ gate_23( 0 );
    circuit.AddGate( &gate_23 );
    GateZ gate_24( 3 );
    circuit.AddGate( &gate_24 );
    GateX gate_25( 4 );
    circuit.AddGate( &gate_25 );
    circuit.ResetReg();
    circuit.Run();
    if ( IsIdentical( state ) )
    {
        std::cout << "State is stabilised by ZIIZX" << std::endl;
    }

    return 0;
}
