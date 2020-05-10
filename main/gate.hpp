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
    friend class Circuit;

public:
    constexpr
    Gate() {}

private:
    virtual void
    Apply() const = 0;
};



// Pauli Gates

class GatePauli : public Gate
{
public:
    constexpr
    GatePauli( QReg reg ) : m_reg(reg) {}

protected:
    QReg m_reg;
};


class GateI : public GatePauli
{
public:
    constexpr
    GateI( QReg reg ) : GatePauli(reg) {}

private:
    void
    Apply() const;
};


class GateX : public GatePauli
{
public:
    constexpr
    GateX( QReg reg ) : GatePauli(reg) {}

private:
    void
    Apply() const;
};


class GateY : public GatePauli
{
public:
    constexpr
    GateY( QReg reg ) : GatePauli(reg) {}

private:
    void
    Apply() const;
};


class GateZ : public GatePauli
{
public:
    constexpr
    GateZ( QReg reg ) : GatePauli(reg) {}

private:
    void
    Apply() const;
};



// other 1-qubit: Hadamard, Rotations

class GateH : public Gate
{
public:
    constexpr
    GateH( QReg reg ) : m_reg(reg) {}

private:
    QReg m_reg;

    void
    Apply() const;
};


class GateRotation : public Gate
{
public:
    constexpr
    GateRotation( QReg reg, f64 angle ) : m_reg(reg), m_angle(angle) {}

private:
    QReg m_reg;
    f64  m_angle;

    void
    Apply() const;
};



// 2-qubit gates

class GateCNot : public Gate
{
public:
    constexpr
    GateCNot( QReg reg1, QReg reg2 ) : m_reg1(reg1), m_reg2(reg2) {}

private:
    QReg m_reg1;
    QReg m_reg2;

    void
    Apply() const;
};


class GateSwap : public Gate
{
public:
    constexpr
    GateSwap( QReg reg1, QReg reg2 ) : m_reg1(reg1), m_reg2(reg2) {}

private:
    QReg m_reg1;
    QReg m_reg2;

    void
    Apply() const;
};
