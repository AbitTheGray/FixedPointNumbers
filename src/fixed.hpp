#pragma once
#include <cstdint>
#include <type_traits>
#include <concepts>
#include <compare>
#include <string>

namespace Voxelite
{
    /**
     * Fixed-point numbers.
     *
     */
    struct fixed32_16
    {
        int64_t Value;
        static constexpr std::size_t IntegralBits = 32;
        static constexpr std::size_t FractionalBits = 16;

        inline constexpr fixed32_16() noexcept : Value() {}
        inline constexpr fixed32_16(
            const decltype(Value) value
        ) noexcept : Value(value) {}
        inline explicit constexpr fixed32_16(
            const decltype(Value) wholeValue,
            const decltype(Value) decimalValue
        ) noexcept;

        // Copy
        inline constexpr fixed32_16(const fixed32_16& other) noexcept = default;
        inline constexpr fixed32_16& operator=(const fixed32_16& other) noexcept = default;
        // Move
        inline constexpr fixed32_16(fixed32_16&& other) noexcept = default;
        inline constexpr fixed32_16& operator=(fixed32_16&& other) noexcept = default;

        [[nodiscard]] inline constexpr operator bool() const noexcept { return Value; }

        [[nodiscard]] inline constexpr bool operator==(const fixed32_16 other) const noexcept { return Value == other.Value; }
        [[nodiscard]] inline constexpr auto operator<=>(const fixed32_16 other) const noexcept { return Value <=> other.Value; }

        [[nodiscard]] inline constexpr fixed32_16 operator-() const noexcept { return { -Value }; }

        /*
        [[nodiscard]] inline constexpr fixed32_16 operator++() noexcept;
        [[nodiscard]] inline constexpr fixed32_16 operator--() noexcept;
        [[nodiscard]] inline constexpr fixed32_16 operator++(int) noexcept;
        [[nodiscard]] inline constexpr fixed32_16 operator--(int) noexcept;
        */

#pragma region integers
        inline constexpr fixed32_16(std::integral auto) noexcept;

        template<typename TI>
            requires std::integral<TI>
        [[nodiscard]] inline constexpr operator TI() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::integral auto other) const noexcept { return *this == fixed32_16(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::integral auto other) const noexcept { return *this <=> fixed32_16(other); }
#pragma endregion

#pragma region floating-point numbers
        inline constexpr explicit fixed32_16(std::floating_point auto) noexcept;

        template<typename TF>
            requires std::floating_point<TF>
        [[nodiscard]] inline constexpr explicit operator TF() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::floating_point auto other) const noexcept { return *this == fixed32_16(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::floating_point auto other) const noexcept { return *this <=> fixed32_16(other); }
#pragma endregion
    };
    static_assert(sizeof(fixed32_16) == sizeof(uint64_t));

    [[nodiscard]] inline constexpr fixed32_16 operator+(fixed32_16, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator-(fixed32_16, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator*(fixed32_16, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator/(fixed32_16, fixed32_16) noexcept;

    [[nodiscard]] inline std::string to_string(fixed32_16);

#pragma region integers
    [[nodiscard]] inline constexpr fixed32_16 operator+(fixed32_16, std::integral auto) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator-(fixed32_16, std::integral auto) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator*(fixed32_16, std::integral auto) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator/(fixed32_16, std::integral auto) noexcept;

    [[nodiscard]] inline constexpr fixed32_16 operator+(std::integral auto, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator-(std::integral auto, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator*(std::integral auto, fixed32_16) noexcept;
    [[nodiscard]] inline constexpr fixed32_16 operator/(std::integral auto, fixed32_16) noexcept;
#pragma endregion
}

#include "fixed.inl"

template<>
struct std::hash<Voxelite::fixed32_16>
{
    [[nodiscard]] std::size_t operator()(const Voxelite::fixed32_16& value) const noexcept\
    {
        return value.Value;
    }
};
