/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/foreign.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/maybe.hpp>
#include <boost/hana/tuple.hpp>

#include <string>
using namespace boost::hana;
using namespace std::string_literals;


int main() {
    //! [sequence]
    BOOST_HANA_RUNTIME_ASSERT(
        sequence<Tuple>(
            tuple(tuple("a1"s, "a2"s), tuple("b1"s), tuple("c1", "c2", "c3"))
        )
        ==
        tuple(
            tuple("a1"s, "b1"s, "c1"s),
            tuple("a1"s, "b1"s, "c2"s),
            tuple("a1"s, "b1"s, "c3"s),

            tuple("a2"s, "b1"s, "c1"s),
            tuple("a2"s, "b1"s, "c2"s),
            tuple("a2"s, "b1"s, "c3"s)
        )
    );
    //! [sequence]

    {
        //! [traverse]
        BOOST_HANA_CONSTEXPR_LAMBDA auto half = [](auto x) {
            return if_(x % int_<2> == int_<0>,
                just(x / int_<2>),
                nothing
            );
        };

        BOOST_HANA_CONSTANT_ASSERT(
            traverse<Maybe>(tuple(int_<2>, int_<4>, int_<6>), half)
            ==
            just(tuple(int_<1>, int_<2>, int_<3>))
        );

        BOOST_HANA_CONSTANT_ASSERT(
            traverse<Maybe>(tuple(int_<2>, int_<3>, int_<6>), half)
            ==
            nothing
        );
        //! [traverse]
    }
}
