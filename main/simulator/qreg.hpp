#pragma once

#include <types.hpp>
#include <constants.hpp>
#include <limits>
#include <cassert>

/**
 * Simple abstract wrapper around an integer index used for type safety.
 * On modern compilers this is optimised out and incurs no performance penalty.
 */
class QReg
{
public:
    constexpr
    QReg() : m_index(std::numeric_limits<typeof(m_index)>::max()) {}

    constexpr
    QReg( u32 reg_index ) : m_index(reg_index) { assert( k_num_qubits > reg_index ); }

private:
    u32 m_index;
};
