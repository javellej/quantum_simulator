#include <gate.hpp>
#include <circuit.hpp>
#include <constants.hpp>
#include <cassert>


extern std::vector<Phase> g_phases;


// TODO this function gains at being optimised, it's the general bottleneck
void
GateX::Apply() const
{
    // MSB is register 0 by convention
    u32 reg_mask = 0x1 << ( k_num_qubits - 1 - *reinterpret_cast<const u32*>(&m_reg) );

    for (u32 i=0; i<k_num_phases; ++i)
    {
        // only swap once
        if ( 0x0 == ( i & reg_mask ) )
        {
            // swap i and i ^ reg_mask
            Phase tmp_phase_i = g_phases[i];
            g_phases[i] = g_phases[i^reg_mask];
            g_phases[i^reg_mask] = tmp_phase_i;
        }
    }
}
