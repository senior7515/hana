/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/fwd/list.hpp>
#include <boost/hana/integral.hpp>

#include "benchmark.hpp"

<%= setup %>


int main() {
    using L = <%= datatype %>;
    auto list = boost::hana::make<L>(
        <%= (1..input_size).to_a.map { |i| "boost::hana::int_<#{i}>" }.join(', ') %>
    );

    boost::hana::benchmark::measure([=] {
        boost::hana::sort(list);
    });
}
