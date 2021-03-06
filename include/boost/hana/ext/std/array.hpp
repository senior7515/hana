/*!
@file
Defines `boost::hana::ext::std::Array`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_EXT_STD_ARRAY_HPP
#define BOOST_HANA_EXT_STD_ARRAY_HPP

#include <boost/hana/fwd/ext/std/array.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/detail/std/integer_sequence.hpp>
#include <boost/hana/detail/std/move.hpp>
#include <boost/hana/detail/std/remove_reference.hpp>
#include <boost/hana/detail/std/size_t.hpp>

// instances
#include <boost/hana/iterable.hpp>
#include <boost/hana/list.hpp>

#include <array>


namespace boost { namespace hana {
    template <>
    struct Iterable::instance<ext::std::Array> : Iterable::mcd {
        template <typename Xs>
        static constexpr decltype(auto) head_impl(Xs&& xs)
        { return detail::std::forward<Xs>(xs)[0]; }

        template <typename T, detail::std::size_t N, typename Xs, detail::std::size_t ...index>
        static constexpr auto tail_helper(Xs&& xs, detail::std::index_sequence<index...>) {
            return ::std::array<T, N - 1>{{
                detail::std::forward<Xs>(xs)[index + 1]...
            }};
        }

        template <typename Xs>
        static constexpr decltype(auto) tail_impl(Xs&& xs) {
            using RawArray = typename detail::std::remove_reference<Xs>::type;
            constexpr auto N = ::std::tuple_size<RawArray>::value;
            using T = typename RawArray::value_type;
            return tail_helper<T, N>(
                detail::std::forward<Xs>(xs),
                detail::std::make_index_sequence<N - 1>{}
            );
        }

        template <typename T, detail::std::size_t N>
        static constexpr auto is_empty_impl(::std::array<T, N> const&)
        { return bool_<N == 0>; }
    };

    template <>
    struct List::instance<ext::std::Array> : List::mcd<ext::std::Array> {
        struct anything { };

        static constexpr auto nil_impl()
        { return ::std::array<anything, 0>{}; }

        template <typename T, detail::std::size_t N, typename X, typename Xs, detail::std::size_t ...index>
        static constexpr auto
        cons_helper(X&& x, Xs&& xs, detail::std::index_sequence<index...>) {
            return ::std::array<T, N + 1>{{
                detail::std::forward<X>(x),
                detail::std::forward<Xs>(xs)[index]...
            }};
        }

        template <typename X, typename Xs>
        static constexpr decltype(auto) cons_impl(X&& x, Xs&& xs) {
            using RawArray = typename detail::std::remove_reference<Xs>::type;
            constexpr auto N = ::std::tuple_size<RawArray>::value;
            using T = typename RawArray::value_type;
            return cons_helper<T, N>(
                detail::std::forward<X>(x),
                detail::std::forward<Xs>(xs),
                detail::std::make_index_sequence<N>{}
            );
        }

        template <typename X>
        static constexpr auto cons_impl(X x, ::std::array<anything, 0>)
        { return ::std::array<X, 1>{{detail::std::move(x)}}; }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_EXT_STD_ARRAY_HPP
