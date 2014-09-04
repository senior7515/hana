/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/bool/logical.hpp>
#include <boost/hana/foldable/foldable.hpp>

#include <boost/hana/benchmark/measure.hpp>

<%= setup %>


int main() {
    auto foldable = <%= foldable %>;
    auto pred = [](auto&& x, auto&& y) { return boost::hana::true_; };

    boost::hana::benchmark::measure([=] {
        boost::hana::maximum_by(pred, foldable);
    });
}