class Solution {
public:
   bool exist(vector<vector<char>> &board, string word) {
     
       for(int i = 0 ; i < board.size() ; ++i)
           for(int j = 0 ; j < board[0].size() ; ++j)
               if(dfs(0 , i , j , board , word))
                   return true;
       return false;
   }
   bool dfs(int index , int x , int y , vector<vector<char>> &board , string &word)
   {
       if(index == word.size()) 
           return true;
       
       if(x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or board[x][y] == '.')
           return false;
       
       if(board[x][y] != word[index])
           return false;
       
       char temp = board[x][y];
       board[x][y] = '.'; 
       if(dfs(index + 1 , x - 1 , y , board , word) || dfs(index + 1 , x + 1 , y , board , word) || dfs(index + 1 , x , y - 1 , board , word) || dfs(index + 1 , x , y + 1 , board , word))
           return true;
           
       board[x][y] = temp; 
       return false;
       
   }
   
};