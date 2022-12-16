# Parse
!¬)

Total Number of Lines: 3613
Last Checked: 12/15/2022 16:51 PM London.

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
  
  auto operator[](int i);
}; // Just Tuple combined with a vector
```
Notice the `operator[]`, it is novel, but bear in mind it only works for tuple of the same types. This is because in order to have varying return types it has to be done at comile time, and passing an arguement to a function like this: `foo(int x)` is not done at compile time, therefore it will always return the type of the first type in the parameter pack!

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
`pse::pack_size` is a way to find the size of a parameter pack at compile time. It works a bit like a `pse::Tuple` in that it stores it's elements like `pse::Tuple<Ts...> other;` but it is for finding the size of a parameter pack instead. Say you have a parameter pack of `int, double, bool, char` and we didn't know the size of this parameter pack, we could use `pse::pack_size` by doing `pse::pack_size<int, double, bool, char>::value` and that will give us the value of `4`. An example implementation looks like this:
```C++
template<typename T, typename... Ts>
struct pack_size
{
};

template<typename T>
struct pack_size<T>
{
};
```
It is very simple, and all you have to do to access to size is to get the `static` datamember: `value`.
There is also a container called `pse::Bitmap`, it consists of a collection of datamembers that are aranged like this:
```C++
	[0, 0], [1, 0], [2, 0], [3, 0], [4, 0], [5, 0]
	
	[0, 1], [1, 1], [2, 1], [3, 1], [4, 1], [5, 1]
	
	[0, 2], [1, 2], [2, 2], [3, 2], [4, 2], [5, 2]
	
	[0, 3], [1, 3], [2, 3], [3, 3], [4, 3], [5, 3]
	
	[0, 4], [1, 4], [2, 4], [3, 4], [4, 4], [5, 4]
	
	[0, 5], [1, 5], [2, 5], [3, 5], [4, 5], [5, 5]
```
`pse::Bitmap`'s implementation looks a bit like this:
```C++
struct Bitmap
{
  // all of the usual constructors +
  template<typename T, typename... Ts>
  Bitmap(T t, Ts... ts);
  
  int m_bitmap[1][1];
};
```
It's constructor is very simple to use, you can simply pass in `pse::Down{3}, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14` and the `pse::Bitmap` will end up looking like this:
```C++
                 1, 6, 11
		 2, 7, 12
		 3, 8, 13
		 4, 9, 14
		 5, 10
```
We pass in `pse::Down{}` this tells us how many numbers we want across, in this case we passed in three, so it has three numbers down for example: `1, 2, 3, 4, 5` and the rest depends on how many numbers you passed in and the value of the `value` data member of `pse::Down`. The `pse::Down` shows us that we want `pse::Down::value` going down and the rest depends on what parameters we have passed in.

In the `Traits.cpp` header file, there are many useful `class`es/`struct`s that are all just instances of meta-programming. For example `pse::Is_Type`, it's implementation looks like this:
```C++
template<typename T>
struct Is_Type
{
};
```
`pse::Is_Same` compares two types to see if they are the same using partial template specialization. An example implementation looks like this:
```C++
template<typename A,  typename B>
struct Is_Same
{
};
```
There is also `pse::Add_Const` which just adds const to a type passed in, an example implementation looks like this:
```C++
template<typename T>
struct Add_Const
{
};
```
There is also a `class`/`struct` called `pse::Remove_Const` which just removes the `const` from a value (only if the type passed in is `const`). An example implementation looks like this:
```C++
template<typename T>
struct Remove_Const
{
};
```
There is also the same as for `pse::Add_Const` and `pse::Remove_Const`, there is `pse::Add_Ref` and `pse::Remove_Ref`. An example implementation of `pse::Add_Ref` looks like this:
```C++
template<typename T>
struct Add_Ref
{
};
```
And an example implemenatation of `pse::Remove_Ref` looks like this:
```C++
template<typename T>
struct Remove_Ref
{
};
```

There is also `pse::Add_Pointer` which adds a pointer to a given type. An example implementation of `pse::Add_Pointer` looks like this:
```C++
template<typename T>
struct Add_Pointer
{
};
```
Also you can check if a type is a pointer by doing this:
```C++
auto x = pse::Is_Same<pse::Add_Pointer<T>::value, T>::value;
```
To check wheather adding a pointer to an already pointer is the same type. Or you can just do:
```C++
pse::Is_Pointer<T>::value;
```
An example implementation of `pse::Is_Pointer` is:
```C++
template<typename T>
struct Is_Pointer
{
};
```

Also there is `pse::GeneratorSame` which is just a specialised `pse::Generator` for a gererator of the same type. It still has the same interface as `pse::Generator` but just small changes in the internal mechanisms. An example implementation looks like this:
```C++
template<auto T, auto... Ts>
struct GeneratorSame
{
  TupleCTAD<T, Ts...> types{};
  auto operator()();
};
```
So, as stated before the interface is just like the one seen in `pse::Generator`, so for more information look at the details of the `pse::Generator` implemenatation. The only difference between the two is that `pse::GeneratorSame` has a different internal mechanism of `operator()()`.

There are also lots of other algorithms in the `Algo.cpp` header file. One example is `pse::find` it just takes a data structure that has the `operator[]` and takes something to find. If it finds that thing in the data structure it returns the index that it was found at, if nothing was found then `0` will be retuned. An example implementation of `pse::find` looks like this:
```C++
auto find(auto& a, auto& ToFind)
{
 // Implemenatation.
}
```
There is also `pse::find_if` which finds an element in a data structure if it meets the requirement of the callable passed in. An example implementation looks like this:
```C++
auto find_if(auto& a, auto& Callable)
{
  // Implemenatation.
}
```
If the callable returns true with a given index of the data structure, that index is `return`ed otherwise `0` is `return`ed, to symbol that no value that met the condition of the Callable(something with `operator()`) evaluated to true in the data structure.

There is also `pse::reverse` which takes a given container `a` and reverses the elements in that array. The implementation looks a bit like this:
```C++
auto reverse(auto& a)
{
  // reverse the elements in the array.
}
```
So having a given input: `1, 2, 3, 4`, when passed to the reverse function, `pse::reverse` it will now look like: `4, 3, 2, 1`. Which is succesfully reversed! But the container that stores the elements it has to have `operator[]` and the types stored have to support `operator=` and those are mostly all of the constraints!

There is also `pse::apply` what this does it takes a range `r` and then takes two operations, `minus` and `times` for example. Say the range, `r` was `1, 2, 3, 4` and the operands were `pse::minus` and `pse::multiply`. It would look like this:
```C++
 (((0 -= (1 * 2)) -= (2 * 3)) -= (3 * 4))
```
An example implementation of `pse::apply` looks like this:
```C++
template<typename TypeOfRange>
auto apply(TypeOfRange& r, auto& first_operand, auto& second_operand)
{
  // implementation.
}
```

`pse::CodeMeaning` contained in the `CodeMeaning.cpp` header file has lots of different `if`'s and `else if`'s in order to find the write error code, here is a collection of the error codes and their values.

```C++
026: Out Of Bounds Access.
054: Unvalid Type.
076: Not A Number (NaN).
```

The pse Library blog!
https://rshepherdcpp.wixsite.com/none/post/the-pse-library-new-idiom

SonarLink: https://sonarcloud.io/project/configuration?id=robertshepherdcpp_pse&analysisMode=GitHubActions
