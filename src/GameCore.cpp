//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.cpp                              //
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

//Header
#include "../include/GameCore.h"
//std
#include <algorithm>
#include <sstream>

//Usings
USING_NS_COREPUZZLE15;


// Constants / Enums / Typedefs //
const int GameCore::kUnlimitedMoves = -1;
const int GameCore::kEmptyValue     = 0;


// CTOR/DTOR //
GameCore::GameCore(int width, int height, int maxMoves, int seed) :
    //m_board - Init in initBoard().
    m_emptyCoord   (-1, -1),
    m_status       (CoreGame::Status::Continue),
    m_movesCount   (0),
    m_maxMovesCount(maxMoves),
    m_random       (seed)
{
    initBoard(width, height);
}


// Public Methods //
GameCore::MoveResult GameCore::move(const CoreCoord::Coord &coord)
{
    MoveResult result;

    //Game is already over - Don't do anything...
    if(m_status != CoreGame::Status::Continue)
        return result;

    //Coord is the empty coord - Don't do anything...
    if(m_emptyCoord == coord)
        return result;

    //Coord isn't at same row or col from the empty coord.
    //Cannot move - Don't do anything...
    if(!m_emptyCoord.isSameX(coord) && m_emptyCoord.isSameY(coord))
        return result;

    //Set Increment coord.
    auto incrCoord = (coord.x < m_emptyCoord.x) ? CoreCoord::Coord::Left () :
                     (coord.x > m_emptyCoord.x) ? CoreCoord::Coord::Right() :
                     (coord.y < m_emptyCoord.y) ? CoreCoord::Coord::Up   () :
                   /*(coord.y > m_emptyCoord.y)*/ CoreCoord::Coord::Down ();


}

const GameCore::Board& GameCore::getBoard() const
{
    return m_board;
}

int GameCore::getValueAt(const CoreCoord::Coord &coord) const
{
    return m_board[coord.y][coord.x];
}


CoreGame::Status GameCore::getStatus() const
{
    return m_status;
}


int GameCore::getMovesCount() const
{
    return m_movesCount;
}

int GameCore::getMaxMovesCount() const
{
    return m_maxMovesCount;
}

int GameCore::getRemainingMovesCount() const
{
    if(m_maxMovesCount == GameCore::kUnlimitedMoves)
        return GameCore::kUnlimitedMoves;

    return m_maxMovesCount - m_movesCount;
}


int GameCore::getWidth() const
{
    return m_board[0].size();
}

int GameCore::getHeight() const
{
    return m_board.size();
}


int GameCore::getSeed() const
{
    return m_random.getSeed();
}

bool GameCore::isUsingRandomSeed() const
{
    return m_random.isUsingRandomSeed();
}


std::string GameCore::ascii() const
{
    std::stringstream ss;

    for(const auto &line : m_board)
    {
        for(const auto &value : line)
            ss << value << " ";
        ss << std::endl;
    };

    return ss.str();
}

// Private Methods //
void GameCore::initBoard(int width, int height)
{
    //Init a temp vector with all values.
    std::vector<int> tmp(width * height);
    std::iota(std::begin(tmp), std::end(tmp), 0);

    //Shuffle the temp vector.
    std::shuffle(std::begin(tmp), std::end(tmp),
                 m_random.getNumberGenerator());


    //Add the values into the board.
    m_board.reserve(height);
    for(int i = 0; i < height; ++i)
    {
        m_board.push_back(std::vector<int>(width));
        std::copy_n(std::begin(tmp) + i * width,
                    width,
                    std::begin(m_board[i]));

        //Try find the kEmptyValue in this row...
        //If it was found update the emptyCoord
        //i.e that coord will contain the kEmptyValue at start.
        if(m_emptyCoord.y != -1 && m_emptyCoord.x != -1)
        {
            auto it = std::find(std::begin(m_board[i]),
                                std::end  (m_board[i]),
                                kEmptyValue);

            if(it != std::end(m_board[i]))
            {
                m_emptyCoord.y = i;
                m_emptyCoord.x = std::begin(m_board[0]) - it;
            }
        }
    }//for(int i = 0; i < height; ++i)
}

void GameCore::checkStatus()
{
    //Player sort all values - Game Won
    if(valuesAreSorted())
    {
        m_status = CoreGame::Status::Victory;
        return;
    }

    //Values aren't sorted, check if player
    //reach the max moves allowed.
    if(getRemainingMovesCount() == 0)
    {
        m_status = CoreGame::Status::Defeat;
    }
}

bool GameCore::valuesAreSorted()
{
    //
    if(m_board[getHeight() -1][getWidth() -1] ==  kEmptyValue)
        return false;

    //Check if all values are sorted.
    int prevValue = -1;
    int sorted    = true;

    for(int i = 0; i < getHeight(); ++i)
    {
        for(int j = 0; j < getWidth(); ++j)
        {
            //Last value must be the kEmptyValue.
            if(i == getHeight() -1 && j == getWidth() -1)
                return true;

            int value = m_board[i][j];
            if(prevValue > value)
                return false;

            prevValue = value;
        }
    }

    return true;
}
