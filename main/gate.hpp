#pragma once

#include <qreg.hpp>
#include <types.hpp>


/**
 * A gate corresponds to a unitary operation between a certain amount of registers.
 * The reversibility of unitary gates makes it such that the number of inputs is the
 * same as the number of output links.
 *
 * The Gate class is instantiated at compile time and contains internal attributes to
 * represent all types of supported gates.
 */
class Gate
{
public:
    enum Type : u8
    {
        I,
        X,
        Y,
        Z,
        Rotation,
        CNot,
        Swap
    };

    /**
     * 1-qubit gates
     */
    constexpr
    Gate( Type type, QReg reg );

    /**
     * 2-qubit gates
     */
    constexpr
    Gate( Type type, QReg reg1, QReg reg2 );

    /**
     * Rotation
     */
    constexpr
    Gate( Type type, QReg reg, f64 angle );

    void
    Apply() const;

private:
    Type m_type;
    QReg m_reg1;
    QReg m_reg2;  // only used for 2-qubit gates
    f64  m_angle; // only used for rotations
};
