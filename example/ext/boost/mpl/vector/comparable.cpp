/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/ext/boost/mpl/vector.hpp>

#include <boost/mpl/vector.hpp>
using namespace boost::hana;
namespace mpl = boost::mpl;


BOOST_HANA_CONSTANT_CHECK(equal(mpl::vector2<int, char>{}, mpl::vector<int, char>{}));
BOOST_HANA_CONSTANT_CHECK(not_equal(mpl::vector2<int, char>{}, mpl::vector<int, char, float>{}));

int main() { }
