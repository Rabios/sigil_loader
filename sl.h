/*
Sound, Input, and Graphics Integration Library (SIGIL) 0.9.0
Geoff Nagy
*/
#ifndef SL_H
#define SL_H

// text alignment symbolic constants
#define SL_ALIGN_CENTER 0
#define SL_ALIGN_RIGHT 1
#define SL_ALIGN_LEFT 2

// input key symbolic constants
#define SL_KEY_ESCAPE 256
#define SL_KEY_ENTER 257
#define SL_KEY_TAB 258
#define SL_KEY_BACKSPACE 259
#define SL_KEY_INSERT 260
#define SL_KEY_DELETE 261
#define SL_KEY_RIGHT 262
#define SL_KEY_LEFT 263
#define SL_KEY_DOWN 264
#define SL_KEY_UP 265
#define SL_KEY_PAGE_UP 266
#define SL_KEY_PAGE_DOWN 267
#define SL_KEY_HOME 268
#define SL_KEY_END 269
#define SL_KEY_CAPS_LOCK 280
#define SL_KEY_SCROLL_LOCK 281
#define SL_KEY_NUM_LOCK 282
#define SL_KEY_PRINT_SCREEN 283
#define SL_KEY_PAUSE 284
#define SL_KEY_F1 290
#define SL_KEY_F2 291
#define SL_KEY_F3 292
#define SL_KEY_F4 293
#define SL_KEY_F5 294
#define SL_KEY_F6 295
#define SL_KEY_F7 296
#define SL_KEY_F8 297
#define SL_KEY_F9 298
#define SL_KEY_F10 299
#define SL_KEY_F11 300
#define SL_KEY_F12 301
#define SL_KEY_F13 302
#define SL_KEY_F14 303
#define SL_KEY_F15 304
#define SL_KEY_F16 305
#define SL_KEY_F17 306
#define SL_KEY_F18 307
#define SL_KEY_F19 308
#define SL_KEY_F20 309
#define SL_KEY_F21 310
#define SL_KEY_F22 311
#define SL_KEY_F23 312
#define SL_KEY_F24 313
#define SL_KEY_F25 314
#define SL_KEY_KEYPAD_0 320
#define SL_KEY_KEYPAD_1 321
#define SL_KEY_KEYPAD_2 322
#define SL_KEY_KEYPAD_3 323
#define SL_KEY_KEYPAD_4 324
#define SL_KEY_KEYPAD_5 325
#define SL_KEY_KEYPAD_6 326
#define SL_KEY_KEYPAD_7 327
#define SL_KEY_KEYPAD_8 328
#define SL_KEY_KEYPAD_9 329
#define SL_KEY_KEYPAD_DECIMAL 330
#define SL_KEY_KEYPAD_DIVIDE 331
#define SL_KEY_KEYPAD_MULTIPLY 332
#define SL_KEY_KEYPAD_SUBTRACT 333
#define SL_KEY_KEYPAD_ADD 334
#define SL_KEY_KEYPAD_ENTER 335
#define SL_KEY_KEYPAD_EQUAL 336
#define SL_KEY_LEFT_SHIFT 340
#define SL_KEY_LEFT_CONTROL 341
#define SL_KEY_LEFT_ALT 342
#define SL_KEY_LEFT_SUPER 343
#define SL_KEY_RIGHT_SHIFT 344
#define SL_KEY_RIGHT_CONTROL 345
#define SL_KEY_RIGHT_ALT 346
#define SL_KEY_RIGHT_SUPER 347

// mouse input symbolic constants
#define SL_MOUSE_BUTTON_1 0
#define SL_MOUSE_BUTTON_2 1
#define SL_MOUSE_BUTTON_3 2
#define SL_MOUSE_BUTTON_4 3
#define SL_MOUSE_BUTTON_5 4
#define SL_MOUSE_BUTTON_6 5
#define SL_MOUSE_BUTTON_7 6
#define SL_MOUSE_BUTTON_8 7
#define SL_MOUSE_BUTTON_LEFT SL_MOUSE_BUTTON_1
#define SL_MOUSE_BUTTON_RIGHT SL_MOUSE_BUTTON_2
#define SL_MOUSE_BUTTON_MIDDLE SL_MOUSE_BUTTON_3

#ifdef __cplusplus
extern "C" {
#endif

// Functions
typedef void (*PFNSLWINDOWPROC) (int width, int height, const char *title, int fullScreen);
typedef void (*PFNSLSHOWCURSORPROC) (int showCursor);
typedef void (*PFNSLCLOSEPROC) ();
typedef int (*PFNSLSHOULDCLOSEPROC) ();
typedef int (*PFNSLGETKEYPROC) (int key);
typedef int (*PFNSLGETMOUSEBUTTONPROC) (int button);
typedef int (*PFNSLGETMOUSEXPROC) ();
typedef int (*PFNSLGETMOUSEYPROC) ();
typedef double (*PFNSLGETDELTATIMEPROC) ();
typedef double (*PFNSLGETTIMEPROC) ();
typedef void (*PFNSLRENDERPROC) ();
typedef void (*PFNSLSETBACKCOLORPROC) (double red, double green, double blue);
typedef void (*PFNSLSETFORECOLORPROC) (double red, double green, double blue, double alpha);
typedef void (*PFNSLSETADDITIVEBLENDPROC) (int additiveBlend);
typedef void (*PFNSLPUSHPROC) ();
typedef void (*PFNSLPOPPROC) ();
typedef void (*PFNSLTRANSLATEPROC) (double x, double y);
typedef void (*PFNSLROTATEPROC) (double degrees);
typedef void (*PFNSLSCALEPROC) (double x, double y);
typedef int (*PFNSLLOADTEXTUREPROC) (const char *filename);
typedef int (*PFNSLLOADWAVPROC) (const char *filename);
typedef int (*PFNSLSOUNDPLAYPROC) (int sound);
typedef int (*PFNSLSOUNDLOOPPROC) (int sound);
typedef void (*PFNSLSOUNDPAUSEPROC) (int sound);
typedef void (*PFNSLSOUNDSTOPPROC) (int sound);
typedef void (*PFNSLSOUNDPAUSEALLPROC) ();
typedef void (*PFNSLSOUNDRESUMEALLPROC) ();
typedef void (*PFNSLSOUNDSTOPALLPROC) ();
typedef int (*PFNSLSOUNDPLAYINGPROC) (int sound);
typedef int (*PFNSLSOUNDLOOPINGPROC) (int sound);
typedef void (*PFNSLTRIANGLEFILLPROC) (double x, double y, double width, double height);
typedef void (*PFNSLTRIANGLEOUTLINEPROC) (double x, double y, double width, double height);
typedef void (*PFNSLRECTANGLEFILLPROC) (double x, double y, double width, double height);
typedef void (*PFNSLRECTANGLEOUTLINEPROC) (double x, double y, double width, double height);
typedef void (*PFNSLCIRCLEFILLPROC) (double x, double y, double radius, int numVertices);
typedef void (*PFNSLCIRCLEOUTLINEPROC) (double x, double y, double radius, int numVertices);
typedef void (*PFNSLSEMICIRCLEFILLPROC) (double x, double y, double radius, int numVertices, double degrees);
typedef void (*PFNSLSEMICIRCLEOUTLINEPROC) (double x, double y, double radius, int numVertices, double degrees);
typedef void (*PFNSLPOINTPROC) (double x, double y);
typedef void (*PFNSLLINEPROC) (double x1, double y1, double x2, double y2);
typedef void (*PFNSLSETSPRITETILINGPROC) (double x, double y);
typedef void (*PFNSLSETSPRITESCROLLPROC) (double x, double y);
typedef void (*PFNSLSPRITEPROC) (int texture, double x, double y, double width, double height);
typedef void (*PFNSLSETTEXTALIGNPROC) (int fontAlign);
typedef double (*PFNSLGETTEXTWIDTHPROC) (const char *text);
typedef double (*PFNSLGETTEXTHEIGHTPROC) (const char *text);
typedef int (*PFNSLLOADFONTPROC) (const char *fontFilename);
typedef void (*PFNSLSETFONTPROC) (int font, int fontSize);
typedef void (*PFNSLSETFONTSIZEPROC) (int fontSize);
typedef void (*PFNSLTEXTPROC) (double x, double y, const char *text);

PFNSLWINDOWPROC slWindow;
PFNSLSHOWCURSORPROC slShowCursor;
PFNSLCLOSEPROC slClose;
PFNSLSHOULDCLOSEPROC slShouldClose;
PFNSLGETKEYPROC slGetKey;
PFNSLGETMOUSEBUTTONPROC slGetMouseButton;
PFNSLGETMOUSEXPROC slGetMouseX;
PFNSLGETMOUSEYPROC slGetMouseY;
PFNSLGETDELTATIMEPROC slGetDeltaTime;
PFNSLGETTIMEPROC slGetTime;
PFNSLRENDERPROC slRender;
PFNSLSETBACKCOLORPROC slSetBackColor;
PFNSLSETFORECOLORPROC slSetForeColor;
PFNSLSETADDITIVEBLENDPROC slSetAdditiveBlend;
PFNSLPUSHPROC slPush;
PFNSLPOPPROC slPop;
PFNSLTRANSLATEPROC slTranslate;
PFNSLROTATEPROC slRotate;
PFNSLSCALEPROC slScale;
PFNSLLOADTEXTUREPROC slLoadTexture;
PFNSLLOADWAVPROC slLoadWAV;
PFNSLSOUNDPLAYPROC slSoundPlay;
PFNSLSOUNDLOOPPROC slSoundLoop;
PFNSLSOUNDPAUSEPROC slSoundPause;
PFNSLSOUNDSTOPPROC slSoundStop;
PFNSLSOUNDPAUSEALLPROC slSoundPauseAll;
PFNSLSOUNDRESUMEALLPROC slSoundResumeAll;
PFNSLSOUNDSTOPALLPROC slSoundStopAll;
PFNSLSOUNDPLAYINGPROC slSoundPlaying;
PFNSLSOUNDLOOPINGPROC slSoundLooping;
PFNSLTRIANGLEFILLPROC slTriangleFill;
PFNSLTRIANGLEOUTLINEPROC slTriangleOutline;
PFNSLRECTANGLEFILLPROC slRectangleFill;
PFNSLRECTANGLEOUTLINEPROC slRectangleOutline;
PFNSLCIRCLEFILLPROC slCircleFill;
PFNSLCIRCLEOUTLINEPROC slCircleOutline;
PFNSLSEMICIRCLEFILLPROC slSemiCircleFill;
PFNSLSEMICIRCLEOUTLINEPROC slSemiCircleOutline;
PFNSLPOINTPROC slPoint;
PFNSLLINEPROC slLine;
PFNSLSETSPRITETILINGPROC slSetSpriteTiling;
PFNSLSETSPRITESCROLLPROC slSetSpriteScroll;
PFNSLSPRITEPROC slSprite;
PFNSLSETTEXTALIGNPROC slSetTextAlign;
PFNSLGETTEXTWIDTHPROC slGetTextWidth;
PFNSLGETTEXTHEIGHTPROC slGetTextHeight;
PFNSLLOADFONTPROC slLoadFont;
PFNSLSETFONTPROC slSetFont;
PFNSLSETFONTSIZEPROC slSetFontSize;
PFNSLTEXTPROC slText;

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif
