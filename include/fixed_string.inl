#pragma once
#include "fixed.hpp"

namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    [[nodiscard]] inline constexpr static typename fixed<IB, FB>::T ParseString(const std::string_view in)
    {
        using T = typename fixed<IB, FB>::T;
        T value = {};

        auto it = in.begin();

        // Before decimal point
        for(; it != in.end() && *it != '.'; it++)
        {
            switch(*it)
            {
                case '\'':
                case ' ':
                case '_':
                    continue;
                case '.':
                    break;
                case '\0':
                    return value << FB;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    value *= 10;
                    value += static_cast<T>(*it - '0');
                    continue;
                default: [[unlikely]]
                    throw std::runtime_error("Failed to recognize a character to parse into fixed-point number");
            }
        }
        value = value << FB;

        if(it != in.end() && *it == '.')
        {
            // Skip decimal point
            it++;

            // After decimal point
            for(std::size_t digitIndex = 0, divider = 10; it != in.end() && digitIndex < FB; it++)
            {
                switch(*it)
                {
                    case '\'':
                    case ' ':
                    case '_':
                        continue;
                    case '\0':
                        return value;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        value += (static_cast<T>(*it - '0') << FB) / divider;
                        digitIndex++;
                        divider *= 10;
                        continue;
                    default:
                        throw std::runtime_error("Failed to recognize a character to parse into fixed-point number");
                }
            }
        }

        return value;
    }

    template<fpn::size_t IB, fpn::size_t FB>
    constexpr fixed<IB, FB>::fixed(const std::string_view in)
      : Value(ParseString<IB, FB>(in))
    {
    }
}
// to_string
namespace fpn
{
    template<fpn::size_t IB, fpn::size_t FB>
    inline std::string to_string(const fixed<IB, FB> value)
    {
        return std::to_string(static_cast<double>(value)); //TODO
    }
    template<typename CharT, fpn::size_t IB, fpn::size_t FB>
    std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& out, const fixed<IB, FB> value) noexcept
    {
        if constexpr(std::is_same_v<CharT, char>)
            return out << std::to_string(static_cast<double>(value));
        else
            return out << static_cast<double>(value);
    }
}
