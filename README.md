# pse library

### FAQ

What is the pse library?
- Well, it is a library that does not depend on the standard library! It is still a work in progress with lots of features that still need to be implemented. But it resembles lots of features that the standard library has.

How can I contribute?
- There are many ways that you can contribute. First, by trying to fix issues that have been put in the issues section of this repository. Secondly, by implementing a feature that you think would be a good feature in the pse library and then opening a pull request!

How old is the pse library?
- Really new! It started in late November 2022!

### Contributors
A list of all the people have helped in the process of making this repository!

- [@robertshepherdcpp](https://github.com/robertshepherdcpp/)
- [@ryuusama09](https://github.com/ryuusama09)
- [@tarunsamanta2k20](https://github.com/tarunsamanta2k20)

### The Documentation:

Total Number of Lines: 4609
Last Checked: 12/23/2022 17:18 PM London.

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

In the `Traits.cpp` header file, there are many useful `class`es/`struct`s that are all just instances of meta-programming. In the traits library there is also an `_v` option for nearly every trait bar a few like add_ref_ref, and add_pointer_pointer. For example `pse::Is_Type`, it's implementation looks like this:
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
There is also `pse::Remove_Volatile` and with it comes `pse::Remove_Volatile_v`. Given a type it removes the volatile from it (if there is any). An example implementation looks like this:
```C++
template<typename T>
struct Remove_Volatile
{
  // Implementation.
};

template<typename T>
struct Remove_Volatile_v = Remove_Volatile<T>::value;
```
There is also `remove_const_volatile_ref` which removes all type specifiers. For example if it is given `const volatile& char` it's value would be char. It's implementation looks like this:
```C++
template<typename T>
struct remove_const_volatile
{
    using value = Remove_Const_v<Remove_Volatile_v<Remove_Ref_v<T>>>;
};
```
There is also `remove_const_volatile_ref_v` which is just like `Remove_Const_v` and `Remove_Volatile_v` in that it gets the value out of the class `remove_const_volatile_ref` with the type `T`. An example implementation looks like this:
```C++
template<typename T>
using remove_const_volatile_ref_v = remove_const_volatile_ref<T>::value;
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

There is also `pse::abs`, this function gives the absolute value of a number. This is the distance between 0 and the number, with no regard to direction. So if i has a number -5 and i used `pse::abs` the output would be 5 because the distance between -5 and 0 is 5. So if i passed in 5 to `pse::abs` it would give me the same answer 5. It is basically just a way of getting rid of zero. Here is an example implementation:

```C++
inline double abs(double i)
{
	if (i < 0)
	{
		return (i + (0 - i) + i); // this bit here is the magic.
	}
	else
	{
		return i;
	}
}
```

There is also `pse::floor` this just rounds down to the nearest whole number, an example implemenation looks like this:
```C++
auto abs(double b)
{
  // Implementation.
}
```
There is also `pse::ciel` which is just basically the opposite of `pse::floor` in that is rounds up to the nearest whole number. An example implemenatation looks like this:
```C++
auto ciel(double b)
{
  // Implemenatation.
}
```
There is also `pse::round` which rounds to the nearest whole number. So if `x < 0.5` round down otherwise, `x => 0.5` round up. An example implemenation looks like this:
```C++
auto round(double b)
{
  // Implemenatation.
}
```
There is also the famous `gcd` algorithm that find the Greatest Common Divisor. An example implemenatation looks like this:
```C++
int gcd(int a, int b) {
  // base case
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  // recursive case
  if (a > b) {
    return gcd(a % b, b);
  } else {
    return gcd(a, b % a);
  }
}
```
There is also the LCM algorithm, the Lowest Common Multiple algorithm finds the lowest common multiple of two numbers, an example implementation looks like this:
```C++
int lcm(int a, int b)
{
    // Find the greatest common divisor of a and b
    int gcd = 1;
    for (int i = 2; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }

    // Return the LCM of a and b
    return (a * b) / gcd;
}
```
There is also `pse::Node` this is just like any other node that you would find, it has a parent: `parent` and two child nodes: `left_child` and `right_child`. An example implemenation of `pse::Node` looks like this:
```C++
template<typename T>
struct Node
{
  T m_data;

  Node<T>* parent;
  Node<T>* first_child;
  Node<T>* second_child;
};
```

There is also a `pse::BinaryTree`, it looks something like this:
```C++
template <typename T>  // template for type of Node.
struct BinaryTree {
    Node<T>* curr;

    auto left() {
        if (curr->first_child != nullptr) curr = curr->first_child;
    }
    auto right() {
        if (curr->right_child != nullptr) curr = curr->second_child;
    }
    auto up() {
        if (curr->parent != nullptr) curr = curr->parent;
    }

    auto get() { return curr.m_data; }

    template <typename NodeType, typename... NodeTypes>
    BinaryTree(NodeType* n, NodeTypes*... ns);

    template <typename NodeType>
    BinaryTree(NodeType* n);
};
```
But it is only partially implemented, so it is not production code ready yet. But it has quite a lot of the functionality, but the constructors are not the best.

There is also `pse::enable_if`, that is just like `std::enable_if`. It rely's on SFINAE (Substitution Failiure Is Not An Error). `pse::enable_if` can be replaced with other things like c++20 concepts, but in case you don't have a modern c++20 compiler, enable_if is implemented. It's implementation looks like this:
```C++
// the base template
template<bool B, typename T>
struct enable_if
{
};

// the specialisation
template<typename T>
struct enable_if<true, T>
{
  using value = T;
}

template<bool b, typename T>
using enable_if_v = enable_if<b, T>::value;
```

There are also several useful factory functions in the pse library, although they have obsure names they are very useful! There is `factory_parameter_pack_non_typename` there is `factory_parameter_pack_typename`, there is `factory_construct_typename`, there is `factory_construct_non_typename`.

Here are example inmplementations of them all:

`factory_constructor_non_typename`:
```C++
template<typename Class, detail::constructor& p_p, auto&&... Args>

	struct factory_constructor_non_typename
	{
		auto operator()()
		{
			return Value;
		}

		Class Value{ Args... };
	};
	
```
`factory_parameter_pack_non_typename`:
```C++

	
	template<typename Class, detail::parameter_pack& c, auto&&... Args>
	struct factory_parameter_pack_non_typename
	{
		auto operator()()
		{
			return Value;
		}

		Class Value = Class{ Args... };
	};
```
`factory_construct_typename`:	
```C++
	template<typename Class, detail::constructor& c, typename... Args>
	struct factory_construct_typename
	{
		auto operator()(Args... args)
		{
			return Class{ args... };
		}
	};
```
`factory_parameter_pack_typename`:
```C++

	template<typename Class, detail::parameter_pack& p_p, typename... Args>
	struct factory_parameter_pack_typename
	{
		constexpr auto operator()(Args... args)
		{
			return Class{args...};
		}
	};
	
```

There is also `char_int` so that you can convert between chars and ints, it only works with single digit digits though because, for instance you cannot do this `432 -> '432'` because that does not fit inside a character! There is `int_to_char` and `char_to_int`. Here is an example implementation of `int_to_char`:
```C++
  auto int_to_char(int i)
  {
    return (static_cast<char>(i + 48));
  }
```
And an example implementation of `char_to_int` is as follows:
```C++
  auto int_to_char(int i)
  {
    return (static_cast<char>(i + 48));
  }
```

`pse::CodeMeaning` contained in the `CodeMeaning.cpp` header file has lots of different `if`'s and `else if`'s in order to find the write error code, here is a collection of the error codes and their values.

There is also `pse::index_sequence`. This generates a sequence of indixes for the passed parameter pack `T` and `Ts...`. It will have a `const`ant array `indeces` containing all of the indexes for the types that you have passed.  An examle of calling it would look like this:
```C++
index_sequence<0, int, float, char, bool> i_s{};
```
so then the array `indeces` will have the following values: `0, 1, 2, 3`. An example implementation of `pse::index_sequence` is as follows:
```C++
template<auto StartSize = 0, typename T, typename... Ts>
struct index_sequence
{
    decltype(StartSize) indeces[sizeof...(Ts) + 1){/*indeces*/};
    
    // rest of implementation.
};
```

```C++
026: Out Of Bounds Access.
034: Your hardware is not supported.
054: Unvalid Type.
056: Boolean evaluated to false.
076: Not A Number (NaN).
84: This Function Is No Longer In Use.
96: Your Software is not supported.
```
<details><summary>Some Useful Links</summary>
<p>

The pse Library blog!
https://rshepherdcpp.wixsite.com/none/post/the-pse-library-new-idiom

SonarLink: https://sonarcloud.io/project/configuration?id=robertshepherdcpp_pse&analysisMode=GitHubActions

</p>
</details>
