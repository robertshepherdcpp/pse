#pragma once

#include"pack_size.cpp"
#include"pack_at.cpp"

// a better pse::Vector

namespace pse
{
    template<typename T>
    struct Vec
    {
        // Another way of using a pse::Initializer_List.
        template<typename A, typename... B>
        Vec(A a, B... b)
        {
            size = pack_size<A, B...>::value;
            const int new_size = size;
            delete[] m_data;
            m_data = new T[new_size];
            for (int i = 0; i < size; i++)
            {
                m_data[i] = pack_at<T, A, B...>(0, i, a, b...);
            }
        }

        template<typename A>
        Vec(A a)
        {
            size = 1;
            // don't need to do anything more as the size of m_data is originally 1.
            size[0] = a;
        }

        auto operator[](int i) -> T
        {
            if (i > size)
            {
                return T{};
            }
            return m_data[i];
        }

        int size = 0;
        //T m_data[1];
        T* m_data;
    };
} // namespace pse
