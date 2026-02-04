# include <bits/stdc++.h>
using namespace std;

// Definition of class player
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


// Definition of class Board
class Board{
    int rows, cols, connectN;
    vector<vector<int>> grid;

    public:
        Board(int rows, int cols, int connectN){
            this->rows = rows;
            this->cols = cols;
            this->connectN = connectN;
            this->grid.resize(rows, vector<int> (cols));
            FillBoard(grid, 0);
        }

        void FillBoard(vector<vector<int>> &grid, int piece){
            for(int i =0; i< rows; i++){
                for(int j = 0; j < cols; j++){
                    grid[i][j] = piece;
                }
            }            
        }

        vector<vector<int>> getBoard(){
            return this->grid;
        }

        int getColumns(){
            return this->cols;
        }

        int placepiece(int col, int piece){
            if(col < 0 && col >= this->cols)
                return -1;
            else if(piece == 0)
                return -1;
            for(int i = rows-1; i >= 0; i--){
                if(grid[i][col] == 0){
                    grid[i][col] = piece;
                    return i;
                }
            } 
            return -1;
        }

        bool checkWinner(int row, int col, int piece){
            int count = 0;
            // check horizontally
            for(int j = 0; j< cols; j++){
                if(grid[row][j] == piece)
                    count+=1;
                else
                    count = 0;
                if(count == connectN)
                    return true;
            }   

            // check vertically
            count = 0;
            for(int i=0; i< rows; i++){
                if(grid[i][col] == piece)
                    count+=1;
                else
                    count = 0;
                
                if(count == connectN)
                    return true;
            } 

            // check diagonal 
            count = 0;
            for(int i = 0; i< rows; i++){
                int j = row + col - i;
                if(j>=0 && j < cols && grid[i][j] == piece)
                    count+=1;
                else
                    count = 0;
                if(count == connectN)
                    return true; 
            }

            // anti diagonal 
            count = 0;
            for(int i = 0; i< rows; i++){
                int j = col - row + i;
                if(j>=0 && j < cols && grid[i][j] == piece)
                    count+=1;
                else
                    count = 0;
                if(count == connectN)
                    return true; 
            }


            return false;
        }        

};

class Game{
    vector<vector<int>> grid;
    int connectN, targetS;
    vector<Player* > players;
    unordered_map<string , int> scores;
    
    public:
        Game(Board b1, int  connectN, int target){
            this->grid = b1;
            this->connectN = connectN;
            this->targetS = target;

            this->players.push_back(new Player('Player 1', 1));
            this->players.push_back(new Player('Player 2', 2));
            
            for(auto x : players){
                scores[x->getName()] = 0;
            }
        }

        void printBoard(){
            cout<<"Board" <<endl;
            for(int i = 0; i< grid.size(); i++){
                for(int j = 0; j< grid[0].size(); j++)
                    if(grid[i][j] == 1)
                        cout<< "Y ";
                    else if(grid[i][j] == 2)
                        cout<< "R ";
                    else 
                        cout<<"0 ";
                cout<< endl;
            }
        }

        pair<int, int> playMove(Player player){
            printBoard();
            cout<< player.getName()<< "'s turn"<<endl;
            cin >> movecol;
            moverow =  grid.placepiece(movecol, player.getPiece());
            return {moverow, movecol};
        }

        Player playRound(){
            while(true){
                for(auto player in players){
                    auto [row, col] = playMove(player);
                    pieceColor = player.getPiece();
                    if(grid->checkWinner(row, col, pieceColor)){
                        scores[player.getName()] +=1;
                        return player;
                    }
                }
            }
            return NULL;
        }
        
        void play(){
            int maxScore = 0;
            Player winner = NULL;
            while(maxScore < targetS){
                winner = playRound();
                if(winner)
                    cout<< winner.getName()<<" won this round"<<endl;
                maxscore = max(maxscore, scores[winner.getName()]);
                grid.FillBoard(grid, 0); 
            }
            cout<< winner.getName()<< " won the game"<<endl;
        }
};


int main(){

    return 0;
}