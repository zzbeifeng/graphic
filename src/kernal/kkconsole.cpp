#include "kkconsole.h"

#include <thread>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

NS_KK_BEGIN

void log(const char * format, ...)
{
    int bufferSize = MAX_LOG_LENGTH;
    char* buf = nullptr;
    int nret = 0;
    va_list args;
    do
    {
        buf = new (std::nothrow) char[bufferSize];
        if (buf == nullptr)
            return;
        /*
        pitfall: The behavior of vsnprintf between VS2013 and VS2015/2017 is different
        VS2013 or Unix-Like System will return -1 when buffer not enough, but VS2015/2017 will return the actural needed length for buffer at this station
        The _vsnprintf behavior is compatible API which always return -1 when buffer isn't enough at VS2013/2015/2017
        Yes, The vsnprintf is more efficient implemented by MSVC 19.0 or later, AND it's also standard-compliant, see reference: http://www.cplusplus.com/reference/cstdio/vsnprintf/
        */
        va_start(args, format);
        nret = vsnprintf(buf, bufferSize - 3, format, args);
        va_end(args);

        if (nret >= 0)
        { // VS2015/2017
            if (nret <= bufferSize - 3)
            {// success, so don't need to realloc
                break;
            }
            else
            {
                bufferSize = nret + 3;
                delete[] buf;
            }
        }
        else // < 0
        {	// VS2013 or Unix-like System(GCC)
            bufferSize *= 2;
            delete[] buf;
        }
    } while (true);
    buf[nret] = '\n';
    buf[++nret] = '\0';

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    

#elif CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32

    int pos = 0;
    int len = nret;
    char tempBuf[MAX_LOG_LENGTH + 1] = { 0 };
    WCHAR wszBuf[MAX_LOG_LENGTH + 1] = { 0 };

    do
    {
        std::copy(buf + pos, buf + pos + MAX_LOG_LENGTH, tempBuf);

        tempBuf[MAX_LOG_LENGTH] = 0;

        MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
        OutputDebugStringW(wszBuf);
        WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
        printf("%s", tempBuf);

        pos += MAX_LOG_LENGTH;

    } while (pos < len);
    SendLogToWindow(buf);
    fflush(stdout);
#else
   
#endif

#if TEST_DEBUG
    fprintf(stdout, "debug %s", buf);
    fflush(stdout);
#endif

    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);

    delete[] buf;
}

kkconsole::kkconsole(/* args */)
{
    kkgraphic::log("log %d",2);
}

kkconsole::~kkconsole()
{
}


NS_KK_END
