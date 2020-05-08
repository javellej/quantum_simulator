#include <circuit.hpp>
#include <qreg.hpp>
#include <iostream>

int
main( int argc, char *argv[] )
{
    if ( 2 != argc )
    {
        std::cout << "Syntax error." << std::endl;
        return 1;
    }

    int num_registers = atoi( argv[1] );

    std::cout << "Circuit on " << num_registers << " registers." << std::endl;

    return 0;
}
