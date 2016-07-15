//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        CorePuzzle15_Utils.h                      //
//            █ █        █ █        CorePuzzle15                              //
//             ████████████                                                   //
//           █              █       Copyright (c) 2016                        //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CorePuzzle15_include_CorePuzzle15_Utils_h__
#define __CorePuzzle15_include_CorePuzzle15_Utils_h__

//All classes of this core is placed inside this namespace.
//We use MACROS so is easier to change if needed.
//Is (in our opinion) more explicit.
//And finally the editors will not reformat the code.

#define NS_COREPUZZLE15_BEGIN namespace CorePuzzle15 {
#define NS_COREPUZZLE15_END   }
#define USING_NS_COREPUZZLE15 using namespace CorePuzzle15

//The core version number.
#define COW_COREPUZZLE15_VERSION_MAJOR    "0"
#define COW_COREPUZZLE15_VERSION_MINOR    "1"
#define COW_COREPUZZLE15_VERSION_REVISION "1"

#define COW_COREPUZZLE15_VERSION       \
    COW_COREPUZZLE15_VERSION_MAJOR "." \
    COW_COREPUZZLE15_VERSION_MINOR "." \
    COW_COREPUZZLE15_VERSION_REVISION

#endif // defined(__CorePuzzle15_include_CorePuzzle15_Utils_h__) //
