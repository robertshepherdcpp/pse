#pragma once

namespace pse
{
	template<typename T, typename... Ts>
	struct DecreasingTuple
	{

		DecreasingTuple(T t, Ts... ts)
		{
			First = t;
			Seconds = DecreasingTuple<Ts...>{ ts... };
		}

		auto DecreaseBy(int i)
		{
			size = i;
		}

		template<int I>
		auto get()
		{
			if constexpr(I > value)
			{
				return {};
			}
			else
			{
				return Seconds.get<I>();
			}
		}

		int size = value;

		// static constexpr int value = 1 + Seconds::value;
		int value = (sizeof(Ts)...) / sizeof(T);

		T First{};
		DecreasingTuple<Ts...> Seconds{};
	};

	template<typename T>
	struct DecreasingTuple<T>
	{
		T First{};

		DecreasingTuple(T t)
		{
			First = t;
		}

		auto get()
		{
			return First;
		}

		int size = 0;

		static constexpr int value = 1;
	};
} // namespace pse