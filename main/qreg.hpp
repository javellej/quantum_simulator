#pragma once

#include <types.hpp>

/**
 * Simple abstract wrapper around an integer index used for type safety.
 * On modern compilers this is optimised out and incurs no performance penalty.
 */
class QReg
{
public:
    QReg( u32 reg_index );

private:
    u32 m_index;
};
