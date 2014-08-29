/*!
@file
Defines `boost::hana::Functor::fmap_mcd`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FUNCTOR_FMAP_MCD_HPP
#define BOOST_HANA_FUNCTOR_FMAP_MCD_HPP

#include <boost/hana/functor/functor.hpp>

#include <boost/hana/logical/logical.hpp>


namespace boost { namespace hana {
    //! Minimal complete definition: `fmap`
    struct Functor::fmap_mcd : functor_detail::common {
        template <typename Xs, typename Pred, typename F>
        static constexpr auto adjust_impl(Xs xs, Pred pred, F f) {
            auto go = [=](auto x) {
                return eval_if(pred(x),
                    [=](auto _) { return _(f)(x); },
                    [=](auto) { return x; }
                );
            };
            return fmap(xs, go);
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_FUNCTOR_FMAP_MCD_HPP
