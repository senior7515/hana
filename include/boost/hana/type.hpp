/*!
@file
Defines the `boost::hana::Type` data type.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_TYPE_HPP
#define BOOST_HANA_TYPE_HPP

#include <boost/hana/fwd/type.hpp>

#include <boost/hana/bool.hpp>
#include <boost/hana/integral.hpp>

// instances
#include <boost/hana/comparable.hpp>


namespace boost { namespace hana {
    //! Instance of `Comparable` for `Type`s.
    //!
    //! Two `Type`s are equal if and only if they represent the same C++ type.
    //! Hence, equality is equivalent to the `std::is_same` type trait.
    //!
    //! @snippet example/type/comparable.cpp main
    template <>
    struct Comparable::instance<Type, Type> : Comparable::equal_mcd {
        template <typename T, typename U>
        static constexpr auto equal_impl(T, U)
        { return false_; }

        template <typename T>
        static constexpr auto equal_impl(T, T)
        { return true_; }
    };

#ifndef BOOST_HANA_DOXYGEN_INVOKED
    template <typename T>
    constexpr auto _sizeof::operator()(T) const
    { return size_t<sizeof(typename T::type)>; }
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_TYPE_HPP
