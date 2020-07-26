#include "Board.hpp"
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace WarGame;


    // operator for putting soldiers on the game-board during initialization.
    Soldier*& Board::operator[](std::pair<int,int> location){
      if(location.first<0||location.second<0||location.first>=rows||location.second>=cols)throw "";
       return board[location.first][location.second];
    }
    
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
    }
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
      if(board[source.first][source.second]==nullptr)throw "";
      std::cout<<direction<<" "<<direction/10;
      int r=source.first+(direction/10);
      int c=source.second+(direction%10);
      if(c<0||r<0||r>=rows||c>=cols)throw "";
      board[r][c]=board[source.first][source.second];
      board[source.first][source.second]=nullptr;
      if(board[r][c]->act=="near"){
        auto sol=find_near(r,c,board[r][c]->target);
        sol->health+=board[r][c]->demge;
        if(sol->health<=0)sol=nullptr;
        else sol->health=std::min(sol->health,sol->max_helth);
      }
      if(board[r][c]->act=="cnear"){
        // command(player_number,"near",board[r][c]->target);
        int i,j;
        for(i=0;i<rows;i++){
          for(j=0;j<cols;j++){
            if(board[i][j]==nullptr||board[r][c]->player!=board[i][j]->player||board[r][c]->player!=board[i][j]->player||("near"!=board[i][j]->act&&"cnear"!=board[i][j]->act))continue;
            find_near(i,j,board[r][c]->target);
            
          }
        }
        for(auto row:board){
          for(auto sol:row){
             if(sol==nullptr)continue;
             if(sol->health<=0)sol=nullptr;
             else sol->health=std::min(sol->health,sol->max_helth);

          }
        }

      }
    // void Board::command(int player,std)


    }
    Soldier* Board::find_near(int r,int c,int player){
      double dist,min=INFINITY;
      Soldier* sol=nullptr;
      int i,j;
      for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
          if(board[i][j]==nullptr||board[i][j]->player!=player)continue;
          dist=sqrt(pow(r+i,2)+pow(c+j,2));
          if(dist< min&&dist!=0){
            min=dist;
            sol=board[i][j];
          }
        }
      }
      return sol;
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const{
      for(auto row:board){
        if(std::any_of(row.begin(), row.end(), [player_number](Soldier* i){return i!=nullptr&& i->player==player_number;}))return true;
      }
      return false;
    }
