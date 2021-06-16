#ifndef KK_CONSOLE
#define KK_CONSOLE

#include "../platform/kkPlatformMacors.h"

NS_KK_BEGIN

/// The max length of CCLog message.
static const int MAX_LOG_LENGTH = 16*1024;

/**
 @brief Output Debug message.
 */
void log(const char * format, ...);

class kkconsole
{
private:
    /* data */
public:
    kkconsole(/* args */);
    ~kkconsole();
};

NS_KK_END

#endif