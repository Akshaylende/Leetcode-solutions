#include <bits/stdc++.h>
using namespace std;


// Defining player
class Player{
    string name;
    int piece;
    public:
        Player(string name, int color){
            this->name = name;
            this->piece = color;
        }

        string getName(){
            return this->name;
        }

        int getPiece(){
            return this->piece;
        }
};



// Defining Board
class Board{
    vector<vector<int>> Grid;
    int rows, cols, connectN;
    public:
        Board(int row, int col, int connect){
            this->rows = row;
            this->cols = col;
            this->connectN = connect;
            Grid.resize(rows, vector<int>(cols));
            fillBoard( 0);
        }

        void fillBoard(int val){
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    Grid[i][j] = val;
        }

        void printBoard(){
            for(int i =0; i< rows; i++){
                for(int j =0; j< cols; j++){
                    if(Grid[i][j] == 1){
                        cout<<"X ";
                    } 
                    else if(Grid[i][j] == 2){
                        cout<<"Y ";
                    }
                    else cout<<"O "; 
                }
                cout<<endl;
            }
        }


        int placePiece(int col, int piece){
            if(col<0 || col >= cols) return -1;
            for(int i = rows-1; i>=0; i--){
                if(Grid[i][col] == 0){
                    Grid[i][col] = piece;
                    return i;
                }
            }
            return -1;
        }

        bool checkWin(int row, int col, int piece){
            int count = 0;
            // horizontal
            for(int i=0; i<cols; i++){
                if(Grid[row][i] == piece) count+=1;
                else count = 0;
                if(count == connectN) return true;
            }

            // vertical
            count = 0;
            for(int i=0; i<rows; i++){
                if(Grid[i][col] == piece) count+=1;
                else  count = 0;
                if(count == connectN) return true;
            }

            // diagonal
            count = 0;
            for(int i=0; i<rows; i++){
                int j = row + col - i;
                if(j>=0 && j< cols && Grid[i][j] == piece) count+=1;
                else count = 0;
                if(count == connectN) return true;
            }

            // Anti-diagonal
            count = 0;
            for(int i=0; i<rows; i++){
                int j = col - row + i;
                if(j>=0 && j< cols && Grid[i][j] == piece) count+=1;
                else count = 0;
                if(count == connectN) return true;
            }

            return false;
        }
};

class Game{
    int targetScore, connectN;
    Board *b;
    vector<Player *> players;
    unordered_map<string, int> scores;
    public:
        Game(Board *b1, int targetS, int connect){
            this->targetScore = targetS;
            this->connectN = connect;
            this->b = b1;
            // Instantiating players
            players.push_back(new Player("player 1", 1));
            players.push_back(new Player("player 2", 2));

            // setting scores
            scores[players[0]->getName()] = 0;
            scores[players[1]->getName()] = 0;
        }

    
        bool playChance(Player *player){
            b->printBoard();
            int col;
            cout<<"Enter a valid column move(zero Indexed): ";
            cin>>col;
            int row = b->placePiece(col, player->getPiece());
            if(row != -1){
                if(b->checkWin(row, col, player->getPiece())){
                    scores[player->getName()] +=1;
                    return true;
                }
            }
            return false;
        }

        string playRound(){
            while(true){
                for(auto player: players){
                    if(playChance(player))
                        return player->getName();
                }
            }
            return "";
        }

        void play(){
            int round = 0;
            int maxScore = 0;
            string winner = "";
            while(maxScore < targetScore){
                round += 1;
                winner = playRound();
                if(scores.find(winner)!= scores.end()){
                    scores[winner]+=1;
                    maxScore = max(maxScore, scores[winner]);
                    cout<< winner << " won the "<< round << " round"<<endl;
                }
                b->fillBoard(0);
            }
            cout<< winner << " is the winner of the game."<<endl;
        }

};

int main(){
    cout<<"In main"<<endl; 
    int r, c, cn, ts;
    cout<< "Enter the rows, cols and connect n count : ";
    cin>> r>> c>> cn;
    Board *b1 = new Board(r, c, cn);
    cout<< endl;

    cout<<"Enter the target score to declare someone as win";
    cin>> ts; 
    cout<< endl;

    Game *g1  = new Game(b1, ts, cn);
    g1->play();

    return 0;
}







