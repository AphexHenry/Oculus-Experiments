////
////  Tools.h
////  OculusFMOD
////
////  Created by Baptiste Bohelay on 10/08/2015.
////
////
//
//#ifndef __OculusFMOD__Tools__
//#define __OculusFMOD__Tools__
//
//#include <stdio.h>
//#include <functional>
//#include <iostream>
//#include <utility>
//
//using namespace std;
//
////namespace bat {
//    template<typename Obj, typename Result, typename ...Args>
//    struct Delegate
//    {
//        Obj x;
//        Result (Obj::*f)(Args...);
//        
//        template<typename ...Ts>
//        Result operator()(Ts&&... args)
//        {
//            return (x.*f)(forward<Ts>(args)...);
//        }
//    };
//    
//    template<typename Obj, typename Result, typename ...Args>
//    auto make_delegate(const Obj &x, Result (Obj::*fun)(Args...))
//    -> Delegate<Obj, Result, Args...>
//    {
//        Delegate<Obj, Result, Args...> result{x, fun};
//        return result;
//    }
////};
//
//
//
//#endif /* defined(__OculusFMOD__Tools__) */
