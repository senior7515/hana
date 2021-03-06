/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/type.hpp>
using namespace boost::hana;


//! [main]
struct X { };
BOOST_HANA_CONSTANT_CHECK(type<X> == decltype_(X{}));
BOOST_HANA_CONSTANT_CHECK(type<int> == decltype_(1));
//! [main]

int main() { }
