#ifndef SL_LOADER_H
#define SL_LOADER_H

#ifdef __cplusplus
extern "C" {
#endif

void*   sl_lib;
void*   slLoadLibrary(const char* name);
void*   slGetProc(const char* addrname);
int     slLoadAPI(const char* libname);
int     slUnloadAPI(void);

#ifdef __cplusplus
} // closing brace for extern "C"
#endif

#endif
