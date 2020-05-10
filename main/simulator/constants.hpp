#pragma once

#include <amplitude.hpp>
#include <types.hpp>

constexpr u32 k_num_qubits = 5;
static_assert( 32 > k_num_qubits ); // restriction to avoid integer overflow, could be relaxed in theory
constexpr u32 k_num_amplitudes = 0x1 << k_num_qubits;

constexpr Amplitude k_i( 0, 1 );
constexpr f64       k_pi = acos( -1 );
constexpr f64       k_sqrt_2_inv = 1 / sqrt( 2 );
