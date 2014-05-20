/*
 * Copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/functional.hpp>

#include <boost/hana/detail/static_assert.hpp>
using namespace boost::hana;


int main() {
    BOOST_HANA_STATIC_ASSERT(always(10)() == 10);
    BOOST_HANA_STATIC_ASSERT(always(10)('a') == 10);
    BOOST_HANA_STATIC_ASSERT(always(10)('a', 'b') == 10);
    BOOST_HANA_STATIC_ASSERT(always(10)('a', 'b', 'c') == 10);
}