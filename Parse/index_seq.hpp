#pragma once

namespace pse
{
	// index sequence only
	template <int ...>
	struct index_sequence
	{
	};

	template <int N, int ... Next>
	struct index_sequence_helper : public index_sequence_helper<N - 1, N - 1, Next...>
	{
	};

	template <int ... Next>
	struct index_sequence_helper<0U, Next ... >
	{
		using type = index_sequence<Next ... >;
	};

	template <int N>
	using make_index_sequence = typename index_sequence_helper<N>::type;
} // namespace pse