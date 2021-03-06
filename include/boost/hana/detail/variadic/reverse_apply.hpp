/*!
@file
Defines `boost::hana::detail::variadic::reverse_apply`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_DETAIL_VARIADIC_REVERSE_APPLY_HPP
#define BOOST_HANA_DETAIL_VARIADIC_REVERSE_APPLY_HPP

#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/detail/variadic/reverse_apply/unrolled.hpp>


namespace boost { namespace hana { namespace detail { namespace variadic {
    BOOST_HANA_CONSTEXPR_LAMBDA auto reverse_apply =
        [](auto&& f, auto&& ...x) -> decltype(auto) {
            return detail::variadic::reverse_apply_unrolled(
                detail::std::forward<decltype(f)>(f),
                detail::std::forward<decltype(x)>(x)...
            );
        };
}}}} // end namespace boost::hana::detail::variadic

#endif // !BOOST_HANA_DETAIL_VARIADIC_REVERSE_APPLY_HPP
