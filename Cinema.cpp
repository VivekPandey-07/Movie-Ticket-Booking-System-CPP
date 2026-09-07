#include <string>
#include <vector>
using namespace std;
class Cinema {
    string name; vector<Screen> screens; vector<Movie> movies;
public:
    Cinema(string name):name(name){}
    void addScreen(int n){screens.emplace_back(n);} void addMovie(const Movie&m){movies.push_back(m);}
    vector<Screen>& getScreens(){return screens;} vector<Movie>& getMovies(){return movies;}
};
