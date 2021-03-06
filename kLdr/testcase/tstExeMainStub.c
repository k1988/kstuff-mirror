/* $Id$ */
/** @file
 * kLdr testcase - DLL Stub.
 */

/*
 * Copyright (c) 2006-2007 Knut St. Osmundsen <bird-kStuff-spamix@anduin.net>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#include "tst.h"

#if K_OS == K_OS_OS2
# define INCL_BASE
# include <os2.h>

#elif K_OS == K_OS_WINDOWS
/* nothing */

#elif K_OS == K_OS_NT
# include <ddk/ntapi.h> /** @todo fix the nt port. */

#else
# error "port me"
#endif


extern int main();


#if K_OS == K_OS_OS2
/**
 * OS/2 'main'.
 */
ULONG _System OS2Main(HMODULE hmod, ULONG fFlag, ULONG ulReserved, PSZ pszzEnv, PSZ pszzCmdLine)
{
    int rc;
    rc = main();
    return rc;
}

#elif K_OS == K_OS_WINDOWS
/**
 * Windows'main'
 */
int WindowsMain(void)
{
    int rc;
    rc = main();
    return rc;
}

#elif K_OS == K_OS_NT
/**
 * Windows NT 'main'
 */
VOID NtProcess(HANDLE hDllHandle, DWORD dwReason, LPVOID lpReserved)
{
    int rc;
    rc = main();
    /* (no way around this) */
    for (;;)
        ZwTerminateProcess(NtCurrentProcess(), rc);
}

#else
# error "port me"
#endif


