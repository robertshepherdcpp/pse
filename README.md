# Parse

Total Number Of Lines: 2128

Last Checked: 11/27/2022 20:57 PM London.

Parse is a helpful open-source library for C++. Consisting of many features that are part of the C++ Standard Library
Here are some examples:

A `pse::vector` is just like a `std::vector`, consisting of all of the same functionality.

```C++
template<typename T>
struct Vector{};
```
`Tuple` is again just like the `std::tuple` with all of the functionality.
```C++
template<typename T, typename... Ts>
struct Tuple{};
```
But this one is currently in progress. I am currently now making one that doesn't increase in size but decreases in size only, so it has part of the functionality of a `vector` but not the `push_back` functionality part. It will be called `DecreasingTuple`
```C++
template<typename T, typename... Ts>
struct TupleLike
{
  template<typename T>
  auto push_back(B b);
}; // Just Tuple combined with a vector
```
`swap` is also just like `std::swap`. But a bit more basic.
```C++
template<typename T>
auto swap(T& a, T& b)
{
  // Implementation
}
```
Others also include:
This is just a structure like a `Initializer_List` in that it stores data as a list with member functions. But it can also hold different types of types like `int` and `float` but it is not used for this purpose it is used for being like an `Initialiser_List`. This `Range` structure also has member functions, more are still to be implemented but the major one for now is `pse::Range::Take(int a, int b)` it takes two integers and returns the bit of the array in between those two indexes. There is not any error checking yet but will be soon.
```C++
template<typename T, typename... Ts>
struct Range
{
  // Implemenetation.
};
```

