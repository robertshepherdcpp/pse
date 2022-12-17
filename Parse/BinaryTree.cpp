#pragma once

#include"Node.cpp" // pse::Node<T>
#include"pack_at.cpp" // pse::pack_at
#include"pack_size.cpp" // pse::pack_size

namespace pse
{
	template<typename T> // template for type of Node.
	struct BinaryTree
	{
		Node<T>* curr;

		auto left() { if (curr->first_child != nullptr) curr = curr->first_child; }
		auto right() { if (curr->right_child != nullptr) curr = curr->second_child; }
		auto up() { if (curr->parent != nullptr) curr = curr->parent; }

		auto get() { return curr.m_data; }

		template<typename NodeType, typename... NodeTypes>
		BinaryTree(NodeType* n, NodeTypes*... ns);

		template<typename NodeType>
		BinaryTree(NodeType* n);
	};

	template<typename T>
	template<typename NodeType, typename... NodeTypes>
	BinaryTree<T>::BinaryTree(NodeType* n, NodeTypes*... ns)
	{
		// have a deepest node value
		NodeType* deepest = curr;
		// FIXME: finish implementation.
	}

	template<typename T>
	template<typename NodeType>
	BinaryTree<T>::BinaryTree(NodeType* n)
	{
		// not sure if these will assign deeply, though.
		NodeType* deepest = curr;
		deepest = n;
	}
} // namespace pse