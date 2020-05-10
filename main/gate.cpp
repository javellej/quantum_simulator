#include <gate.hpp>
#include <circuit.hpp>
#include <constants.hpp>
#include <cassert>


extern std::vector<Amplitude> g_amplitudes;

constexpr Amplitude k_i( 0, 1 );
constexpr f64       k_pi = acos( -1 );
constexpr f64       k_sqrt_2_inv = 1 / sqrt( 2 );

u32
RegMask( QReg reg )
{
    // MSB is register 0 by convention
    return 0x1 << ( k_num_qubits - 1 - *reinterpret_cast<const u32*>(&reg) );
}


// TODO these functions gain at being optimised, it's the general bottleneck


void
GateI::Apply() const
{
}


void
GateX::Apply() const
{
    u32 reg_mask = RegMask( m_reg );

    for (u32 i=0; i<k_num_amplitudes; ++i)
    {
        // only swap once
        if ( 0x0 == ( i & reg_mask ) )
        {
            // swap i and i ^ reg_mask
            u32 i_0 = i;
            u32 i_1 = i ^ reg_mask;
            Amplitude a_0 = g_amplitudes[i_0];
            Amplitude a_1 = g_amplitudes[i_1];

            g_amplitudes[i_0] = a_1;
            g_amplitudes[i_1] = a_0;
        }
    }
}


void
GateY::Apply() const
{
    u32 reg_mask = RegMask( m_reg );

    for (u32 i=0; i<k_num_amplitudes; ++i)
    {
        // only swap once
        if ( 0x0 == ( i & reg_mask ) )
        {
            u32 i_0 = i;
            u32 i_1 = i ^ reg_mask;
            Amplitude a_0 = g_amplitudes[i_0];
            Amplitude a_1 = g_amplitudes[i_1];

            g_amplitudes[i_0] = -k_i * a_1;
            g_amplitudes[i_1] =  k_i * a_0;
        }
    }
}


void
GateZ::Apply() const
{
    u32 reg_mask = RegMask( m_reg );

    for (u32 i=0; i<k_num_amplitudes; ++i)
    {
        if ( 0x0 != ( i & reg_mask ) )
        {
            g_amplitudes[i] *= -1;
        }
    }
}




// other 1-qubit gates

void
GateH::Apply() const
{
    u32 reg_mask = RegMask( m_reg );

    for (u32 i=0; i<k_num_amplitudes; ++i)
    {
        if ( 0x0 == ( i & reg_mask ) )
        {
            u32 i_0 = i;
            u32 i_1 = i ^ reg_mask;
            Amplitude a_0 = g_amplitudes[i_0];
            Amplitude a_1 = g_amplitudes[i_1];

            g_amplitudes[i_0] = Amplitude( k_sqrt_2_inv ) * ( a_0 + a_1 );
            g_amplitudes[i_1] = Amplitude( k_sqrt_2_inv ) * ( a_0 - a_1 );
        }
    }
}


void
GateRotation::Apply() const
{
    u32 reg_mask = RegMask( m_reg );

    for (u32 i=0; i<k_num_amplitudes; ++i)
    {
        if ( 0x0 != ( i & reg_mask ) )
        {
            g_amplitudes[i] *= Amplitude( cos( m_angle ), sin( m_angle ) );
        }
    }
}




// 2-qubit gates

void
GateCNot::Apply() const
{
}

void
GateSwap::Apply() const
{
}
