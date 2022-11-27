# Parse

Parse is a helpful open-source library for C++. Consisting of many features that are part of the C++ Standard Library
Here are some examples

```C++
template<typename T>
struct Vector{};
```

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

```C++
template<typename T>
auto swap(T& a, T& b)
{
  // Implementation
}
```

