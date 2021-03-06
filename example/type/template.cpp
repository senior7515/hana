/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/type.hpp>

#include <type_traits>
using namespace boost::hana;


//! [main]
template <typename ...> struct f;
struct x;
struct y;

BOOST_HANA_CONSTANT_CHECK(template_<f>() == type<f<>>);
BOOST_HANA_CONSTANT_CHECK(template_<f>(type<x>) == type<f<x>>);
BOOST_HANA_CONSTANT_CHECK(template_<f>(type<x>, type<y>) == type<f<x, y>>);

static_assert(std::is_same<
    decltype(template_<f>)::apply<x, y>::type,
    f<x, y>
>::value, "");
//! [main]

int main() { }
