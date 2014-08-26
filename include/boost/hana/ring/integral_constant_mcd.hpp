/*!
@file
Defines `boost::hana::Ring::integral_constant_mcd`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_RING_INTEGRAL_CONSTANT_MCD_HPP
#define BOOST_HANA_RING_INTEGRAL_CONSTANT_MCD_HPP

#include <boost/hana/constant/constant.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/std/is_integral.hpp>
#include <boost/hana/integral_constant/integral_constant.hpp>
#include <boost/hana/ring/mcd.hpp>


namespace boost { namespace hana {
    //! Any two `IntegralConstant`s form a multiplicative `Ring`.
    template <typename I1, typename I2>
    struct Ring::integral_constant_mcd : Ring::mcd {
        template <typename X, typename Y>
        static constexpr auto mult_impl(X x, Y y) {
            constexpr auto prod = value(x) * value(y);
            return integral_constant<I1, decltype(prod), prod>;
        }

        static BOOST_HANA_CONSTEXPR_LAMBDA auto one_impl()
        { return integral_constant<I1, int, 1>; }
    };

    template <typename I, typename T>
    struct Ring::instance<I, T, when<
        is_an<IntegralConstant, I>() &&
        detail::std::is_integral<T>{}
    >>
        : Ring::mcd
    {
        template <typename X, typename Y>
        static constexpr auto mult_impl(X x, Y y)
        { return value(x) * y; }
    };

    template <typename T, typename I>
    struct Ring::instance<T, I, when<
        detail::std::is_integral<T>{} &&
        is_an<IntegralConstant, I>()
    >>
        : Ring::mcd
    {
        template <typename X, typename Y>
        static constexpr auto mult_impl(X x, Y y)
        { return x * value(y); }
    };

    template <typename I1, typename I2>
    struct Ring::instance<I1, I2, when<
        is_an<IntegralConstant, I1>() &&
        is_an<IntegralConstant, I2>()
    >>
        : Ring::integral_constant_mcd<I1, I2>
    { };
}} // end namespace boost::hana

#endif // !BOOST_HANA_RING_INTEGRAL_CONSTANT_MCD_HPP