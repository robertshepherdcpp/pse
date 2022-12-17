#pragma once

namespace pse
{
	template<typename T>
	struct Node
	{
		T m_data;

		Node* parent;
		Node* first_child;
		Node* second_child;
	};

	/*
	* One of these nodes will look like this:
	*            pse::ParentNode
	*                  /\
	*                 /  \
	*                /    \
	*               /      \
	*              /        \
	*             /          \
	*        Other Node     This Node
	*                           /\
	*                          /  \
	*                         /    \
	*                        /      \
	*                     first    second
	*                     child    child
	*/

} // namespace pse