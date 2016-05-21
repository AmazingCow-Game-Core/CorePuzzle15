//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        main.cpp                                  //
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


//This guard is to ease the usage of the Puzzle15Core,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_COREPUZZLE15_TEST_ENABLED__

#include <cstdlib>
#include <iostream>
#include <vector>
#include "../include/CorePuzzle15.h"

USING_NS_COREPUZZLE15;
using namespace std;


void usage()
{
    cout << "Amazing Cow - CorePuzzle15 Test Game" << endl;
    cout << "Usage: " << endl;
    cout << "   testgame <width> <height> <max moves> <seed>" << endl;
    cout << "Example: " << endl;
    cout << "   testgame      4        4           -1     -1" << endl;
    cout << "   testgame      4        4           10    123" << endl;

    exit(1);
}

int main(int argc, const char *argv[])
{
    if(argc != 5)
        usage();

    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int m = atoi(argv[3]);
    int s = atoi(argv[4]);

    GameCore core(w, h, m, s);

    while(core.getStatus() == CoreGame::Status::Continue)
    {
        cout << endl;
        cout << core.ascii() << endl;
        cout << "Max Moves:      : " << core.getMaxMovesCount()       << endl;
        cout << "Moves Count     : " << core.getMovesCount()          << endl;
        cout << "Remaining Moves : " << core.getRemainingMovesCount() << endl;
        cout << "Seed            : " << core.getSeed()                << endl;
        cout << "Random seed     : " << core.isUsingRandomSeed()      << endl;
        cout << "Empty Coord     :"  << core.getEmptyValueCoord()     << endl;

        cout << endl;

        CoreCoord::Coord coord;
        cin >> coord.y >> coord.x;

        core.move(coord);

    }
    cout << "End status: " << core.getStatus() << endl;
}

#endif // __AMAZINGCORE_MEMORYCORE_TEST_ENABLED__ //
