/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/variadic/drop_into.hpp>

#include <boost/hana/assert.hpp>

#include <test/injection.hpp>
using namespace boost::hana;
namespace vd = detail::variadic;


struct non_pod { virtual ~non_pod() { } };

using test::x;

int main() {
    auto f = test::injection([]{});

    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<0>(f)(),
        f()
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<0>(f)(x<0>),
        f(x<0>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<0>(f)(x<0>, x<1>),
        f(x<0>, x<1>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<0>(f)(x<0>, x<1>, x<2>),
        f(x<0>, x<1>, x<2>)
    ));


    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<1>(f)(x<0>),
        f()
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<1>(f)(x<0>, x<1>),
        f(x<1>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<1>(f)(x<0>, x<1>, x<2>),
        f(x<1>, x<2>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<1>(f)(x<0>, x<1>, x<2>, x<3>),
        f(x<1>, x<2>, x<3>)
    ));


    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<2>(f)(x<0>, x<1>),
        f()
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<2>(f)(x<0>, x<1>, x<2>),
        f(x<2>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<2>(f)(x<0>, x<1>, x<2>, x<3>),
        f(x<2>, x<3>)
    ));
    BOOST_HANA_CONSTANT_CHECK(equal(
        vd::drop_into<2>(f)(x<0>, x<1>, x<2>, x<3>, x<4>),
        f(x<2>, x<3>, x<4>)
    ));

    // make sure we can use non-pods
    vd::drop_into<1>(f)(x<0>, non_pod{});
    vd::drop_into<1>(f)(non_pod{}, x<1>);
}
