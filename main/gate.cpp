#include <gate.hpp>
#include <cassert>


constexpr
Gate::Gate( Type type, QReg reg )
  : m_type(type), m_reg1(reg), m_reg2(), m_angle(0)
{
    assert( Type::I == type ||
            Type::X == type ||
            Type::Y == type ||
            Type::Z == type );
}


constexpr
Gate::Gate( Type type, QReg reg1, QReg reg2 )
  : m_type(type), m_reg1(reg1), m_reg2(reg2), m_angle(0)
{
    assert( Type::CNot == type ||
            Type::Swap == type );
}


constexpr
Gate::Gate( Type type, QReg reg, f64 angle )
  : m_type(type), m_reg1(reg), m_reg2(), m_angle(angle)
{
    assert( Type::Rotation == type );
}


void
Gate::Apply() const
{
    if ( Type::X == m_type )
    {

    }
}
