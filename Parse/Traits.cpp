#pragma once

namespace pse
{
	namespace Traits
	{

		// A really simple but really useful type trait.
		template<typename... Things>
		using void_t = void;

		template<bool B>
		struct bool_constant
		{
			static constexpr bool value = B;
		};

		struct true_type : bool_constant<true> {};
		struct false_type : bool_constant<false> {};

		template<typename A, typename B>
		struct IsLargerThan
			: bool_constant<(sizeof(A) > sizeof(B))>
		{
		};

		template<typename A, typename B>
		struct IsSameThan
			: bool_constant < sizeof(A) == sizeof(B) >
		{
		};

		template<typename A, typename B>
		struct IsLessThan
			: bool_constant < sizeof(A) < sizeof(B) >
		{
		};

		template<typename A, typename B>
		struct Is_Same
		{
			static constexpr auto value = false;
		};

		template<typename T>
		struct Is_Same<T, T>
		{
			static constexpr auto value = true;
		};

		template<typename A, typename B>
		static constexpr bool Is_Same_v = Is_Same<A, B>::value;

		template<typename T>
		struct Add_Const
		{
			using value = const T;
		};

		template<typename T>
		struct Add_Const<T const>
		{
			using value = T;
		};

		template<typename T>
		using Add_Const_v = Add_Const<T>::value;

		template<typename T>
		struct Remove_Const
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Const<T const>
		{
			using value = T;
		};

	    template<typename T>
		using Remove_Const_v = Remove_Const<T>::value;

		template<typename T>
		struct Add_Ref
		{
			using value = T&;
		};

		template<typename T>
		struct Add_Ref<T&>
		{
			using value = T;
		};

		template<typename T>
		using Add_Ref_v = Add_Ref<T>::value;

		template<typename T>
		struct Remove_Ref
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Ref<T&>
		{
			using value = T;
		};

		template<typename T>
		using Remove_Ref_v = Remove_Ref<T>::value;

		template<typename T>
		struct Add_Pointer
		{
			using value = T*;
		};

		template<typename T>
		struct Add_Pointer<T*>
		{
			using value = T;
		};

		template<typename T>
		using Add_Pointer_v = Add_Pointer<T>::value;

		template<typename T>
		struct Remove_Pointer
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Pointer<T*>
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Pointer<T**>
		{
			using value = T;
		};

		template<typename T>
		using Remove_Pointer_v = Remove_Pointer<T>::value;

		template<typename T>
		struct Add_Pointer_Pointer
		{
			using value = T**;
		};

		template<typename T>
		struct Add_Pointer_Pointer<T*>
		{
			using value = T*;
		};

		template<typename T>
		struct Add_Pointer_Pointer<T**>
		{
			using value = T;
		};

		template<typename T>
		struct Add_Rvalue_Ref
		{
			using value = T&&;
		};

		template<typename T>
		struct Add_Rvalue_Ref<T&&>
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Ref<T&&>
		{
			using value = T;
		};

		template<typename T>
		struct Is_Pointer
		{
			static constexpr bool value = false;
		};

		template<typename T>
		struct Is_Pointer<T*>
		{
			static constexpr bool value = true;
		};

		template<typename T>
		static constexpr bool Is_Pointer_v = Is_Pointer<T>::value;

		template<typename A, typename B>
		concept same_as = requires(A a, B b)
		{
			Is_Same<A, B>::value;
		};

		template<typename T>
		concept is_pointer = requires(T t)
		{
			Is_Pointer<T>::value == true;
		};

        template<typename T>
		concept is_ref = requires(T t)
		{
			Is_Same < T, Add_Ref<T>::value>::value == true;
		};

		template<typename T>
		struct Type
		{
			using value = T;
		};

		template<typename T>
		concept is_const = requires(T t)
		{
			Is_Same<T, Add_Rvalue_Ref<T>::value>::value == true;
		};

		// template<typename T>
		//concept is_ref = requires(T t)
		//{
		//	Is_Same<T, Add_Rvalue_Ref<T>::value>::value == true;
		//};

		template<typename T>
		concept is_type = true;

		template<typename T>
		concept is_swappable = requires(T t)
		{
			t.swap(t);
		};

		template<typename T>
		concept is_not_swappable = requires(T t)
		{
			!is_swappable<T>;
		};

		template<is_swappable T>
		struct Is_Swappable
		{
			static constexpr bool value = true;
		};

		template<typename T>
		concept is_rvalue_ref = requires(T t)
		{
			Is_Same<T, Add_Rvalue_Ref<T>::value>::value == true;
		};

		template<typename T>
		struct Is_Type
		{
			static constexpr bool value = true;
		};

		/* Doesn't work, needs the same template parameter as Is_Type, see above.
		template<auto T>
		struct Is_Type<T>
		{
			static constexpr bool value = false;
		};
		*/

		template<typename T>
		concept is_integral = requires(T t)
		{
			t += t;
			t /= t;
			t *= t;
			t * t;
			t / t;
			t + t;
			t -= t;
			t - t;
		};

		// Make type A of type B;
		template<typename A,typename B>
		struct Make
		{
			A a{};
			B b{};
		};
		// ^ i don't think is implementable.
		// |

		template<typename T>
		concept is_string = requires(T t)
		{
			t += t;
			t + t;
			t.substr(1, 2);
			t -= t;
			t - t;
			t[0];
		};

		template<typename T, template<typename A> typename... Traits>
		struct Conjunction
		{
			// trying to use the c++17 fold expression but giving the error: syntax error: '('
			// using value = (Traits<T>...)::value;
		};

		template<typename T, typename... Ts>
		struct common_type
		{
			// needs implementating
		};

		template<bool T, bool... Ts>
		struct conjunction
		{
			static constexpr bool value = T && conjunction<Ts...>::value;
		};

		template<bool T>
		struct conjunction<T>
		{
			static constexpr bool value = T;
		};

		template<bool B, typename T>
		struct enable_if
		{
			// No implementation as B evalutated to false.
		};

		template<typename T>
		struct enable_if<true, T>
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Volatile
		{
			using value = T;
		};

		template<typename T>
		struct Remove_Volatile<T volatile>
		{
			using value = T;
		};

		template<typename T>
		using Remove_Volatile_v = Remove_Volatile<T>::value;

		template<typename T>
		struct remove_const_volatile_ref
		{
			using value = Remove_Const_v<Remove_Volatile_v<Remove_Ref_v<T>>>;
		};

		template<typename T>
		using remove_const_volatile_ref_v = remove_const_volatile_ref<T>::value;

		template<bool B, typename T>
		using enable_if_v = enable_if<B, T>::value;

	} // namespace Traits
} // namespace pse