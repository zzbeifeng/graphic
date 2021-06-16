#include "kkApplication.h"

USING_NS_KK;

kkApplication::kkApplication()
{
    google::InitGoogleLogging("kkgraphic");
    fLS::FLAGS_log_dir = "./";
    FLAGS_v = 2;
}

kkApplication::~kkApplication()
{
}

void kkApplication::init(){
 
    LOG(INFO) << "init";
     
    kklog("Test %d \n",20);

    window.show();

}

void kkApplication::unInit(){

}

void kkApplication::beforeInit()
{

}

void kkApplication::beforeUnInit(){

}

