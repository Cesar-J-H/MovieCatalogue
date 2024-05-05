//Comedy class meant to construct comedy movie objects
#include <iostream>
#include "Movie.h"
#include "Comedy.h"

/*
Constructor for Comedy movie
*/
Comedy::Comedy() = default;

/*
Destructor for Comedy movie
*/
Comedy::~Comedy() = default;

/*
Method that returns the type of movie it is being F
*/
char Comedy::getMovieType() const {
    return 'F';
}

/*
Method that returns a string being of title and year meant to 
be used as a key 
*/
std::string Comedy::getKey() const {
	return getTitle() + "," + getYear();
}

/*
Operator== overload meant to be used to compare comedy movies
based upon title and year
*/
bool Comedy::operator==(const Movie & movie) const {
	return (title == movie.getTitle()) && 
		(year == movie.getYear());
}

/*
Operator== overload meant to be used to compare comedy movies
based upon == overload
*/
bool Comedy::operator!=(const Movie & movie) const {
	return !(this == &movie);
}

/*
Operator > overload meant to be used to compare comedy movies
based upon title and year
*/
bool Comedy::operator>(const Movie & movie) const {
	if (title.compare(movie.getTitle()) > 1) {
		return true;
	}
	else {
		if(year > movie.getYear()) {
			return true;
		}
	}
	return false;
}

/*
Operator < overload meant to be used to compare comedy movies
based upon title and year
*/
bool Comedy::operator<(const Movie & movie) const {
	if (title.compare(movie.getTitle()) < 1) {
		return true;
	}
	else {
		if(title == movie.getTitle()) {
			if(year < movie.getYear()) {
				return true;
			}
		}
	}
	return false;
}
