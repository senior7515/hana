/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/tuple.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_CHECK(tuple(1, 2, 3) == tuple(1, 2, 3));
    BOOST_HANA_CONSTEXPR_CHECK(tuple(1, 2, 3) != tuple(1, 2, 3, 4));
    //! [main]
}
