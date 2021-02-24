#pragma once

#include <type_traits>

namespace hsd
{

    struct type_identifier_base
    {
        bool is(type_identifier_base* other) noexcept
        {
            return this == other;
        }

        enum
        {
            is_const = 1,
            is_volatile = 2
        };
    };

    template <typename T>
    struct type_identifier : type_identifier_base
    {
        static type_identifier _inst;
    };

    template <typename T>
    constexpr static int _any_flags_for = ((std::is_const_v<T> ? type_identifier_base::is_const : 0) |
                                           (std::is_volatile_v<T> ? type_identifier_base::is_volatile : 0));

    struct observer_any
    {
        type_identifier_base* _type;
        int _flags;
        void* _ptr;

        template <typename T>
        observer_any(T* ptr)
            : _type(&type_identifier<std::remove_cv_t<T>>::_inst), _flags(_any_flags_for<T>), _ptr(ptr) {}

        template <typename T>
        bool is() const
        {
            int flags = _any_flags_for<T>;
            return _type->is(&type_identifier<std::remove_cv_t<T>>::_inst) && ((flags & _flags) == _flags);
        }

        template <typename T>
        T* try_as() const
        {
            return is<T>() ? static_cast<T*>(_ptr) : nullptr;
        }

        // ! Warning: Held type must be T or more cv-qualified T
        template <typename T>
        T& get_unsafe() const
        {
            return *static_cast<T*>(_ptr);
        }
    };
}
