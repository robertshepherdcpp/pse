// #include<compare> // for the spaceship

namespace pse
{
	template<int T>
	struct fixed_string
	{
		char chars[T + 1] = {};
		constexpr fixed_string(char(&arr)[T])
		{
			for (int i = 0; i < T; i++)
			{
				chars[i] = arr[i];
			}
		}
		// auto operator<=>(const fixed_string&) const = default;
	};

	template <unsigned long N>
	fixed_string(const char(&str)[N])->fixed_string<N - 1>;

	template<fixed_string s, typename T> // s is the tag and T is type of member
	struct member
	{
		typedef T member_type;
		T value_{};
		member(T val) { value_ = val; }
		member() {}
		auto tag() { return s; }
		auto value() { return value_; }
	};

	template<fixed_string s, typename T>
	auto make_member(T value) -> member<s, T>
	{
		return member<s, T>{value};
	}

	template<typename... Ts>
	struct overload : Ts...
	{
		using Ts::operator()...;
	};

	template<typename T>
	struct is_member
	{
		constexpr static auto value = false;
	};

	template<typename T>
	concept IsMember = is_member<T>::value;

	template<fixed_string s, typename T>
	struct is_member<member<s, T>>
	{
		constexpr static auto value = true;
	};

	template<typename T>
	struct meta_struct
	{
		//template<auto index, typename T>
		//auto add_member(T t) -> void
		//{
		//    
		//}

		T data_member;

		//template<fixed_string tag>
		//constexpr auto read() const noexcept
		//{
		//	return read_struct<tag>(*this);
		//}

		// Link to source: https://github.com/fengwang/meta-structure/blob/main/meta_structure.hpp

		//template< fixed_string tag_, meta_struct S >
		//constexpr auto read_struct(S const& structure) noexcept
		//{
		//	return structure([&](member const& member1, member const& ... members) noexcept
		//	{
		//		if constexpr (M.tag() == tag_)
		//			return member1.value();
		//		else
		//		{
		//			static_assert(sizeof...(MS) > 0, "This field is not defined in the structure.");
		//			return read_struct<tag_>(create_struct(members...));
		//		}
		//	});
		//}
	};
}