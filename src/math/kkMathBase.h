#ifdef __cplusplus
    #define NS_KK_MATH_BEGIN                     namespace kkgraphic {
    #define NS_KK_MATH_END                       }
    #define USING_NS_KK_MATH                     using namespace kkgraphic
#else
    #define NS_KK_MATH_BEGIN 
    #define NS_KK_MATH_END 
    #define USING_NS_KK_MATH 
#endif

/**Util macro for conversion from degrees to radians.*/
#define MATH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
/**Util macro for conversion from radians to degrees.*/
#define MATH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
/**
@{ Util macro for const float such as epsilon, small float and float precision tolerance.
*/
#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_PIOVER2                1.57079632679489661923f
#define MATH_EPSILON                0.000001f