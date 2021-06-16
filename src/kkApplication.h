#ifndef KK_APPLICATION
#define KK_APPLICATION

#include "../includes/glog/logging.h"
#include "kkWindow.h"
#include "platform/kkPlatformMacors.h"


NS_KK_BEGIN

class kkApplication
{
private:
   KKWindow window;
   void beforeInit();
   void beforeUnInit();
public:
    kkApplication();
    ~kkApplication();
    void init();
    void unInit();
};

NS_KK_END

#endif