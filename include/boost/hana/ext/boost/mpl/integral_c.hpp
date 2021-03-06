/*!
@file
Defines `boost::hana::ext::boost::mpl::IntegralC`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP
#define BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP

#include <boost/hana/fwd/ext/boost/mpl/integral_c.hpp>

#include <boost/hana/core/convert.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/core/when.hpp>

// instances
#include <boost/hana/constant.hpp>
#include <boost/hana/integral_constant.hpp>

#include <boost/mpl/integral_c.hpp>


namespace boost { namespace hana {
    //! `Constant` instance for Boost.MPL IntegralConstants.
    //!
    //! ### Example
    //! @include example/ext/boost/mpl/integral_c/constant.cpp
    template <typename T>
    struct Constant::instance<ext::boost::mpl::IntegralC<T>> : Constant::mcd {
        template <typename C>
        static constexpr auto value_impl(C const&)
        { return C::value; }
    };

    template <typename T>
    struct IntegralConstant::instance<ext::boost::mpl::IntegralC<T>>
        : IntegralConstant::mcd
    {
        template <T v>
        static constexpr auto integral_constant_impl()
        { return ::boost::mpl::integral_c<T, v>{}; }
    };

    template <typename T, typename C>
    struct convert<ext::boost::mpl::IntegralC<T>, C,
        when<is_an<IntegralConstant, C>()>
    > {
        template <typename X>
        static constexpr decltype(auto) apply(X x) {
            constexpr auto v = value(x);
            return ::boost::mpl::integral_c<T, v>{};
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EXT_BOOST_MPL_INTEGRAL_C_HPP
