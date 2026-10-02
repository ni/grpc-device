#ifndef NILRT_CXX17_TYPE_TRAITS_H
#define NILRT_CXX17_TYPE_TRAITS_H

#include <type_traits>

#if __cplusplus < 201703L
namespace std {
template <typename T, typename U>
inline constexpr bool is_same_v = is_same<T, U>::value;

template <typename T>
inline constexpr bool is_const_v = is_const<T>::value;
}  // namespace std
#endif

#endif
