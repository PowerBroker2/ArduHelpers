#pragma once
#include "Arduino.h"

/** @brief Float constant for pi */
constexpr float F_PI = 3.14159265358979323846f;

/**
 * @brief Forces all digital pins into a known HIGH state.
 *
 * This function configures every digital pin on the MCU as an OUTPUT and
 * drives it HIGH. It is particularly useful to prevent floating chip-select (CS)
 * lines on shared buses such as SPI, which can cause unintended device
 * selection and bus contention.
 */
inline void forceAllPinsHigh()
{
    for (uint8_t pin = 0; pin < NUM_DIGITAL_PINS; pin++)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }
}

/**
 * @brief Constrain a value between a minimum and maximum.
 *
 * Works for any numeric type: float, double, int, etc.
 *
 * @param input The value to constrain.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return Constrained value between min and max.
 */
template<typename T1, typename T2, typename T3>
inline auto constrain_val(const T1& input, const T2& min, const T3& max)
{
    using ReturnType = std::common_type_t<T1, T2, T3>;
    if (input > max) return static_cast<ReturnType>(max);
    if (input < min) return static_cast<ReturnType>(min);
    return static_cast<ReturnType>(input);
}

/**
 * @brief Map a value from one range to another.
 *
 * Works for any numeric type: float, double, int, etc.
 *
 * @tparam T Numeric type of input and ranges.
 * @param x The input value.
 * @param in_min The lower bound of the input range.
 * @param in_max The upper bound of the input range.
 * @param out_min The lower bound of the output range.
 * @param out_max The upper bound of the output range.
 * @return The mapped value in the output range.
 */
template<typename T1, typename T2, typename T3, typename T4, typename T5>
inline auto map_val(const T1& x,
                    const T2& in_min,
                    const T3& in_max,
                    const T4& out_min,
                    const T5& out_max)
{
    using ReturnType = std::common_type_t<T1, T2, T3, T4, T5>;
    return static_cast<ReturnType>((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

/**
 * @brief Returns the minimum of two values.
 *
 * This function works with any type that supports the `<` operator.
 *
 * @tparam T The type of the input values.
 * @param a First value.
 * @param b Second value.
 * @return The smaller of `a` and `b`.
 */
template<typename T1, typename T2>
inline auto min_val(const T1& a, const T2& b)
{
    using ReturnType = std::common_type_t<T1, T2>;
    return static_cast<ReturnType>((a < b) ? a : b);
}

/**
 * @brief Returns the maximum of two values.
 *
 * This function works with any type that supports the `>` operator.
 *
 * @tparam T The type of the input values.
 * @param a First value.
 * @param b Second value.
 * @return The larger of `a` and `b`.
 */
template<typename T>
inline T max_val(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

long factorial(const int& n);
