/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/type.hpp>
#include <boost/hana/type_list.hpp>

#include <type_traits>
using namespace boost::hana;


int main() {
    //! [fmap]
    BOOST_HANA_CONSTEXPR_LAMBDA auto types = type_list<void, int(), char[10]>;
    BOOST_HANA_CONSTEXPR_LAMBDA auto pointers = fmap(types, template_<std::add_pointer_t>);
    BOOST_HANA_CONSTANT_CHECK(pointers == type_list<void*, int(*)(), char(*)[10]>);
    BOOST_HANA_CONSTANT_CHECK(head(pointers) == type<void*>);
    //! [fmap]
}
