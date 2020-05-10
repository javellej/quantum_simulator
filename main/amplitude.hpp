#pragma once

#include <types.hpp>
#include <complex>

/**
 * This class represents amplitudes associated with base states in a superposition
 * TODO check which is more optimal between re/im representation or radius/angle.
 */
class Amplitude
{
public:
    constexpr
    Amplitude( f64 real=0, f64 imag=0 ) : m_amplitude( real, imag ) {}

    constexpr f64
    Re() { return m_amplitude.real(); }

    constexpr f64
    Im() { return m_amplitude.imag(); }

    Amplitude
    operator+( const Amplitude &other ) const
    {
        return Amplitude( m_amplitude + other.m_amplitude );
    }

    Amplitude
    operator-( const Amplitude &other ) const
    {
        return Amplitude( m_amplitude - other.m_amplitude );
    }

    Amplitude
    operator*( const Amplitude &other ) const
    {
        return Amplitude( m_amplitude * other.m_amplitude );
    }

    Amplitude
    operator-() const
    {
        return Amplitude( -1 ) * *this;
    }

    void
    operator*=( const Amplitude &other )
    {
        m_amplitude *= other.m_amplitude;
    }

private:
    std::complex<f64> m_amplitude;

    constexpr
    Amplitude( std::complex<f64> cplx_amp ) : m_amplitude(cplx_amp) {}
};
