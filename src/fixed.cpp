#include "fixed.hpp"

namespace fpn
{
    static_assert(fixed32_16()     == 0);

    static_assert(fixed32_16(0)   == 0);
    static_assert(fixed32_16(1)   == 1);
    static_assert(fixed32_16(2)   == 2);
    static_assert(fixed32_16(-1)  == -1);
    static_assert(-fixed32_16(1)  == -1);
    static_assert(-fixed32_16(-1) == 1);

    //static_assert(fixed32_16(0u)   == 0);
    //static_assert(fixed32_16(1u)   == 1);
    //static_assert(fixed32_16(2u)   == 2);

    static_assert(fixed32_16(0.0f) == 0);
    static_assert(fixed32_16(1.0f) == 1);
    static_assert(fixed32_16(2.0f) == 2);

    static_assert(fixed32_16(0.0) == 0);
    static_assert(fixed32_16(1.0) == 1);
    static_assert(fixed32_16(2.0) == 2);

    static_assert(fixed32_16(0.1) != 0);
    static_assert(fixed32_16(1.1) != 1);
    static_assert(fixed32_16(2.1) != 2);

    static_assert(fixed32_16(0.9) != 0);
    static_assert(fixed32_16(1.9) != 1);
    static_assert(fixed32_16(2.9) != 2);

    static_assert(fixed32_16(0.9) != 1);
    static_assert(fixed32_16(1.9) != 2);
    static_assert(fixed32_16(2.9) != 3);

    static_assert(static_cast<double>(fixed32_16(0)) == 0.0);
    static_assert(static_cast<double>(fixed32_16(1)) == 1.0);
    static_assert(static_cast<double>(fixed32_16(2)) == 2.0);

    static_assert(static_cast<double>(fixed32_16(0.0)) == 0.0);
    static_assert(static_cast<double>(fixed32_16(1.0)) == 1.0);
    static_assert(static_cast<double>(fixed32_16(2.0)) == 2.0);

    static_assert(static_cast<double>(fixed32_16(0.5)) == 0.5);
    static_assert(static_cast<double>(fixed32_16(1.5)) == 1.5);
    static_assert(static_cast<double>(fixed32_16(2.5)) == 2.5);

    static_assert(static_cast<double>(fixed32_16(0.25)) == 0.25);
    static_assert(static_cast<double>(fixed32_16(1.25)) == 1.25);
    static_assert(static_cast<double>(fixed32_16(2.25)) == 2.25);

    static_assert(static_cast<double>(fixed32_16(0.125)) == 0.125);
    static_assert(static_cast<double>(fixed32_16(1.125)) == 1.125);
    static_assert(static_cast<double>(fixed32_16(2.125)) == 2.125);

    static_assert(static_cast<double>(fixed32_16(0.0625)) == 0.0625);
    static_assert(static_cast<double>(fixed32_16(1.0625)) == 1.0625);
    static_assert(static_cast<double>(fixed32_16(2.0625)) == 2.0625);

#if FPN_CONSTEXPR_HAS == 1
    static_assert(static_cast<double>(fixed32_16(0.1)) == 0.100'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(1.1)) == 1.100'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(2.1)) == 2.100'006'103'515'625);

    static_assert(static_cast<double>(fixed32_16(0.2)) == 0.199'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(1.2)) == 1.199'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(2.2)) == 2.199'996'948'242'187'5);

    static_assert(static_cast<double>(fixed32_16(0.3)) == 0.300'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(1.3)) == 1.300'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(2.3)) == 2.300'003'051'757'812'5);

    static_assert(static_cast<double>(fixed32_16(0.4)) == 0.399'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(1.4)) == 1.399'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(2.4)) == 2.399'993'896'484'375);
#endif

    static_assert(static_cast<double>(fixed32_16(0.5)) == 0.5);
    static_assert(static_cast<double>(fixed32_16(1.5)) == 1.5);
    static_assert(static_cast<double>(fixed32_16(2.5)) == 2.5);

#if FPN_CONSTEXPR_HAS == 1
    static_assert(static_cast<double>(fixed32_16(0.6)) == 0.600'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(1.6)) == 1.600'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(2.6)) == 2.600'006'103'515'625);

    static_assert(static_cast<double>(fixed32_16(0.7)) == 0.699'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(1.7)) == 1.699'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(2.7)) == 2.699'996'948'242'187'5);

    static_assert(static_cast<double>(fixed32_16(0.8)) == 0.800'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(1.8)) == 1.800'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(2.8)) == 2.800'003'051'757'812'5);

    static_assert(static_cast<double>(fixed32_16(0.9)) == 0.899'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(1.9)) == 1.899'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(2.9)) == 2.899'993'896'484'375);
#endif

    static_assert(static_cast<double>(fixed32_16(-0.0)) == -0.0);
    static_assert(static_cast<double>(fixed32_16(-1.0)) == -1.0);
    static_assert(static_cast<double>(fixed32_16(-2.0)) == -2.0);

    static_assert(static_cast<double>(fixed32_16(-0.5)) == -0.5);
    static_assert(static_cast<double>(fixed32_16(-1.5)) == -1.5);
    static_assert(static_cast<double>(fixed32_16(-2.5)) == -2.5);

    static_assert(static_cast<double>(fixed32_16(-0.25)) == -0.25);
    static_assert(static_cast<double>(fixed32_16(-1.25)) == -1.25);
    static_assert(static_cast<double>(fixed32_16(-2.25)) == -2.25);

    static_assert(static_cast<double>(fixed32_16(-0.125)) == -0.125);
    static_assert(static_cast<double>(fixed32_16(-1.125)) == -1.125);
    static_assert(static_cast<double>(fixed32_16(-2.125)) == -2.125);

    static_assert(static_cast<double>(fixed32_16(-0.0625)) == -0.0625);
    static_assert(static_cast<double>(fixed32_16(-1.0625)) == -1.0625);
    static_assert(static_cast<double>(fixed32_16(-2.0625)) == -2.0625);

#if FPN_CONSTEXPR_HAS == 1
    static_assert(static_cast<double>(fixed32_16(-0.1)) == -0.100'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(-1.1)) == -1.100'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(-2.1)) == -2.100'006'103'515'625);

    static_assert(static_cast<double>(fixed32_16(-0.2)) == -0.199'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(-1.2)) == -1.199'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(-2.2)) == -2.199'996'948'242'187'5);

    static_assert(static_cast<double>(fixed32_16(-0.3)) == -0.300'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(-1.3)) == -1.300'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(-2.3)) == -2.300'003'051'757'812'5);

    static_assert(static_cast<double>(fixed32_16(-0.4)) == -0.399'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(-1.4)) == -1.399'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(-2.4)) == -2.399'993'896'484'375);
#endif

    static_assert(static_cast<int32_t>(fixed32_16(-0.5)) == -1);
    static_assert(static_cast<int32_t>(fixed32_16(-1.5)) == -2);
    static_assert(static_cast<int32_t>(fixed32_16(-2.5)) == -3);

    static_assert(static_cast<double>(fixed32_16(-0.5)) == -0.5);
    static_assert(static_cast<double>(fixed32_16(-1.5)) == -1.5);
    static_assert(static_cast<double>(fixed32_16(-2.5)) == -2.5);

#if FPN_CONSTEXPR_HAS == 1
    static_assert(static_cast<double>(fixed32_16(-0.6)) == -0.600'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(-1.6)) == -1.600'006'103'515'625);
    static_assert(static_cast<double>(fixed32_16(-2.6)) == -2.600'006'103'515'625);

    static_assert(static_cast<double>(fixed32_16(-0.7)) == -0.699'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(-1.7)) == -1.699'996'948'242'187'5);
    static_assert(static_cast<double>(fixed32_16(-2.7)) == -2.699'996'948'242'187'5);

    static_assert(static_cast<double>(fixed32_16(-0.8)) == -0.800'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(-1.8)) == -1.800'003'051'757'812'5);
    static_assert(static_cast<double>(fixed32_16(-2.8)) == -2.800'003'051'757'812'5);

    static_assert(static_cast<double>(fixed32_16(-0.9)) == -0.899'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(-1.9)) == -1.899'993'896'484'375);
    static_assert(static_cast<double>(fixed32_16(-2.9)) == -2.899'993'896'484'375);
#endif

    static_assert(fixed32_16(-1.0f) == -1);
    static_assert(-fixed32_16(1.0f) == -1);
    static_assert(-fixed32_16(-1.0f) == 1);

    static_assert(fixed32_16(-1.0)  == -1);
    static_assert(-fixed32_16(1.0)  == -1);
    static_assert(-fixed32_16(-1.0)  == 1);
}
