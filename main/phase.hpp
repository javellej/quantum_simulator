#pragma once

#include <types.hpp>
#include <complex>

class Phase
{
public:
    constexpr
    Phase() : m_phase( 0, 0 ) {}

    constexpr
    Phase( f64 real, f64 imag ) : m_phase( real, imag ) {}

    constexpr f64
    Re() { return m_phase.real(); }

    constexpr f64
    Im() { return m_phase.imag(); }

private:
    std::complex<f64> m_phase;
};
