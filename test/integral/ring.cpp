/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/integral/comparable.hpp>
#include <boost/hana/integral/ring.hpp>

#include <test/iso/integral_constant/ring.hpp>
using namespace boost::hana;


int main() {
    IntegralConstant_ring<Integral, int, short>();
    IntegralConstant_ring<Integral, int, int>();
    IntegralConstant_ring<Integral, int, long>();
}