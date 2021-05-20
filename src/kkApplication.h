#ifndef KK_APPLICATION
#define KK_APPLICATION

#include "../includes/glog/logging.h"
#include "kkWindow.h"

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

#endif