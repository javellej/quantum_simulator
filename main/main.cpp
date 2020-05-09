#include <circuit.hpp>
#include <gate.hpp>
#include <qreg.hpp>
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

    Gate gate_x( Gate::Type::X, 0 );

    gate_x.Apply();

    circuit.PrintState();

    return 0;
}
