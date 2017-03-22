# libMmkFormat

MaulingMonKey's Format Macros.

Currently just provides MMK_FORMAT_TRUNC(name, length, format, ...) shorthand with all the warnings turned up.

License: [Apache 2.0](LICENSE.txt)

# Example

```c
#include <mmk/format.h> // MMK_FORMAT_TRUNC
#include <stdio.h>      // puts

int main() {
	const char* const name = "World";

	MMK_FORMAT_TRUNC(hello_world, 1024, "Hello, %s!", name);
	// Roughly equivalent to: char hello_world[1024] = "Hello, World!";

	puts(hello_world);
}

```

# Installation

Add [libMmkFormat](https://www.nuget.org/packages/libMmkFormat/) to your project via nuget.  Done!

Alternatively, clone and add [libMmkFormat/include/](libMmkFormat/include/) to your #include paths.
There is currently no source/.lib/.dll/.a/.so component to worry about.
There are no configuration options.

# Compatability

Supported compilers:
- MSVC 2005+
- GCC 3.0+
- Clang

Requirements:
- Variadic macro support (via C99, C++11, or compiler extension)

Other compilers likely work, although they may not generate appropriate warnings.

# TODO

- Public CI
- Support ICC
- 'nix friendly packaging?

# Why?

- Proof of concept for publishing native nuget packages via my local build chain.
- Need a C-friendly, non-error-prone formatting shorthand option for all my impending debug library shenannigans.
- Josh Wittner says "Always be Shipped", which is even better than "Always be Shipping"
