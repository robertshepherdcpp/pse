#include"TupleLike.cpp"

/*
* Robert Shepherd (c) Copywrite 2022
* Generator is just basically a programmable object:
*/

/*
* Generator.add_action([](){std::cout << "First Action"});
* Generator.add_actoin([](){std::cout << "Second Action"});
* 
* It is a bit like a coroutine in that it kindof suspends and resumes when called. An example
* of calling it is:
*
* Generator() // outputs "First Action"
* Generator() // outputs "Second Action"
* 
*/

/*
* Make TupleLike type.
* 
* What it does:
* 
* like a vector in that it can change size, but it can have many different types.
*/

namespace pse
{
	struct Generator
	{
		// TupleLike v{};
	};
};