/*
 * Copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/list.hpp>

#include <functional>
using namespace boost::hana;


int main() {
    // Elementwise product
    BOOST_HANA_STATIC_ASSERT(
        zip_with(std::multiplies<>{}, list(1, 2, 3, 4), list(5, 6, 7, 8))
        ==
        list(5, 12, 21, 32)
    );
}