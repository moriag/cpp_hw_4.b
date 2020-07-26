/**
 * Header file for the board of the war game.
 * 
 * You can copy this file to a new file called Board.hpp, and extend it as you like.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"


namespace WarGame {

class Board {
  private:
    std::vector<std::vector<Soldier*>> board;
    int rows,cols;
    
  public:
    enum MoveDIR { Up=-10, Down=10, Right=1, Left=-1 };
    
    Board(uint numRows, uint numCols) : rows(numRows),cols(numCols),
      board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}
    ~Board(){}
    Soldier*& operator[](std::pair<int,int> location);
    Soldier* operator[](std::pair<int,int> location) const;
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction);
    bool has_soldiers(uint player_number) const;
    Soldier* find_near(int r,int c, int player);
};

}
