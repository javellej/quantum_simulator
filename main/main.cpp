#include <constants.hpp>
#include <circuit.hpp>
#include <gate.hpp>
#include <amplitude.hpp>
#include <qreg.hpp>
#include <vector>
#include <iostream>


extern std::vector<Amplitude> g_amplitudes;


// As a demonstration of the circuit simulator we use th following application: creation
// of a graph state and check that the resulting state is an eigenvector of the stabilisers
// defined by the adjacency matrix of the underlyong graph.
int
main( int argc, char *argv[] )
{
    if ( 1 != argc )
    {
        std::cout << "Syntax error, usage: \"" << argv[0] << "\"" << std::endl;
        return 1;
    }

    Circuit circuit;

    std::cout << "Circuit on " << k_num_qubits << " 1-qubit registers." << std::endl;


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
    circuit.PrintState();


    // Step 2 : apply stabilisers and check state is unchanged

    // XZIIZ stabiliser
    GateX gate_11( 0 );
    circuit.AddGate( &gate_11 );
    GateZ gate_12( 1 );
    circuit.AddGate( &gate_12 );
    GateZ gate_13( 4 );
    circuit.AddGate( &gate_13 );
    std::cout << std::endl;
    circuit.ResetReg();
    circuit.Run();
    circuit.PrintState();

    // ZXZII stabiliser
    GateZ gate_14( 0 );
    circuit.AddGate( &gate_11 );
    GateX gate_15( 1 );
    circuit.AddGate( &gate_12 );
    GateZ gate_16( 2 );
    circuit.AddGate( &gate_13 );
    std::cout << std::endl;
    circuit.ResetReg();
    circuit.Run();
    circuit.PrintState();

    // IZXZI stabiliser
    GateZ gate_17( 1 );
    circuit.AddGate( &gate_11 );
    GateX gate_18( 2 );
    circuit.AddGate( &gate_12 );
    GateZ gate_19( 3 );
    circuit.AddGate( &gate_13 );
    std::cout << std::endl;
    circuit.ResetReg();
    circuit.Run();
    circuit.PrintState();

    // IIZXZ stabiliser
    GateZ gate_20( 2 );
    circuit.AddGate( &gate_11 );
    GateX gate_21( 3 );
    circuit.AddGate( &gate_12 );
    GateZ gate_22( 4 );
    circuit.AddGate( &gate_13 );
    std::cout << std::endl;
    circuit.ResetReg();
    circuit.Run();
    circuit.PrintState();

    // ZIIZX stabiliser
    GateZ gate_23( 0 );
    circuit.AddGate( &gate_11 );
    GateZ gate_24( 3 );
    circuit.AddGate( &gate_12 );
    GateX gate_25( 4 );
    circuit.AddGate( &gate_13 );
    std::cout << std::endl;
    circuit.ResetReg();
    circuit.Run();
    circuit.PrintState();

    return 0;
}
