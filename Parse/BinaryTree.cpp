#pragma once

#include"Node.cpp" // pse::Node<T>
#include"pack_at.cpp" // pse::pack_at
#include"pack_size.cpp" // pse::pack_size

namespace pse
{
    // https://www.godbolt.org/z/rPzja18nW

	template<typename T> // template for type of Node.
	struct BinaryTree
	{
		Node<T>* curr;
		Node<T>* root;

		BinaryTree(Node<T>* root_node) : root(root_node), curr(root_node) {}

		auto left() { if (curr->first_child != nullptr) curr = curr->first_child; }
		auto right() { if (curr->right_child != nullptr) curr = curr->second_child; }
		auto up() { if (curr->parent != nullptr) curr = curr->parent; }

		auto get_left() { if (curr->first_child != nullptr) return curr->first_child; }
		auto get_right() { if (curr->right_child != nullptr) return curr->second_child; }
		auto get_up() { if (curr->parent != nullptr) curr = curr->parent; }

		auto get() { return curr.m_data; }

		template<typename NodeType, typename... NodeTypes>
		BinaryTree(NodeType* n, NodeTypes*... ns);

		// template<typename NodeType>
		// BinaryTree(NodeType* n);
	};

	template<typename T>
	template<typename NodeType, typename... NodeTypes>
	BinaryTree<T>::BinaryTree(NodeType* n, NodeTypes*... ns)
	{
		// have a deepest node value
		NodeType* deepest = curr;
		// FIXME: finish implementation.
	}

	//template<typename T>
	//template<typename NodeType>
	//BinaryTree<T>::BinaryTree(NodeType* n)
	//{
	//	// not sure if these will assign deeply, though.
	//	NodeType* deepest = curr;
	//	deepest = n;
	//}
} // namespace pse