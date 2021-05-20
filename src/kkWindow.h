#ifndef KKWINDOW
#define KKWINDOW

#include "../includes/glog/logging.h"
#include "../includes/GLFW/glfw3.h" //<GLFW/glfw3.h>

class KKWindow
{
 private:
 void onResize(GLFWwindow*,int w,int h);

 public:
       KKWindow();
       ~KKWindow();
       void show();
       void close();
       
};

#endif
