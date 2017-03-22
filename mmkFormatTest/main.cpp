/* Copyright 2017 MaulingMonkey

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/* NOTE: Keep Readme.md in sync if modifying this file (assuming this example is still there.) */

#include <mmk/format.h> // MMK_FORMAT_TRUNC
#include <stdio.h>      // puts

int main() {
	const char* const name = "World";

	MMK_FORMAT_TRUNC(hello_world, 1024, "Hello, %s!", name);
	// Roughly equivalent to: char hello_world[1024] = "Hello, World!";

	puts(hello_world);
}
