/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/bool.hpp>

#include <iostream>
using namespace boost::hana;


namespace pure {
//! [pure]
template <typename X>
auto identity(X x) { return x; }

auto x = identity(bool_<true>);
static_assert(value(x), "");
//! [pure]
}

namespace impure {
//! [impure]
//! [impure_identity]
template <typename X>
auto identity(X x) {
    std::cout << "Good luck in evaluating this at compile-time!";
    return x;
}
//! [impure_identity]

auto x = identity(bool_<true>);
static_assert(value(x), "");
//! [impure]
}

int main() { }
