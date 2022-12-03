# Parse

Total Number Of Lines: 2566
Last Checked: 12/3/2022 19:32 PM London.

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
There is also swap for `pse::Iterator` using `pse::Itertor.get_ref` and swapping like that. so if you had: `pse::Iterator<int> it1{int42pointer};` and `pse::Iterator<T> it2{int24pointer};` and then we called `pse::swap` that this time is implemented in the `Algo.cpp` header file, and did `std::cout << it1.get_val();` and `std::cout << it2.get_val();` the output would be `2442`. Notice this is because we didn't output `\n`. It looks the same as pse::swap but the generic version.

```C++
// Algo.cpp
template<typename T>
auto swap(Iterator<T>& it)
{
  // swaps the two values
}
```
Others also include:

`pse::Range`:

This is just a structure like a `Initializer_List` in that it stores data as a list with member functions. But it can also hold different types of types like `int` and `float` but it is not used for this purpose it is used for being like an `Initialiser_List`. This `Range` structure also has member functions, more are still to be implemented but the major one for now is `pse::Range::Take(int a, int b)` it takes two integers and returns the bit of the array in between those two indexes. There is not any error checking yet but will be soon.
```C++
template<typename T, typename... Ts>
struct Range
{
  // Implemenetation.
};
```
There is also `pse::Iterator` which looks like the following:
```C++
template<typename T>
struct Iterator
{
  auto operator++();
  auto operator--();
  auto operator+=();
  auto operator-=();
  
  auto get();
  auto get_val();
  decltype(auto) get_ref();
  
  auto get_Increment();
  auto get_Dectrement();
  
  auto get_PlusEquals();
  auto get_MinusEquals();
  
  auto begin();
  auto end();
  
  int size;
};
```
It is just a safer way to use `T*` in that you can increment: `++`, decrement: `--` but it is just better, there are set member functions `get` and `get_val` and not accidently using a pointer rather than the value conatained beneath the pointer. It also has the `size` member variable. `pse::Iterator.begin()` return the `value` datamember because that is the start. Also `pse::Iterator.end()` returns a default initialized `pse::Iterator<T>` like this `return pse::Iterator<T>{};`. We do this because we are using a higher level iterator and `pse::Iterator<T>{}` is a good sentinel value.

Also in the `Algo.cpp` header file, there are many algorithms:

```C++
template<typename Callable>
pse::Invoke(Callable& c)
{
  return c();
}
```
It is just like `std::invoke` but oviously in the `pse` library. It just returns the invoked callable passed in. It can be a lambda expression: `[](){}` a struct that has the `operator()` like this `struct s{auto operator();}` and that would work. It is a very simple function.

There is also `pse::OnAll` which takes an Iterator and a lamba and calls that lambda on all of the elemts:
```C++
template<typename T, typename Callable>
auto OnAll(Iterator<T>& it, Callable& c)
{
  // calls the lamdba on all of the it elements in the Iterator.
  // Only works if the constructor was passed a size.
}
```
`pse::OnAll` acts just like `pse::for_each`. There is no error handling for this though so if you pass in a lambda that takes an `pse::StringList` and you pass an `Iterator<T>` of type `int` you will just get an error. So use the power to pass in what you want wisely!

There is also `pse::Sort` it sorts all the elements in a `pse::Iterator<T>` by using the `pse::swap` overload for `pse::Iterator`. Its implementation looks like this:
```C++
template<typename T>
auto Sort(Iterator<T>& it)
{
  // sorts by increasing value.
}
```
But there is also an overload that takes a lambda/callable to use on `pse::Sort`. It looks like this:

```C++
template<typename T, typename Callable>
auto Sort(Iterator<T>& it)
{
  // sort based on what value the callable/lambda returns.
  // when using this function the lambda/callable has to return a bool value.
}
```
