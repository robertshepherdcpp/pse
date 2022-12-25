#pragma once

#include"pack_size.hpp"
#include"pack_at.hpp"
#include"ErrorCode.hpp" // so that we can throw an exception when out of bounds.

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
            if (m_data) // check if data is already allocated, becuase we don't want
                        // to deallocate memory that we don't already own!
            {
                delete[] m_data;
            }
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

        Vec() {/*Do nothing because everything is already initialized. Well sort of*/ }

        auto operator[](int i) -> T
        {
            if (i > size)
            {
                // return T{}; No instead of returning T{} we should throw an error code.
            }
            return m_data[i];
        }

        // Jason Turner preferse .at() instead of operator[], he considers it to be 
        // a best practice so i will implement a .at() member function with bounds checking.

        auto at(int i)
        {
            if (i > size)
            {
                throw ErrorCode{026}; // ErrorCode 026 is for out of bounds.
            }
            else
            {
                return m_data[i];
            }
        }


        int size = 0;
        //T m_data[1];
        T* m_data;
    };
} // namespace pse
