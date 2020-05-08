# Quantum Circuit Simulator

This project demonstrates the simlutaion of quantum circuit with a universal set of gates on a limited number of 1-qubit registers.
Noise is not taken into account, which makes the simulation unrealistic in that regard, for now.


## Dependencies

This project targets a linux environment with the following tools installed:
   - `make`
   - `g++`


## Build the project

Simply type `make` at the root of the project.
Two binaries will be produced:
   - `build/unit` that runs the unit tests
   - `build/run_circuit` that runs the main circuit

Compilation in debug mode (with symbols and optimisation turned off) is done with `make debug` and compilation in release mode (with optimisations and LTO) with `make release`.
