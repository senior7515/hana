/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/functional.hpp>
#include <boost/hana/maybe.hpp>
#include <boost/hana/tuple.hpp>
using namespace boost::hana;


int main() {
    //! [ap]
    BOOST_HANA_CONSTEXPR_LAMBDA auto f = _ + _;
    BOOST_HANA_CONSTEXPR_CHECK(
        ap(lift<Tuple>(f), tuple(1, 2), tuple(3, 4, 5))
            ==
        tuple(
            f(1, 3), f(1, 4), f(1, 5),
            f(2, 3), f(2, 4), f(2, 5)
        )
    );

    BOOST_HANA_CONSTEXPR_LAMBDA auto g = [](auto a, auto b, auto c) {
        return a * b * c;
    };
    BOOST_HANA_CONSTEXPR_CHECK(
        ap(lift<Maybe>(g), just(1), just(2), just(3)) == just(1 * 2 * 3)
    );
    BOOST_HANA_CONSTANT_CHECK(
        ap(lift<Maybe>(g), just(1), nothing, just(3)) == nothing
    );
    //! [ap]

    //! [lift]
    BOOST_HANA_CONSTEXPR_CHECK(lift<Tuple>('x') == tuple('x'));
    BOOST_HANA_CONSTEXPR_CHECK(lift<Maybe>('x') == just('x'));
    //! [lift]
}
