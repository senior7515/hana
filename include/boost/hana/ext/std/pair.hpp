/*!
@file
Defines `boost::hana::ext::std::Pair`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_STD_PAIR_HPP
#define BOOST_HANA_EXT_STD_PAIR_HPP

#include <boost/hana/fwd/ext/std/pair.hpp>

#include <boost/hana/detail/std/forward.hpp>

// instances
#include <boost/hana/product.hpp>

#include <utility>


namespace boost { namespace hana {
    template <>
    struct Product::instance<ext::std::Pair> : Product::mcd {
        template <typename X, typename Y>
        static decltype(auto) make_impl(X&& x, Y&& y) {
            return ::std::make_pair(
                detail::std::forward<X>(x),
                detail::std::forward<Y>(y)
            );
        }

        template <typename P>
        static decltype(auto) first_impl(P&& p) {
            return detail::std::forward<P>(p).first;
        }

        template <typename P>
        static decltype(auto) second_impl(P&& p) {
            return detail::std::forward<P>(p).second;
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EXT_STD_PAIR_HPP
