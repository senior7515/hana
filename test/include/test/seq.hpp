/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_TEST_TEST_SEQ_HPP
#define BOOST_HANA_TEST_TEST_SEQ_HPP

#include <boost/hana/bool.hpp>
#include <boost/hana/detail/constexpr.hpp>

// instances
#include <boost/hana/foldable.hpp>
#include <boost/hana/iterable.hpp>
#include <boost/hana/list.hpp>


namespace boost { namespace hana {
    namespace test {
        struct Seq;

        template <typename Storage>
        struct seq_type : operators::Iterable_ops<seq_type<Storage>> {
            explicit constexpr seq_type(Storage s) : storage(s) { }
            Storage storage;
            struct hana { using datatype = Seq; };
        };

        BOOST_HANA_CONSTEXPR_LAMBDA auto seq = [](auto ...xs) {
            auto storage = [=](auto f) { return f(xs...); };
            return seq_type<decltype(storage)>(storage);
        };
    }

    // Define either one to select which MCD is used:
    //  BOOST_HANA_TEST_FOLDABLE_FOLDS_MCD
    //  BOOST_HANA_TEST_FOLDABLE_UNPACK_MCD
    //  BOOST_HANA_TEST_FOLDABLE_ITERABLE_MCD
    //
    // If neither is defined, the MCD used is unspecified.
#ifdef BOOST_HANA_TEST_FOLDABLE_FOLDS_MCD
    template <>
    struct Foldable::instance<test::Seq>
        : Foldable::folds_mcd
    {
        template <typename F, typename S, typename X, typename ...Xs>
        static constexpr auto foldr_helper(F f, S s, X x, Xs ...xs)
        { return f(x, foldr_helper(f, s, xs...)); }

        template <typename F, typename S>
        static constexpr auto foldr_helper(F f, S s)
        { return s; }

        template <typename Xs, typename S, typename F>
        static constexpr auto foldr_impl(Xs xs, S s, F f) {
            return xs.storage([=](auto ...xs) {
                return foldr_helper(f, s, xs...);
            });
        }

        template <typename F, typename S, typename X, typename ...Xs>
        static constexpr auto foldl_helper(F f, S s, X x, Xs ...xs)
        { return foldl_helper(f, f(s, x), xs...); }

        template <typename F, typename S>
        static constexpr auto foldl_helper(F f, S s)
        { return s; }

        template <typename Xs, typename S, typename F>
        static constexpr auto foldl_impl(Xs xs, S s, F f) {
            return xs.storage([=](auto ...xs) {
                return foldl_helper(f, s, xs...);
            });
        }
    };
#elif defined(BOOST_HANA_TEST_FOLDABLE_UNPACK_MCD)
    template <>
    struct Foldable::instance<test::Seq>
        : Foldable::unpack_mcd
    {
        template <typename Xs, typename F>
        static constexpr auto unpack_impl(Xs xs, F f)
        { return xs.storage(f); }
    };
#else
    // Defined implicitly by Iterable
#endif

    template <>
    struct Iterable::instance<test::Seq> : Iterable::mcd {
        template <typename Xs>
        static constexpr auto head_impl(Xs xs) {
            return xs.storage([=](auto x, auto ...xs) {
                return x;
            });
        }

        template <typename Xs>
        static constexpr auto tail_impl(Xs xs) {
            return xs.storage([=](auto x, auto ...xs) {
                return test::seq(xs...);
            });
        }

        template <typename Xs>
        static constexpr auto is_empty_impl(Xs xs) {
            return xs.storage([=](auto ...xs) {
                return bool_<sizeof...(xs) == 0>;
            });
        }
    };

    template <>
    struct List::instance<test::Seq> : List::mcd<test::Seq> {
        template <typename X, typename Xs>
        static constexpr auto cons_impl(X x, Xs xs) {
            return xs.storage([=](auto ...xs) {
                return test::seq(x, xs...);
            });
        }

        static BOOST_HANA_CONSTEXPR_LAMBDA auto nil_impl() {
            return test::seq();
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_TEST_TEST_SEQ_HPP
