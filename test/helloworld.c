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
