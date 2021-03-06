/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/type.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    struct X { };
    BOOST_HANA_CONSTEXPR_CHECK(sizeof_(type<X>) == sizeof(X));
    BOOST_HANA_CONSTEXPR_CHECK(sizeof_(type<int>) == sizeof(int));
    //! [main]
}
