#pragma once
#include <cstdint>
#include <type_traits>
#include <concepts>
#include <compare>
#include <string>

#include "integer_bits.hpp"

namespace fpn
{
#if defined(__GNUC__) || (defined(_MSVC_LANG) && _MSVC_LANG >= 202600)
#   define FPN_CONSTEXPR_HAS 1
#   define FPN_CONSTEXPR constexpr
#endif
#ifndef FPN_CONSTEXPR
#   define FPN_CONSTEXPR_HAS 0
#   define FPN_CONSTEXPR
#endif
    /**
     * Fixed-point numbers.
     */
    template<std::size_t IntegralBits, std::size_t FractionalBits>
    struct fixed
    {
        static_assert(IntegralBits > 1);
        static_assert(FractionalBits > 0);
        static_assert(IntegralBits + FractionalBits <= 64);

        typename integer_bits<IntegralBits + FractionalBits>::signed_type Value;

        inline constexpr fixed() noexcept : Value() {}
        inline constexpr fixed(
            const decltype(Value) value
        ) noexcept : Value(value) {}
        inline explicit constexpr fixed(
            typename integer_bits<IntegralBits>::signed_type     integralValue,
            typename integer_bits<FractionalBits>::unsigned_type fractionalValue
        ) noexcept;
        template<std::size_t IB2, std::size_t FB2>
        inline constexpr fixed(fixed<IB2, FB2>) noexcept;

        // Copy
        inline constexpr fixed(const fixed& other) noexcept = default;
        inline constexpr fixed& operator=(const fixed& other) noexcept = default;
        // Move
        inline constexpr fixed(fixed&& other) noexcept = default;
        inline constexpr fixed& operator=(fixed&& other) noexcept = default;

        [[nodiscard]] inline constexpr operator bool() const noexcept { return Value; }

        [[nodiscard]] inline constexpr bool operator==(const fixed other) const noexcept { return Value == other.Value; }
        [[nodiscard]] inline constexpr auto operator<=>(const fixed other) const noexcept { return Value <=> other.Value; }

        [[nodiscard]] inline constexpr fixed operator-() const noexcept { return { -Value }; }

        /*
        [[nodiscard]] inline constexpr fixed operator++() noexcept;
        [[nodiscard]] inline constexpr fixed operator--() noexcept;
        [[nodiscard]] inline constexpr fixed operator++(int) noexcept;
        [[nodiscard]] inline constexpr fixed operator--(int) noexcept;
        */

#pragma region integers
        inline constexpr fixed(std::integral auto) noexcept;

        template<typename TI>
            requires std::integral<TI>
        [[nodiscard]] inline constexpr operator TI() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::integral auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::integral auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion

#pragma region floating-point numbers
        inline constexpr explicit fixed(std::floating_point auto) noexcept;

        template<typename TF>
            requires std::floating_point<TF>
        [[nodiscard]] inline constexpr explicit operator TF() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::floating_point auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::floating_point auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion

        //TODO Conversion to other fixed-point numbers
    };

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, fixed<IB, FB>) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline std::string to_string(fixed<IB, FB>);

#pragma region Other fixed-point numbers
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator+(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator-(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator*(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<std::size_t IB1, std::size_t FB1, std::size_t IB2, std::size_t FB2>
    [[nodiscard]] inline constexpr auto operator/(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
#pragma endregion

#pragma region integers
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, std::integral auto) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, std::integral auto) noexcept;

    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(std::integral auto, fixed<IB, FB>) noexcept;
    template<std::size_t IB, std::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(std::integral auto, fixed<IB, FB>) noexcept;
#pragma endregion
    
    using fixed8_8  = fixed<8,  8>;
    using fixed8_16 = fixed<8, 16>;
    using fixed8_24 = fixed<8, 24>;
    using fixed8_32 = fixed<8, 32>;
    using fixed8_40 = fixed<8, 40>;
    using fixed8_48 = fixed<8, 48>;
    using fixed8_56 = fixed<8, 56>;
    
    using fixed16_8  = fixed<16,  8>;
    using fixed16_16 = fixed<16, 16>;
    using fixed16_24 = fixed<16, 24>;
    using fixed16_32 = fixed<16, 32>;
    using fixed16_40 = fixed<16, 40>;
    using fixed16_48 = fixed<16, 48>;

    using fixed32_8  = fixed<32,  8>;
    using fixed32_16 = fixed<32, 16>;
    using fixed32_24 = fixed<32, 24>;
    using fixed32_32 = fixed<32, 32>;
}

#include "fixed.inl"

template<std::size_t IB, std::size_t FB>
struct std::hash<fpn::fixed<IB, FB>>
{
    [[nodiscard]] std::size_t operator()(const fpn::fixed<IB, FB>& value) const noexcept\
    {
        return value.Value;
    }
};
