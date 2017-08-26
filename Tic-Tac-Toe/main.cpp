//
//  main.cpp
//  exercise
//
//  Created by Fangyuan Xing on 8/24/17.
//  Copyright © 2017 Fangyuan Xing. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TicTacToe
{
public:
    
    TicTacToe() : board(3, vector<char>(3, '-')), row(3, 0), col(3, 0), diag(0), anti_diag(0), winner(0)
    {
        drawBoard();
    }
    
    // start game
    void play()
    {
        while(!isfull() && !winner)
        {
            readPosition();
            drawBoard();
            
            if(winner == 1)
            {
                cout << "you win" << endl;
                break;
            }
            
            cout << "computer move" << endl;
            getO();
            drawBoard();
            
            if(winner == 2)
            {
                cout << "you lose" << endl;
                break;
            }
            
            
        }
    }
    
private:
    vector<vector<char>> board;
    vector<int> row;
    vector<int> col;
    int diag;
    int anti_diag;
    int winner;
    
    // draw board
    void drawBoard()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << board[i][j];
                if(j < 2)
                {
                    cout << '|';
                }
            }
            cout << endl;
        }
    }
    
    // one move
    void move(int x, int y, char c)
    {
        board[x][y] = c;
        isWinner(x, y, c);
    }
    
    
    // chech if board is full
    bool isfull()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == '-')
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // computer move
    void getO()
    {
        if(isfull())
        {
            throw "not able to put O";
        }
        
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == '-')
                {
                    move(i, j, 'O');
                    
                    return;
                }
            }
        }
        
    }
    
    // check if curr position is available
    bool isAvailable(int x, int y)
    {
        if(x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != '-')
        {
            return false;
        }
        
        return true;
    }
    
    // read position from user
    void readPosition()
    {
        int x;
        int y;
        
        do
        {
            cout << "please enter a position :" << endl;
            cin >> x >> y;
            
        }
        while(!isAvailable(x, y));
        
        move(x,y,'X');
        
    }
    
    
    // check if there is a winner
    void isWinner(int x, int y, char c)
    {
        int curr = c == 'X' ? 1 : -1;
        row[x] += curr;
        col[y] += curr;
        if(x == y)
        {
            diag += curr;
        }
        if(x + y + 1 == 3)
        {
            anti_diag += curr;
        }
        
        if(abs(row[x]) == 3 || abs(col[y]) == 3 || abs(diag) == 3 || abs(anti_diag) == 3)
        {
            if(c == 'X')
            {
                winner = 1;
            }
            else
            {
                winner = 2;
            }
        }
        
    }
    
    
};



// test
int main(int argc, const char * argv[]) {
    
    TicTacToe * obj = new TicTacToe();
    obj -> play();
    
    return 0;
}
