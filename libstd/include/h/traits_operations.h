/// @file traits_operations.h
/// @data 07/03/2014 16:55:53
/// @author Ambroise Leclerc
/// @brief Type traits operations.
//
// Embedded Template Library
// Copyright (c) 2014, Ambroise Leclerc
//   All rights reserved.
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in
//     the documentation and/or other materials provided with the
//     distribution.
//   * Neither the name of the copyright holders nor the names of
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS'
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.

#ifndef ETL_LIBSTD_TRAITS_OPERATIONS_H
#define ETL_LIBSTD_TRAITS_OPERATIONS_H

namespace std {
/// Base class for type traits. Wraps a static constant of specified type.
template<class T, T v>
struct integral_constant {
  static constexpr T value = v;
  typedef T value_type;
  typedef integral_constant type;
  constexpr operator value_type() const { return value; }
  constexpr value_type operator()() const { return value; }
};

typedef integral_constant<bool, true> true_type;	///> Specialization for type bool
typedef integral_constant<bool, false> false_type;  ///> Specialization for type bool


/// Determines whether the two given types are equivalent.
template<typename T, typename U> struct is_same       : false_type {};
template<typename T>             struct is_same<T, T> : true_type {};  
 
/// Provides member typedef type, which is defined as T if B is true at
/// compile time, or as F if B is false.
template<bool, class T, class F>  struct conditional { typedef T type; };
template<class T, class F>        struct conditional<false, T, F> { typedef F type; };

/// Obtains the type T without const qualification.
template <class T> struct remove_const          { typedef T type; };
template <class T> struct remove_const<const T> { typedef T type; };

/// Obtains the type T without volatile qualification. 
template <class T> struct remove_volatile             { typedef T type; };
template <class T> struct remove_volatile<volatile T> { typedef T type; };

/// Obtains the type T without const or volatile qualification.
template <class T>
struct remove_cv {
    typedef typename std::remove_volatile<typename std::remove_const<T>::type>::type type;
};

} // namespace std
#endif // ETL_LIBSTD_TRAITS_OPERATIONS_H