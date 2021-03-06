/*!
@file
Defines `boost::hana::common` and `boost::hana::common_t`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CORE_COMMON_HPP
#define BOOST_HANA_CORE_COMMON_HPP

#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/std/decay.hpp>
#include <boost/hana/detail/std/declval.hpp>


namespace boost { namespace hana {
    //! @ingroup group-core
    //! Metafunction returning the common data type between two data types.
    //!
    //! We say that two data types `T` and `U` have a common data type `C`
    //! if both objects of data type `T` and objects of data type `U` may be
    //! converted to an object of data type `C`, and if that conversion is
    //! equality preserving. In other words, this means that for any objects
    //! `t1, t2` of data type `T` and `u1, u2` of data type `U`, the following
    //! law is satisfied:
    //! @code
    //!     to<C>(t1) == to<C>(t2) if and only if t1 == t2
    //!     to<C>(u1) == to<C>(u2) if and only if u1 == u2
    //! @endcode
    //!
    //! The role of this metafunction is to provide an alias to the common
    //! type of two given data types. In other words, if `T` and `U` have a
    //! common data type `C`, `common<T, U>::type` is an alias to `C`.
    //! Otherwise, `common<T, U>` has no nested `type` and can be used
    //! in dependent contexts to trigger SFINAE.
    //!
    //! In order for `common` to work properly, it must be specified for
    //! pairs of custom data types by specializing the metafunction in the
    //! `boost::hana` namespace. Flexible specialization with `when` is
    //! supported. A default behavior for types sharing a common type in
    //! the `std::common_type` sense is provided. For those types,
    //! `common<T, U>` is equivalent to `std::decay` of the result type
    //! of the ternary operator:
    //! @code
    //!     std::decay<
    //!         decltype(true ? std::declval<T>() : std::declval<U>())
    //!     >::type
    //! @endcode
    //!
    //! Also note that `common<T, T>::type` is always an alias to `T`, so
    //! `common` does not have to be specialized for the trivial case.
    //!
    //!
    //! ### Example
    //! @snippet example/core/common.cpp main
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    template <typename T, typename U, typename optional when-based enabler>
    struct common { };
#else
    template <typename T, typename U, typename = void>
    struct common
    //! @cond
        : common<T, U, when<true>>
    //! @endcond
    { };

    template <typename T, typename U, bool condition>
    struct common<T, U, when<condition>> { };

    template <typename T>
    struct common<T, T> { using type = T; };

    template <typename T, typename U>
    struct common<T, U, when_valid<decltype(
        true ? detail::std::declval<T>() : detail::std::declval<U>()
    )>> {
        using type = typename detail::std::decay<decltype(
            true ? detail::std::declval<T>() : detail::std::declval<U>()
        )>::type;
    };
#endif

    //! @ingroup group-core
    //! Alias to `common<T, U>::%type`, provided for convenience.
    template <typename T, typename U>
    using common_t = typename common<T, U>::type;
}} // end namespace boost::hana

#endif // !BOOST_HANA_CORE_COMMON_HPP
