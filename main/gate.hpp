#pragma once

#include <qreg.hpp>
#include <types.hpp>
#include <cassert>


/**
 * A gate corresponds to a unitary operation between a certain amount of registers.
 * The reversibility of unitary gates makes it such that the number of inputs is the
 * same as the number of output links.
 *
 * We use an inheritance model to specialise gates down to instantiable classes.
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

    constexpr
    Gate() {}


    virtual void
    Apply() const = 0;
};


class GateX : public Gate
{
public:
    constexpr
    GateX( QReg reg ) : m_reg(reg) {}

    void
    Apply() const;

private:
    QReg m_reg;
};
