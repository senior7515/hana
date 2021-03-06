/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/functional.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    // arg<0>(1, '2', 3.3); // static assertion (regardless of the number of arguments)
    BOOST_HANA_CONSTEXPR_CHECK(arg<1>(1, '2', 3.3) == 1);
    BOOST_HANA_CONSTEXPR_CHECK(arg<2>(1, '2', 3.3) == '2');
    BOOST_HANA_CONSTEXPR_CHECK(arg<3>(1, '2', 3.3) == 3.3);
    // arg<4>(1, '2', 3.3); // static assertion
    //! [main]
}
