# Library-wise preprocessor macros

Defined in header [`_Define.hpp`](../cpp/_Define.hpp)

## Platform-specific macros

### `HSD_PLATFORM_WINDOWS`
Defined when targetting Microsoft Windows platform.

### `HSD_PLATFORM_LINUX`
Defined when targetting Linux platform.

### `HSD_PLATFORM_BSD`
Defined when targetting BSD platform.

### `HSD_PLATFORM_OSX`
Defined when targetting OSX/MacOS platform.

### `HSD_PLATFORM_UNIX`
Defined when targetting other Unix-compatible platform not listed above.

### `HSD_PLATFORM_UNKNOWN`
Defined when targetting an unknown platform.

### `HSD_PLATFORM_POSIX`
Defined when targetting a POSIX-complaint platform, including `Linux`, `BSD`, `OSX/MacOS`
or other Unix-compatible platform.

### `HSD_COMPILER_GCC`
Defined when compiled with GCC compiler.

### `HSD_COMPILER_INTEL`
Defined when compiled with Intel C++ compiler.

### `HSD_COMPILER_CLANG`
Defined when compiled with Clang compiler.

### `HSD_COMPILER_MSVC`
Defined when compiled with Microsoft Visual C++ compiler.

### `HSD_COMPILER_UNKNOWN`
Defined when compiled with an unknown compiler.

## Utility macros

### `HSD_CONSTEXPR`
```c++
#if !defined(HSD_NOT_SUPPORTS_CONSTEXPR)
#define HSD_CONSTEXPR constexpr
#else
#define HSD_CONSTEXPR
#endif
```

Originally made to handle cases where constant-expression memory-allocating types & functions had conditional support in compilers. There is some cleanup needed to fulfill this premise in the library, and possibly a name change.
