//Drama class meant to construct a drama movie object
#include <iostream>
#include "Drama.h"
#include "Movie.h"

/*
Constructor for drama movie
*/
Drama::Drama() = default;

/*
Destructor for drama movie
*/
Drama::~Drama() = default;

/*
Method meant to return a string consisting of director and title 
to be used as a key
*/
std::string Drama::getKey() const {
	return getDirector() + " " + getTitle();
}

/*
Method that returns D as it will be used 
to identify a drama movie
*/
char Drama::getMovieType() const {
    return 'D';
}

/*
Operator == overload meant to be used to compare 
with other drama movie based on director and title
*/
bool Drama::operator==(const Movie & movie) const {
	return (director == movie.getDirector()) &&
		(title == movie.getTitle());
}

/*
Operator != overload meant to be used to compare 
with other drama movie based on director and title
*/
bool Drama::operator!=(const Movie& movie) const {
	return !(this == &movie);
}

/*
Operator > overload meant to be used to compare 
with other drama movie based on director and title
*/
bool Drama::operator>(const Movie& movie) const {
	if (director > movie.getDirector()) {
		return true;
	}
	else {
		if (title > movie.getTitle()) {
			return true;
		}
	}
	return false;
}

/*
Operator < overload meant to be used to compare 
with other drama movie based on director and title
*/
bool Drama::operator<(const Movie & movie) const {
	if (director == movie.getDirector()) {
		return true;
	}
	else {
		if (director == movie.getDirector()) {
			if(title.compare(movie.getTitle()) < 0) {
				return true;
			}
		}
	}
	return false;
}
