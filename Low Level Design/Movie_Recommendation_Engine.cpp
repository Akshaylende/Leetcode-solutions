#include<bits/stdc++.h>
using namespace std;

// Defining User class
class User{
  string name;
  public:
  unordered_map<string, int> reviews;
    User(string uname){
      this->name = uname;
    }
    
    string getName(){
      return this->name;
    }
    
    // Function to add user ratings for movies
    void addReview(string title, int rating){
      reviews[title] = rating;
    }
    
    // checks for watched movies
    bool hasWatch(string title){
      if(reviews.find(title) == reviews.end())
        return false;
      return true;
    }
};

// Defining Movie class
class Movie{
  string title;
  public:
    Movie(string name){
      this->title = name;
    }
    
    string getMovie(){
      return this->title;
    }
};



// Defination for MovieRatings class
class MovieRatings{
  unordered_map<string, int> movie_ratings;
  public:
    MovieRatings(){}
    
    // Adding Ratings in the movie reviews  
    void addRating(string title, int rating){
      int avg_rating = (rating + movie_ratings[title])/2;
      movie_ratings[title] = avg_rating;
    }
    
    // printing movie ratings
    void printMovieRatings(){
      for(auto [x, y] : movie_ratings)
        cout<< x << " "<< y <<endl;
    }
    
    
    // Return Top Three Movies 
    vector<string> topThreeMovies(User *user){
      vector<string>top_three_movies;
      priority_queue<pair<int, string>>pq;
      
      
      for(auto [x, y]: movie_ratings){
        if(!user->hasWatch(x))
          pq.push({y, x});
      }
      
      while(!pq.empty() && top_three_movies.size() < 3){
        auto [rating, movie] = pq.top();
        pq.pop();
        top_three_movies.push_back(movie);
      }
      
      return top_three_movies;
    }
};



// Defination of RecomendationEngine
class RecomendationEngine{
  MovieRatings *mr;
  public:
  RecomendationEngine(){
    this->mr = new MovieRatings();
  }
  
  void addMovieRating(string title, int rate){
    mr->addRating(title, rate);  
  }
  
  void printRecommendations(vector<string>& recomendations){
    cout<< "Top three Recomendations are ";
    
    for(auto x: recomendations)
      cout<< x << "  ";
    
    cout<<endl;
  }
  
  void recomendMovies(User *user){
      vector<string> list = mr->topThreeMovies(user);
      printRecommendations(list);
  }
};

// Main Method
int main(){
  cout<< "Welcome to Recommendation Engine!" << endl;
  RecomendationEngine *RE = new RecomendationEngine();
  
  User *u1 = new User("Akshay");
  User *u2 = new User("Piyush");
  User *u3 = new User("Akash");
  
  Movie *m1 = new Movie("Avengers");
  Movie *m2 = new Movie("Spiderman");
  Movie *m3 = new Movie("Antman");
  Movie *m4 = new Movie("Ironman");
  Movie *m5 = new Movie("Marvels");
  
  u1->addReview("Antman", 4.5);
  u3->addReview("Antman", 4);
  RE->addMovieRating("Antman", 4.5);
  RE->addMovieRating("Antman", 4);
  
  u1->addReview("Ironman", 4);
  RE->addMovieRating("Ironman", 4);
  
  u3->addReview("Spiderman", 4.5);
  RE->addMovieRating("Spiderman", 4.5);
  
  
  RE->recomendMovies(u1);
  return 0;
}