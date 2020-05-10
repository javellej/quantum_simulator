# Quantum Circuit Simulator

This project demonstrates the simlutaion of quantum circuit with a universal set of gates on a limited number of 1-qubit registers.
Noise is not taken into account, which makes the simulation unrealistic in that regard, for now.

The project in in an early stage of development and should be considered as an early prototype leveraging some of the C++ features and idioms.
Some unit tests have been provided however they do not provide a sufficient coverage at the moment.
The intention is more to show how unit tests could be made and extended.

The default number of qubits is 5, but it can be extended up to 31, to be set at compile time.


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


## Run the code

To run the main executable, simply type `./build/run_sim`.
This will create a 5 qubit circuit implementing the preparation of the C5 graph state, then apply the 5 stabilizers and check that the state stays invariant after each.

To run the unit tests simply type `./build/unit`.


## Future evolutions

We foresee several possible evolutions and optimisations for this project to make it quicker, safer, more realistic and cover more functionalities.
Among these are:
   - improve representation of `Amplitude` : at the moment it wraps around `std::complex`, however it might be better to retain phases and norm internally, which would be much more efficient for gates like rotations for example (adding phases instead of multiplying complex numbers)
   - incorporate parametrisable noise
   - add measurements : measuring a set of registers looks at the probabilities from square norms of phases and draw one of the basis states following the probability distribution
   - add classical communication (following measurements)
   - improve unit test coverage to near 100%
   - add SWAP test circuit to test for state equality
   - add controlled operators
   - add implementation of `Uf` the reversible version of the classical function `f` acting on base states : this requires a classical implementation of `f` and its inverse. Its implementation is not fundamentally different from other gates as it is simply about going through all the bases states and cyclicly permutate phases of `x`, `f(x)`, ... until reaching `x` again. The slight change is to remember which base states have already been encountered, but a bit field easily does the trick for example.
   - add templates of well-known circuits (phase estimation, Grover, teleportation, etc.)
   - parallelisation : we believe a lot can be done here, either within the implemetation of each gate `Apply` function (lots of independent amplitude updates), or by detecting commuting gates.
