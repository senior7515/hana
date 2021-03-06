/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_TEST_TEST_AUTO_PRODUCT_HPP
#define BOOST_HANA_TEST_TEST_AUTO_PRODUCT_HPP

#include <boost/hana/product.hpp>

#include <boost/hana/assert.hpp>

#include <test/auto/base.hpp>
#include <test/injection.hpp>

// provided instances
#include <test/auto/comparable.hpp>
#include <test/auto/foldable.hpp>


namespace boost { namespace hana { namespace test {
    template <typename P>
    auto laws<Product, P> = [] {
        auto prod = make<P>;
        using test::x;

        // Product
        {
            // first
            {
                BOOST_HANA_CONSTANT_CHECK(equal(
                    first(prod(x<0>, x<1>)), x<0>
                ));
            }

            // second
            {
                BOOST_HANA_CONSTANT_CHECK(equal(
                    second(prod(x<0>, x<1>)), x<1>
                ));
            }

            // make
            {
                BOOST_HANA_CONSTANT_CHECK(equal(
                    prod(x<0>, x<1>),
                    make<P>(x<0>, x<1>)
                ));
            }
        }

        // Comparable
        {
            laws<Comparable, P>();

            // equal
            {
                BOOST_HANA_CONSTANT_CHECK(equal(
                    prod(x<0>, x<1>), prod(x<0>, x<1>)
                ));
                BOOST_HANA_CONSTANT_CHECK(not_(equal(
                    prod(x<0>, x<1>), prod(x<9>, x<1>)
                )));
                BOOST_HANA_CONSTANT_CHECK(not_(equal(
                    prod(x<0>, x<1>), prod(x<0>, x<9>)
                )));
                BOOST_HANA_CONSTANT_CHECK(not_(equal(
                    prod(x<0>, x<1>), prod(x<9>, x<9>)
                )));
            }
        }

        // Foldable
        {
            laws<Foldable, P>();
            auto f = test::injection([]{});

            // unpack
            {
                BOOST_HANA_CONSTANT_CHECK(equal(
                    unpack(prod(x<0>, x<1>), f),
                    f(x<0>, x<1>)
                ));
            }
        }
    };
}}} // end namespace boost::hana::test

#endif // !BOOST_HANA_TEST_TEST_AUTO_PRODUCT_HPP
