/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/maybe.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto x) {
        return x + 1; // next letter
    };

    BOOST_HANA_CONSTEXPR_CHECK(ap(just(f), just('x')) == just(f('x')));
    BOOST_HANA_CONSTANT_CHECK(ap(nothing, just('x')) == nothing);
    BOOST_HANA_CONSTANT_CHECK(ap(just(f), nothing) == nothing);
    BOOST_HANA_CONSTANT_CHECK(ap(nothing, nothing) == nothing);
    //! [main]
}
