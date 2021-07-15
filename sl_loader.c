#include "sl.h"
#include "sl_loader.h"

#if defined(__WIN) || defined(_WIN32_) || defined(_WIN64_) || defined(WIN32) || defined(__WIN32__) || defined(WIN64) || defined(__WIN64__) || defined(WINDOWS) || defined(_WINDOWS) || defined(__WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(_MSC_VER) || defined(__WINDOWS__) || defined(_X360) || defined(XBOX360) || defined(__X360) || defined(__X360__) || defined(_XBOXONE) || defined(XBONE) || defined(XBOX) || defined(__XBOX__) || defined(__XBOX) || defined(__xbox__) || defined(__xbox) || defined(_XBOX) || defined(xbox) || ((defined(_XBOX_ONE) || defined(_DURANGO)) && defined(_TITLE))
#  define SL_MICROSOFT
#  include <windows.h>
#elif defined(__HAIKU) || defined(__HAIKU__) || defined(_HAIKU) || defined(__BeOS) || defined(__BEOS__) || defined(_BEOS)
#  define SL_BEOS
#  include <image.h>
#else
#  define SL_UNIX
#  include <dlfcn.h>
#endif

extern void* sl_lib;

void* slLoadLibrary(const char* name) {
#ifdef SL_MICROSOFT
    return (HMODULE) LoadLibraryA(name);
#elif SL_BEOS
    return (image_id) load_add_on(name);
#elif SL_UNIX
    return dlopen(name, RTLD_LAZY | RTLD_GLOBAL);
#endif
}

void* slGetProc(const char* addrname) {
#ifdef SL_MICROSOFT
    return GetProcAddress((HMODULE) sl_lib, addrname);
#elif SL_BEOS
    void* addr;

    if (get_image_symbol((image_id) sl_lib, addrname, B_SYMBOL_TYPE_ANY, &addr) == B_OK) {
        return addr;
    }
#elif SL_UNIX
    return dlsym(sl_lib, addrname);
#endif 
}

int slLoadAPI(const char* libname) {
    sl_lib = slLoadLibrary(libname);
    
    if (sl_lib == NULL) {
        return -1;
    }
    
    slWindow            = (PFNSLWINDOWPROC) slGetProc("slWindow");
    slShowCursor        = (PFNSLSHOWCURSORPROC) slGetProc("slShowCursor");
    slClose             = (PFNSLCLOSEPROC) slGetProc("slClose");
    slShouldClose       = (PFNSLSHOULDCLOSEPROC) slGetProc("slShouldClose");
    slGetKey            = (PFNSLGETKEYPROC) slGetProc("slGetKey");
    slGetMouseButton    = (PFNSLGETMOUSEBUTTONPROC) slGetProc("slGetMouseButton");
    slGetMouseX         = (PFNSLGETMOUSEXPROC) slGetProc("slGetMouseX");
    slGetMouseY         = (PFNSLGETMOUSEYPROC) slGetProc("slGetMouseY");
    slGetDeltaTime      = (PFNSLGETDELTATIMEPROC) slGetProc("slGetDeltaTime");
    slGetTime           = (PFNSLGETTIMEPROC) slGetProc("slGetTime");
    slRender            = (PFNSLRENDERPROC) slGetProc("slRender");
    slSetBackColor      = (PFNSLSETBACKCOLORPROC) slGetProc("slSetBackColor");
    slSetForeColor      = (PFNSLSETFORECOLORPROC) slGetProc("slSetForeColor");
    slSetAdditiveBlend  = (PFNSLSETADDITIVEBLENDPROC) slGetProc("slSetAdditiveBlend");
    slPush              = (PFNSLPUSHPROC) slGetProc("slPush");
    slPop               = (PFNSLPOPPROC) slGetProc("slPop");
    slTranslate         = (PFNSLTRANSLATEPROC) slGetProc("slTranslate");
    slRotate            = (PFNSLROTATEPROC) slGetProc("slRotate");
    slScale             = (PFNSLSCALEPROC) slGetProc("slScale");
    slLoadTexture       = (PFNSLLOADTEXTUREPROC) slGetProc("slLoadTexture");
    slLoadWAV           = (PFNSLLOADWAVPROC) slGetProc("slLoadWAV");
    slSoundPlay         = (PFNSLSOUNDPLAYPROC) slGetProc("slSoundPlay");
    slSoundLoop         = (PFNSLSOUNDLOOPPROC) slGetProc("slSoundLoop");
    slSoundPause        = (PFNSLSOUNDPAUSEPROC) slGetProc("slSoundPause");
    slSoundStop         = (PFNSLSOUNDSTOPPROC) slGetProc("slSoundStop");
    slSoundPauseAll     = (PFNSLSOUNDPAUSEALLPROC) slGetProc("slSoundPauseAll");
    slSoundResumeAll    = (PFNSLSOUNDRESUMEALLPROC) slGetProc("slSoundResumeAll");
    slSoundStopAll      = (PFNSLSOUNDSTOPALLPROC) slGetProc("slSoundStopAll");
    slSoundPlaying      = (PFNSLSOUNDPLAYINGPROC) slGetProc("slSoundPlaying");
    slSoundLooping      = (PFNSLSOUNDLOOPINGPROC) slGetProc("slSoundLooping");
    slTriangleFill      = (PFNSLTRIANGLEFILLPROC) slGetProc("slTriangleFill");
    slTriangleOutline   = (PFNSLTRIANGLEOUTLINEPROC) slGetProc("slTriangleOutline");
    slRectangleFill     = (PFNSLRECTANGLEFILLPROC) slGetProc("slRectangleFill");
    slRectangleOutline  = (PFNSLRECTANGLEOUTLINEPROC) slGetProc("slRectangleOutline");
    slCircleFill        = (PFNSLCIRCLEFILLPROC) slGetProc("slCircleFill");
    slCircleOutline     = (PFNSLCIRCLEOUTLINEPROC) slGetProc("slCircleOutline");
    slSemiCircleFill    = (PFNSLSEMICIRCLEFILLPROC) slGetProc("slSemiCircleFill");
    slSemiCircleOutline = (PFNSLSEMICIRCLEOUTLINEPROC) slGetProc("slSemiCircleOutline");
    slPoint             = (PFNSLPOINTPROC) slGetProc("slPoint");
    slLine              = (PFNSLLINEPROC) slGetProc("slLine");
    slSetSpriteTiling   = (PFNSLSETSPRITETILINGPROC) slGetProc("slSetSpriteTiling");
    slSetSpriteScroll   = (PFNSLSETSPRITESCROLLPROC) slGetProc("slSetSpriteScroll");
    slSprite            = (PFNSLSPRITEPROC) slGetProc("slSprite");
    slSetTextAlign      = (PFNSLSETTEXTALIGNPROC) slGetProc("slSetTextAlign");
    slGetTextWidth      = (PFNSLGETTEXTWIDTHPROC) slGetProc("slGetTextWidth");
    slGetTextHeight     = (PFNSLGETTEXTHEIGHTPROC) slGetProc("slGetTextHeight");
    slLoadFont          = (PFNSLLOADFONTPROC) slGetProc("slLoadFont");
    slSetFont           = (PFNSLSETFONTPROC) slGetProc("slSetFont");
    slSetFontSize       = (PFNSLSETFONTSIZEPROC) slGetProc("slSetFontSize");
    slText              = (PFNSLTEXTPROC) slGetProc("slText");
    
    return 0;
}

int slUnloadAPI(void) {
    slWindow            = NULL;
    slShowCursor        = NULL;
    slClose             = NULL;
    slShouldClose       = NULL;
    slGetKey            = NULL;
    slGetMouseButton    = NULL;
    slGetMouseX         = NULL;
    slGetMouseY         = NULL;
    slGetDeltaTime      = NULL;
    slGetTime           = NULL;
    slRender            = NULL;
    slSetBackColor      = NULL;
    slSetForeColor      = NULL;
    slSetAdditiveBlend  = NULL;
    slPush              = NULL;
    slPop               = NULL;
    slTranslate         = NULL;
    slRotate            = NULL;
    slScale             = NULL;
    slLoadTexture       = NULL;
    slLoadWAV           = NULL;
    slSoundPlay         = NULL;
    slSoundLoop         = NULL;
    slSoundPause        = NULL;
    slSoundStop         = NULL;
    slSoundPauseAll     = NULL;
    slSoundResumeAll    = NULL;
    slSoundStopAll      = NULL;
    slSoundPlaying      = NULL;
    slSoundLooping      = NULL;
    slTriangleFill      = NULL;
    slTriangleOutline   = NULL;
    slRectangleFill     = NULL;
    slRectangleOutline  = NULL;
    slCircleFill        = NULL;
    slCircleOutline     = NULL;
    slSemiCircleFill    = NULL;
    slSemiCircleOutline = NULL;
    slPoint             = NULL;
    slLine              = NULL;
    slSetSpriteTiling   = NULL;
    slSetSpriteScroll   = NULL;
    slSprite            = NULL;
    slSetTextAlign      = NULL;
    slGetTextWidth      = NULL;
    slGetTextHeight     = NULL;
    slLoadFont          = NULL;
    slSetFont           = NULL;
    slSetFontSize       = NULL;
    slText              = NULL;
    
#ifdef SL_MICROSOFT
    return (FreeLibrary((HMODULE) sl_lib) == TRUE) ? 0 : -1;
#elif SL_BEOS
    return (unload_add_on((image_id) sl_lib) == B_OK) ? 0 : -1;
#elif SL_UNIX
    return (dlclose(sl_lib) == 0) ? 0 : -1;
#endif
}
