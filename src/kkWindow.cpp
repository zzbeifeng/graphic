#include "kkWindow.h"

KKWindow::KKWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

KKWindow::~KKWindow(){

}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    // What to do
     LOG(INFO)<< "window_size_callback "<<width<<" "<<height;
}

void KKWindow::show(){
    LOG(INFO)<< "kkwindow show";
    // --------------------
    GLFWwindow* window = glfwCreateWindow(800, 600, "kkgraphic", NULL, NULL);
    if (window == NULL)
    {
        LOG(INFO)<< "Failed to create GLFW window";

        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window,window_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    // {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     return -1;
    // }    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
       // processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

void KKWindow::close(){

}

void KKWindow::onResize(GLFWwindow* window,int w,int h){

}