/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>

#include "matrix/comparable.hpp"
using namespace boost::hana;
using namespace cppcon;


int main() {
    BOOST_HANA_CONSTEXPR_CHECK(equal(
        matrix(row(1, 2)),
        matrix(row(1, 2))
    ));
    BOOST_HANA_CONSTEXPR_CHECK(not_(equal(
        matrix(row(1, 2)),
        matrix(row(1, 5))
    )));

    BOOST_HANA_CONSTEXPR_CHECK(equal(
        matrix(row(1, 2),
               row(3, 4)),
        matrix(row(1, 2),
               row(3, 4))
    ));
    BOOST_HANA_CONSTEXPR_CHECK(not_(equal(
        matrix(row(1, 2),
               row(3, 4)),
        matrix(row(1, 2),
               row(0, 4))
    )));
    BOOST_HANA_CONSTEXPR_CHECK(not_(equal(
        matrix(row(1, 2),
               row(3, 4)),
        matrix(row(0, 2),
               row(3, 4))
    )));

    BOOST_HANA_CONSTANT_CHECK(not_(equal(
        matrix(row(1),
               row(2)),
        matrix(row(3, 4),
               row(5, 6))
    )));
    BOOST_HANA_CONSTANT_CHECK(not_(equal(
        matrix(row(1),
               row(2)),
        matrix(row(3, 4))
    )));
}

