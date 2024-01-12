#include <iostream>
#include <string>

class Movie {
public:
    std::string title;
    std::string genre;
    int releasedYear;

    Movie(std::string t, std::string g, int year) : title(t), genre(g), releasedYear(year) {}
};

int main() {
    Movie movies[3] = {
        Movie("abcd", "Sci-Fi", 2010),
        Movie("xzy", "Drama", 2015),
        Movie("AB", "Action", 2008)
    };

    for (int i = 0; i < 3; ++i) {
        std::cout << "Movie " << i + 1 << ":\n";
        std::cout << "Title: " << movies[i].title << "\n";
        std::cout << "Genre: " << movies[i].genre << "\n";
        std::cout << "Released Year: " << movies[i].releasedYear << "\n\n";
    }

    return 0;
}
