
//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.h                                //
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

#ifndef __CorePuzzle15_include_GameCore_h__
#define __CorePuzzle15_include_GameCore_h__

//std
#include <string>
#include <vector>
//CorePuzzle15
#include "CorePuzzle15_Utils.h"
//CoreCoord
#include "CoreCoord.h"
//CoreRandom
#include "CoreRandom.h"
//CoreGame
#include "CoreGame.h"


NS_COREPUZZLE15_BEGIN

class GameCore
{
    // Constants / Enums / Typedefs //
public:
    ///@brief
    ///     Meta-value to indicate that
    ///     Game doesn't enforce a amount of tries.
    static const int kUnlimitedMoves;


    static const int kEmptyValue;

    ///@brief just to reduce verbosity.
    typedef std::vector<std::vector<int>> Board;

    // Inner Types //
public:
    struct MoveResult
    {
        //Types
        enum class Direction {
            Up,
            Down,
            Left,
            Right,
            None
        };

        //CTOR
        MoveResult() :
            moveDirection(Direction::None)
        {
            //Empty...
        }

        //Vars
        Direction             moveDirection;
        CoreCoord::Coord::Vec previousCoords;
        CoreCoord::Coord::Vec currentCoords;
    };


    // CTOR/DTOR //
public:
    ///@brief
    ///     Constructs the Game Core for Puzzle 15.
    ///@warning
    ///     The CTOR won't validate any parameters
    ///     is the caller responsibility to pass valid args.
    ///@param width
    ///     The width of Board - Must be > 0.
    ///@param height
    ///     The height of Board - Must be > 0.
    ///@param maxMoves
    ///     How many moves player is allowed to do.
    ///     Must be kUnlimitedMoves or > 0.
    ///     Default is kUnlimitedMoves.
    ///@param seed
    ///     The seed that will be used to seed the
    ///     random num generator.
    ///     Default is kRandomSeed.
    GameCore(int width,
             int height,
             int maxMoves = kUnlimitedMoves,
             int seed     = CoreRandom::Random::kRandomSeed);


    // Public Methods //
public:
    MoveResult move(const CoreCoord::Coord &coord);


    ///@brief   Gets the game Board.
    ///@returns Reference of the Board.
    ///@see getValueAt().
    const Board& getBoard() const;

    ///@brief Gets the value at CoreCoord::Coord.
    ///@param The desired CoreCoord::Coord.
    ///@warning This function will not validate the args.
    ///@returns Reference of the Board.
    int getValueAt(const CoreCoord::Coord &coord) const;


    ///@brief
    ///     Gets the game Status. Users should call
    ///     this function after each call of moveRow()
    ///     or moveCol().
    ///@returns The current game Status.
    ///@see CoreGame::Status, move();
    CoreGame::Status getStatus() const;


    ///@brief Gets how many moves player did so far.
    ///@returns The number of moves.
    ///@see getMaxMovesCount(), getRemainingMovesCount().
    int getMovesCount() const;

    ///@brief Gets how many moves player is allowed to do.
    ///@returns
    ///     The number of moves or kUnlimitedMoves if
    ///     there is no restriction on moves.
    ///@see getMovesCount(), getRemainingMovesCount().
    int getMaxMovesCount() const;

    ///@brief Gets how many moves player still can do.
    ///@returns
    ///     The number of moves or kUnlimitedMoves if
    ///     there is no restriction on moves.
    ///@see getMaxMovesCount(), getRemainingMovesCount().
    int getRemainingMovesCount() const;


    ///@brief Gets the width of Board.
    ///@returns The width of Board.
    ///@see getHeight().
    int getWidth() const;

    ///@brief Gets the height of Board.
    ///@returns The height of Board.
    ///@see getWidth().
    int getHeight() const;


    ///@brief
    ///     Gets the actual seed used by the
    ///     random number generator.
    ///@returns The actual seed.
    ///@see isUsingRandomSeed().
    int getSeed() const;

    ///@brief
    ///     Gets if random number generator is
    ///     using a random seed or one passed to it.
    ///@returns True if using random seed, false otherwise.
    ///@see getSeed().
    bool isUsingRandomSeed() const;

    ///@brief
    ///     Gets a string representation of Board.
    ///     Intended for debug only.
    std::string ascii() const;


    // Private Methods //
private:
    void initBoard(int width, int height);

    void checkStatus();
    bool valuesAreSorted();

    void swapValuesAt(const CoreCoord::Coord &coord1,
                      const CoreCoord::Coord &coord2);

    // iVars //
private:
    Board            m_board;
    CoreCoord::Coord m_emptyCoord;

    CoreGame::Status m_status;

    int m_movesCount;
    int m_maxMovesCount;

    CoreRandom::Random m_random;
};

NS_COREPUZZLE15_END
#endif // defined(__CorePuzzle15_include_GameCore_h__) //
