#include <constants.hpp>
#include <circuit.hpp>
#include <gate.hpp>
#include <amplitude.hpp>
#include <qreg.hpp>
#include <vector>
#include <iostream>


int
main( int argc, char *argv[] )
{
    if ( 1 != argc )
    {
        std::cout << "Syntax error, usage: \"" << argv[0] << "\"" << std::endl;
        return 1;
    }

    std::cout << "Circuit on " << k_num_qubits << " 1-qubit registers." << std::endl;

    Circuit circuit;

    circuit.PrintState();

    GateH gate( 0 );
    circuit.AddGate( &gate );
    circuit.Run();

    std::cout << "After gate applied" << std::endl;
    circuit.PrintState();

    return 0;
}
