#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

class Movie {
public:
    Movie() : title(""), genre(""), year(0000), director(""), rating(0.0) {}
    Movie(std::string title, std::string genre, int year, std::string director, double rating)
        : title(title), genre(genre), year(year), director(director), rating(rating) {}
    Movie(std::string title)
        : title(title), genre("DESCONOCIDO"), year(9999), director("DESCONOCIDO"), rating(0.0) {}

    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
    int getYear() const { return year; }
    std::string getDirector() const { return director; }
    double getRating() const { return rating; }

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << movie.title << " (" << movie.year << ") - " << movie.director << " - " << movie.rating;
        return os;
    }
    bool operator<(const Movie& other) const {
        return this->title < other.title;
    }
    bool operator==(const Movie& other) const {
        return this->title == other.title;
    }

private:
    std::string title;
    std::string genre;
    int year;
    std::string director;
    double rating;
};

#endif // MOVIE_H
