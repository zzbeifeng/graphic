
#ifndef __PLATFORM_MACROS_H__
#define __PLATFORM_MACROS_H__

// #include "../kernal/kkconsole.h"

/// @name namespace kkgraphic
/// @{

#include "stdio.h"

#ifdef __cplusplus
    #define NS_KK_BEGIN                     namespace kkgraphic {
    #define NS_KK_END                       }
    #define USING_NS_KK                    using namespace kkgraphic
    #define NS_KK                           ::kkgraphic
#else
    #define NS_CC_BEGIN 
    #define NS_CC_END 
    #define USING_NS_CC 
    #define NS_CC
#endif 
//  end of namespace group
/// @}

#define kklog(format,...)  printf("###kkgraphic" format,##__VA_ARGS__)

// #define kklog2(format,...) kkgraphic::log(format, ##__VA_ARGS__)

#ifndef KK_ASSERT
#if KKGRAPHIC_DEBUG > 0
    #if KK_ENABLE_SCRIPT_BINDING
    extern bool KK_DLL kk_assert_script_compatible(const char *msg);
    #define KKASSERT(cond, msg) do {                              \
          if (!(cond)) {                                          \
            if (!kk_assert_script_compatible(msg) && strlen(msg)) \
              kkgraphic::log("Assert failed: %s", msg);             \
            KK_ASSERT(cond);                                      \
          } \
        } while (0)
    #else
    #define KK_ASSERT(cond, msg) KK_ASSERT(cond)
    #endif
#else
    #define KK_ASSERT(cond, msg)
#endif

// FIXME:: Backward compatible
#define KKAssert KKASSERT
#endif  // CCASSERT


#endif