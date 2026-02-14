# include<bits/stdc++.h>
using namespace std;


// Defination of User class
class User{
  int uid;
  string name;
  unordered_map<string, int> ratings;
  public:
    User(int id, string name){
      this -> uid = id;
      this -> name = name;
    }
    
    // Getter for name  
    string getName(){
      return this->name;
    }
    
    int getRatingsCount(){
      int count = 0;
      for(auto [x, y] : ratings){
        if(y > 0) count++; 
      }
      return count;
    }
  
    // ratings handling
    bool addRatings(string title, int rate){
      if(ratings.find(title) != ratings.end()
        || ratings[title] != 0){
          return false;
      }
      ratings[title] = rate;
      return true;
    }
    
    // checking for watched movies
    bool hasWatch(string title){
      
      if(ratings.find(title) != ratings.end())
        return true;
        
      return false;
    }
};




// Defination for Movie class
class Movie{
  int id;
  string title;
  unordered_map<int, unordered_set<User *>> ratings_group;
  public:
    Movie(int id, string name){
      this->id = id;
      this->title = name;
    }
    
    // Getter for movie title
    string getTitle(){
      return this->title;
    }
    
    // Adding user to Ratings Group
    void addUserToGroup(User *user, int rate){
      ratings_group[rate].insert(user);
    }
};



// Defination & Implementation of Recommendation Engine
class RecommendationEngine{
    unordered_map<string, pair<int, int>> reviews;
  public:
    RecommendationEngine(){
      
    } 
    
    // Adding reviews
    void addReviews(string title, int rate){
      int ratingsCount = 0;
      int ratings = 0;
        if(reviews.find(title) != reviews.end()){
            ratings = reviews[title].first;
            ratingsCount  = reviews[title].second; 
        }
      ratingsCount++;
      ratings += rate;
      reviews[title] = {ratings, ratingsCount};
    }
    
    
    // Top Five Movies
    vector<string> topFiveMovies(){
      priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;
      for(auto [x, y] : reviews){
        pq.push({(y.first/y.second), x});
        if(pq.size() > 5) pq.pop();
      }
      vector<string> movies;
      while(!pq.empty()){
        movies.push_back(pq.top().second);
        pq.pop();
      }
      reverse(movies.begin(), movies.end());
      return movies;
    }
    
    
    // Recommend to new User
    vector<string> Recommend(User *user){
        if(user->getRatingsCount() == 0)
          return topFiveMovies();
        unordered_set<string> movies;
        
    }
    
};


// Main method
int main(){
  cout<<"In Main"<<endl;
  
  RecommendationEngine RE;
  
  Movie *m1 = new Movie(1, "Avengers");
  Movie *m2 = new Movie(2, "End Game");
  Movie *m3 = new Movie(3, "Infinity War");
  Movie *m4 = new Movie(4, "Captain America");
  Movie *m5 = new Movie(5, "Marvels");
  Movie *m6 = new Movie(6, "SpiderMan");
  
  User *u1 = new User(1, "Akshay");
  User *u2 = new User(2, "Piyush");
  User *u3 = new User(3, "Ayush");
  User *u4 = new User(4, "Aman");
  User *u5 = new User(5, "Nikki");
  
  u1->addRatings("Captain America", 4);
  u1->addRatings("Marvels" , 4);
  u1->addRatings("Infinity War", 5);
  RE.addReviews("Captain America", 4);
  RE.addReviews("Marvels", 4);
  RE.addReviews("Infinity War", 5);
  
  
  u2->addRatings("Marvels", 4);
  u2->addRatings("SpiderMan", 4);
  RE.addReviews("SpiderMan", 4);
  RE.addReviews("Marvels", 4);
  
  u3->addRatings("Infinity War", 5);
  u3->addRatings("End Game", 5);
  RE.addReviews("Infinity War", 5);
  RE.addReviews("End Game", 5);
  
  u4->addRatings("SpiderMan", 4);
  u4->addRatings("Captain America", 4);
  RE.addReviews("Captain America", 4);
  RE.addReviews("SpiderMan", 4);

  
  vector<string> movies = RE.Recommend(u5);
  
  for(auto x: movies){
    cout<< x << endl;
  }
  if(movies.size() == 0){
    cout<<"Nothing to Recommend"<<endl;
  }
  
  return 0;
}