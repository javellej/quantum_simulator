#pragma once

#include <types.hpp>

constexpr u32 k_num_qubits = 3;
static_assert( 32 > k_num_qubits ); // restriction to avoid integer overflow, could be relaxed in theory
constexpr u32 k_num_phases = 0x1 << k_num_qubits;
