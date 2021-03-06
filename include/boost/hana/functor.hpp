/*!
@file
Defines `boost::hana::Functor`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FUNCTOR_HPP
#define BOOST_HANA_FUNCTOR_HPP

#include <boost/hana/fwd/functor.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/functional/always.hpp>
#include <boost/hana/logical.hpp>


namespace boost { namespace hana {
    namespace functor_detail {
        struct common {
            template <typename F, typename Pred, typename Value>
            static constexpr decltype(auto) replace_impl(F&& functor, Pred&& pred, Value&& v) {
                return adjust(
                    detail::std::forward<F>(functor),
                    detail::std::forward<Pred>(pred),
                    always(detail::std::forward<Value>(v))
                );
            }

            template <typename F, typename Value>
            static constexpr decltype(auto) fill_impl(F&& functor, Value&& v) {
                return fmap(
                    detail::std::forward<F>(functor),
                    always(detail::std::forward<Value>(v))
                );
            }
        };
    }

    //! Minimal complete definition: `fmap`
    struct Functor::fmap_mcd : functor_detail::common {
        template <typename Xs, typename Pred, typename F>
        static constexpr auto adjust_impl(Xs xs, Pred pred, F f) {
            auto go = [=](auto x) {
                return eval_if(pred(x),
                    [=](auto _) -> decltype(auto) { return _(f)(x); },
                    always(x)
                );
            };
            return fmap(xs, go);
        }
    };

    //! Minimal complete definition: `adjust`
    struct Functor::adjust_mcd : functor_detail::common {
        template <typename Xs, typename F>
        static constexpr decltype(auto) fmap_impl(Xs&& xs, F&& f) {
            return adjust(
                detail::std::forward<Xs>(xs),
                always(true_),
                detail::std::forward<F>(f)
            );
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_FUNCTOR_HPP
