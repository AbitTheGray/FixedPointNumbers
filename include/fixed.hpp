#pragma once
#include <cstdint>
#include <type_traits>
#include <concepts>
#include <compare>
#include <string>
#include <numbers>

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
     * Signed fixed-point numbers.
     * @note There is no unsigned variant
     * Equivalent to integer of IntegralBits (8 -> int8_t, 16 -> int16_t) with additional FractionalBits for fractional part.
     * @note FractionalBits are not decimal places it will print. Best way to imagine it is as 1 over number of values of FractionalBits unsigned integer for minimum step (1 -> 1/2 = 0.5, 2 -> 1/4 = 0.25, 3 -> 1/8 = 0.125)
     */
    template<fpn::size_t IB, fpn::size_t FB>
    struct fixed
    {
        static constexpr fpn::size_t IntegralBits = IB;
        static constexpr fpn::size_t FractionalBits = FB;
        static constexpr fpn::size_t TotalBits = IntegralBits + FractionalBits;
        static_assert(IntegralBits > 1);
        static_assert(FractionalBits > 0);
        static_assert(IntegralBits + FractionalBits <= 64);

        using T = typename integer_bits<TotalBits>::signed_type;
        
        /**
         * Structure to hold the value and not collide with other types.
         */
        struct ValueType
        {
            T Value{};

            inline constexpr ValueType() noexcept : Value() {}
            inline constexpr ValueType(const decltype(Value) value) noexcept : Value(value) {}

            // Copy
            inline constexpr ValueType(const ValueType& other) noexcept = default;
            inline constexpr ValueType& operator=(const ValueType& other) noexcept = default;
            // Move
            inline constexpr ValueType(ValueType&& other) noexcept = default;
            inline constexpr ValueType& operator=(ValueType&& other) noexcept = default;
        };

        ValueType Value{};

        // Basic (technical) constructors
        inline constexpr fixed() noexcept : Value() {}
        inline explicit constexpr fixed(ValueType) noexcept;
        inline explicit constexpr fixed(
            typename integer_bits<IB>::signed_type     integralValue,
            typename integer_bits<FB>::unsigned_type fractionalValue
        );

        // Conversion from other fixed size
        template<fpn::size_t IB2, fpn::size_t FB2>
        inline explicit constexpr fixed(fixed<IB2, FB2>) noexcept;

        // Conversion from string
        inline explicit constexpr fixed(const std::string& value) : fixed(std::string_view(value)) {}
        inline explicit constexpr fixed(std::string_view);
        inline explicit constexpr fixed(const char* value) : fixed(std::string_view(value)) {}

        // Copy
        inline constexpr fixed(const fixed& other) noexcept = default;
        inline constexpr fixed& operator=(const fixed& other) noexcept = default;
        // Move
        inline constexpr fixed(fixed&& other) noexcept = default;
        inline constexpr fixed& operator=(fixed&& other) noexcept = default;

        [[nodiscard]] inline constexpr operator bool() const noexcept { return Value.Value != 0; }

        [[nodiscard]] inline constexpr bool operator==(const fixed other) const noexcept { return Value.Value == other.Value.Value; }
        [[nodiscard]] inline constexpr auto operator<=>(const fixed other) const noexcept { return Value.Value <=> other.Value.Value; }

        [[nodiscard]] inline constexpr fixed operator-() const noexcept { return fixed{ ValueType{ static_cast<T>(-Value.Value) } }; }

#pragma region Integral + Fractional Values
        /**
         * Raw representation of the integral part of this number.
         */
        [[nodiscard]] inline constexpr typename integer_bits<IB>::signed_type IntegralPart() const noexcept;
        /**
         * Raw representation of the fractional part of this number.
         */
        [[nodiscard]] inline constexpr typename integer_bits<FB>::unsigned_type FractionalPart() const noexcept;
        /**
         * Integral part only.
         * @warning For negative values with fractional part, the value is as if rounded away from zero ( -1.5 becomes -2 )
         */
        [[nodiscard]] inline constexpr fixed IntegralValue() const noexcept;
        /**
         * Fractional value only.
         * @warning Positive value even for negative numbers.
         */
        [[nodiscard]] inline constexpr fixed FractionalValue() const noexcept;
#pragma endregion

#pragma region Min + Max values
        [[nodiscard]] inline static constexpr fixed MinValue() noexcept;
        [[nodiscard]] inline static constexpr fixed MaxValue() noexcept;

        [[nodiscard]] inline static constexpr fixed MinIncrement() noexcept;
#pragma endregion

#pragma region Mathematical constants
        inline static constexpr fixed e           = "2.718'281'828'459'045'235'360'287'471'352'662'497'757'247'093'699'959'574'966'967'627'7"; ///< e
        inline static constexpr fixed log2e       = "1.442'695'040'888'963'407'359'924'681'001'892'137'426'645'954'152'985'934'135'449'406'9"; ///< log(2, e)
        inline static constexpr fixed log10e      = "0.434'294'481'903'251'827'651'128'918'916'605'082'294'397'005'803'666'566'114'453'783'1"; ///< log(10, e)

        inline static constexpr fixed pi          = "3.141'592'653'589'793'238'462'643'383'279'502'884'197'169'399'375'105'820'974'944'592'3"; ///< π
        inline static constexpr fixed inv_pi      = "0.318'309'886'183'790'671'537'767'526'745'028'724'068'919'291'480'912'897'495'334'688'1"; ///< 1 / π
        inline static constexpr fixed sqrtpi      = "1.772'453'850'905'516'027'298'167'483'341'145'182'797'549'456'122'387'128'213'807'789'8"; ///< sqrt(π)
        inline static constexpr fixed inv_sqrtpi  = "0.564'189'583'547'756'286'948'079'451'560'772'585'844'050'629'328'998'856'844'085'721'7"; ///< 1 / sqrt(π)
        inline static constexpr fixed tau         = "6.283'185'307'179'586'476'925'286'766'559'005'768'394'338'798'750'211'641'949'889'184'6"; ///< τ = 2 * π
        inline static constexpr fixed inv_tau     = "0.159'154'943'091'895'335'768'883'763'372'514'362'034'459'645'740'456'448'747'667'344'0"; ///< 1 / τ
        inline static constexpr fixed sqrttau     = "2.506'628'274'631'000'502'415'765'284'811'045'253'006'986'740'609'938'316'629'923'576'3"; ///< sqrt(τ)
        inline static constexpr fixed inv_sqrttau = "0.398'942'280'401'432'677'939'946'059'934'381'868'475'858'631'164'934'657'665'925'829'6"; ///< 1 / sqrt(τ)

        inline static constexpr fixed ln2         = "0.693'147'180'559'945'309'417'232'121'458'176'568'075'500'134'360'255'254'120'680'009'4"; ///< ln(2)
        inline static constexpr fixed ln10        = "2.302'585'092'994'045'684'017'991'454'684'364'207'601'101'488'628'772'976'033'327'900'9"; ///< ln(10)

        inline static constexpr fixed sqrt2       = "1.414'213'562'373'095'048'801'688'724'209'698'078'569'671'875'376'948'073'176'679'737'99"; ///< sqrt(2)
        inline static constexpr fixed inv_sqrt2   = "0.707'106'781'186'547'524'400'844'362'104'849'039'284'835'937'688'474'036'588'339'868'9";  ///< 1 / sqrt(2)

        inline static constexpr fixed sqrt3       = "1.732'050'807'568'877'293'527'446'341'505'872'366'942'805'253'810'380'628'055'806'979'4"; ///< sqrt(3)
        inline static constexpr fixed inv_sqrt3   = "1.414'213'562'373'095'048'801'688'724'209'698'078'569'671'875'376'948'073'176'679'737'9"; ///< 1 / sqrt(3)

        inline static constexpr fixed egamma      = "0.577'215'664'901'532'860'606'512'090'082'402'431'042'159'335'939'92"; ///< γ, Euler's constant, https://en.wikipedia.org/wiki/Euler%27s_constant
        inline static constexpr fixed phi         = "1.618'033'988'749'894'848'204'586'834'365'638'117'720'309'179'805'762'862'135'448'622'7"; ///< Φ, Golden ratio, https://en.wikipedia.org/wiki/Golden_ratio
#pragma endregion

#pragma region Increment/Decrement operators
        // Prefix
        [[nodiscard]] inline constexpr fixed& operator++() noexcept;
        [[nodiscard]] inline constexpr fixed& operator--() noexcept;
        // Postfix
        [[nodiscard]] inline constexpr const fixed operator++(int) noexcept;
        [[nodiscard]] inline constexpr const fixed operator--(int) noexcept;
#pragma endregion

#pragma region Integers
        inline constexpr fixed(std::integral auto) noexcept;

        template<typename TI>
            requires std::integral<TI>
        [[nodiscard]] inline constexpr explicit operator TI() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::integral auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::integral auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion

#pragma region Floating-point numbers
        inline FPN_CONSTEXPR explicit fixed(std::floating_point auto) noexcept;

        template<typename TF>
            requires std::floating_point<TF>
        [[nodiscard]] inline constexpr explicit operator TF() const noexcept;

        [[nodiscard]] inline constexpr bool operator==(const std::floating_point auto other) const noexcept { return *this == fixed(other); }
        [[nodiscard]] inline constexpr auto operator<=>(const std::floating_point auto other) const noexcept { return *this <=> fixed(other); }
#pragma endregion
    };

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, fixed<IB, FB>) noexcept;

    /**
     * Calculate 1/x
    */
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> inverse(fixed<IB, FB>) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB>& operator+=(fixed<IB, FB>&, auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB>& operator-=(fixed<IB, FB>&, auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB>& operator*=(fixed<IB, FB>&, auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    inline constexpr fixed<IB, FB>& operator/=(fixed<IB, FB>&, auto) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline std::string to_string(fixed<IB, FB>);

    template<typename CharT, fpn::size_t IB, fpn::size_t FB>
    inline std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>&, fixed<IB, FB>) noexcept;

#pragma region Other fixed-point numbers
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator+(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator-(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator*(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
    template<fpn::size_t IB1, fpn::size_t FB1, fpn::size_t IB2, fpn::size_t FB2>
    [[nodiscard]] inline constexpr auto operator/(fixed<IB1, FB1>, fixed<IB2, FB2>) noexcept;
#pragma endregion

#pragma region Integers
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(fixed<IB, FB>, std::integral auto) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(fixed<IB, FB>, std::integral auto) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator+(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator-(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator*(std::integral auto, fixed<IB, FB>) noexcept;
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator/(std::integral auto, fixed<IB, FB>) noexcept;

    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr fixed<IB, FB> operator%(fixed<IB, FB>, std::integral auto) noexcept;
#pragma endregion

#pragma region Predefined types
    // "Slow division" below means division operation uses 128-bit number or far slower algorithm for platforms without 128-bit numbers (=Windows)

    using fixed8_8  = fixed<8,  8>;
    using fixed8_16 = fixed<8, 16>;
    using fixed8_24 = fixed<8, 24>;
    using fixed8_32 = fixed<8, 32>; // Slow division
    using fixed8_40 = fixed<8, 40>; // Slow division
    using fixed8_48 = fixed<8, 48>; // Slow division
    using fixed8_56 = fixed<8, 56>; // Slow division
    
    using fixed16_8  = fixed<16,  8>;
    using fixed16_16 = fixed<16, 16>;
    using fixed16_24 = fixed<16, 24>;
    using fixed16_32 = fixed<16, 32>; // Slow division
    using fixed16_40 = fixed<16, 40>; // Slow division
    using fixed16_48 = fixed<16, 48>; // Slow division

    using fixed24_8  = fixed<24,  8>;
    using fixed24_16 = fixed<24, 16>;
    using fixed24_24 = fixed<24, 24>;
    using fixed24_32 = fixed<24, 32>; // Slow division
    using fixed24_40 = fixed<24, 40>; // Slow division

    using fixed32_8  = fixed<32,  8>;
    using fixed32_16 = fixed<32, 16>;
    using fixed32_24 = fixed<32, 24>;
    using fixed32_32 = fixed<32, 32>; // Slow division

    using fixed40_8  = fixed<40,  8>;
    using fixed40_16 = fixed<40, 16>;
    using fixed40_24 = fixed<40, 24>;

    using fixed48_8  = fixed<48,  8>;
    using fixed48_16 = fixed<48, 16>;

    using fixed56_8  = fixed<56,  8>;
#pragma endregion
}

#include "fixed.inl"
#include "fixed_string.inl"

namespace std
{
    template<fpn::size_t IB, fpn::size_t FB>
    struct hash<fpn::fixed<IB, FB>>
    {
        [[nodiscard]] std::size_t constexpr operator()(const fpn::fixed<IB, FB>& value) const noexcept
        {
            return static_cast<std::size_t>(value.Value.Value);
        }
    };
    template<fpn::size_t IB, fpn::size_t FB>
    struct numeric_limits<fpn::fixed<IB, FB>>
    {
        numeric_limits() = delete;
        using FIXED = fpn::fixed<IB, FB>;

        static constexpr bool is_specialized = true;

        static constexpr bool is_signed  = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact   = true;

        static constexpr bool               has_infinity      = false;
        static constexpr bool               has_quiet_NaN     = false;
        static constexpr bool               has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm        = denorm_absent;
        static constexpr bool               has_denorm_loss   = false;

        static constexpr float_round_style round_style = round_toward_zero;
        static constexpr bool              is_iec559   = false;
        static constexpr bool              is_bounded  = true;
        static constexpr bool              is_modulo   = false; //THINK Maybe?

        static constexpr int digits       = IB + FB - 1;
        static constexpr int digits10     = (IB - 1) * std::log10(2);
        static constexpr int max_digits10 = 0;
        static constexpr int radix        = 2;

        static constexpr int min_exponent   = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent   = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool traps           = true;
        static constexpr bool tinyness_before = false;

        static constexpr FIXED min()           noexcept { return FIXED::MinValue(); }
        static constexpr FIXED lowest()        noexcept { return min(); }
        static constexpr FIXED max()           noexcept { return FIXED::MaxValue(); }
        static constexpr FIXED epsilon()       noexcept { return {}; }
        static constexpr FIXED round_error()   noexcept { return {}; }
        static constexpr FIXED infinity()      noexcept { return {}; }
        static constexpr FIXED quiet_NaN()     noexcept { return {}; }
        static constexpr FIXED signaling_NaN() noexcept { return {}; }
        static constexpr FIXED denorm_min()    noexcept { return {}; }
    };
}
