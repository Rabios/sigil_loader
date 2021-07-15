# sigil_loader

[SIGIL](http://libsigil.com) Loader for C to use SIGIL with no compilation hassle!

### Usage

1. Download shared libs of SIGIL from [SIGIL Downloads](http://www.libsigil.com/#download) depending on your platform!
2. Download/Clone this repo or at least download the files as raw.
3. Write code and include `sl_loader.h` for loader and `sl.h` for API!

```c
#include "sl.h"
#include "sl_loader.h"

int main(int args, char *argv[]) {
    slLoadAPI("libsigil.dll");  // [LOADER] Load SIGIL from shared library!
  
    // set up our window and a few resources we need
    slWindow(400, 400, "Simple SIGIL Example", 0);
    slSetFont(slLoadFont("jura.ttf"), 24);
    slSetTextAlign(SL_ALIGN_CENTER);
  
    while(!slShouldClose() && !slGetKey(SL_KEY_ESCAPE)) {
        // background glow
        slSetForeColor(0.1, 0.9, 0.2, 0.4);
    
        // large text and fat line
        slSetForeColor(0.0, 0.8, 0.2, 1.0);
        slSetFontSize(24);
        slText(200, 250, "SIGIL:");
        slRectangleFill(200, 240, 100, 7);
    
        // smaller subtext
        slSetFontSize(14);
        slText(200, 220, "Sprites, text, sound, input, and more!");
        slLine(48, 210, 352, 210);
    
        slRender();     // draw everything
    }
  
    slClose();          // close the window and shut down SIGIL
    slUnloadAPI();      // [LOADER] Unload the library handle and functions
    
    return 0;
}
```

4. Compile for example via `gcc sl_loader.c helloworld.c -o helloworld` and run compiled executable, Have fun! :)

> NOTE: You could check `test` folder for the example.

### Loader API

This is following API provided with `sl_loader.h` and isn't releated to SIGIL but following his code style! :)

```c
void*   sl_lib;                             // [void]   The SIGIL shared library handle.
int     slLoadAPI(const char* libname);     // [int]    Load SIGIL from shared library path and assigns handle to sl_lib, Returns 0 on success or -1 on failure.
int     slUnloadAPI(void);                  // [int]    Unload SIGIL and returns 0 if success or -1 on failure.
```

### LICENSE

```
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
```
