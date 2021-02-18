# Type support (basic types, type traits)

## Basic types introduced to the library
Defined in header [`Types.hpp`](../cpp/Types.hpp)

```c++
using usize = /* implementation-defined native unsigned size type */;
using isize = /* implementation-defined native signed size type */;

using ulong = unsigned long;
using u64 = unsigned long long;
using u32 = unsigned int;
using u16 = unsigned short;
using u8 = unsigned char;

using i64 = long long;
using i32 = int;
using i16 = short;
using i8 = char;

using wchar = wchar_t;
using uchar = unsigned char;
using char8 = char8_t;
using char16 = char16_t;
using char32 = char32_t;

using f128 = long double;
using f64 = double;
using f32 = float;

using NullType = decltype(nullptr);
```

Additional wide integral types are conditionally supported
```c++
using u128 = /* unsigned 128-bit integer type */;
using i128 = /* signed 128-bit integer type */;
```

## Type traits
Defined in header [`TypeTraits.hpp`](../cpp/TypeTraits.hpp)

### Literal constant
```c++
template <typename T, T v>
struct literal_constant
{
    using type = T;
    static inline constexpr T value = v;
};
```

Used as the basic template type that holds a literal constant value.

```c++
using true_type = literal_constant<bool, true>;
using false_type = literal_constant<bool, false>;
```
| Type | Description |
| :--- | :---------- |
| `enable_if<bool, typename>`  | Defines a member type-def `type` aliasing second parameter, if the first parameter is `true`  |
| `disable_if<bool, typename>` | Defines a member type-def `type` aliasing second parameter, if the first parameter is `false` |
| `conjunction<typename...>`   | Defines a static `bool` member `value` that is the fold-`&&` expression of all parameters' `value` static members |
