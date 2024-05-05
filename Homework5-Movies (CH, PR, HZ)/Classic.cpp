//Classic class meant to construct classic movie objects
#include <iostream>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "Classic.h"

/*
Constructor for Classic movie
*/
Classic::Classic() = default;

/*
Destructors for Classic movie
*/
Classic::~Classic() = default;

/*
Method to help set year for classic movie
*/
void Classic::setYear(std::string y) {
	this->year = y;
	setActorAndDate();
}

/*
Method to help set up actor and date for classic movie
*/
void Classic::setActorAndDate() {
	std::string line = getYear();
	std::stringstream stream(line);
	std::string first_name, last_name, day, year;
	stream >> first_name;
	stream >> last_name;
	stream >> day;
	stream >> year;
	MajorActor = first_name + " " + last_name;
	ReleaseDate = day + " " + year;
}

/*
Method that will return a string being of release date and major actor 
put together to act as a key for classic movie
*/
std::string Classic::getKey() const {
	return this->ReleaseDate + " " + this->MajorActor;
}

/*
Method that will return 'C'
as C is the key used to identify classic movies
*/
char Classic::getMovieType() const {
	return 'C';
}

/*
Operator overload meant to be used in order to compare classic movies together
and return true if they are the same based on director and title
*/
bool Classic::operator==(const Movie& movie) const {
	return (director == movie.getDirector()) &&
		(title == movie.getTitle());
}

/*
Operator != meant to be used in order to compore classic movies together
based on operator ==
*/
bool Classic::operator!=(const Movie& movie) const {
	return !(this == &movie);
}

/*
Operator > overlaod meant to be used to compare classic movies together
based upon release date then by major actor
*/
bool Classic::operator>(const Movie& movie) const {
	const auto* movie2 = dynamic_cast<const Classic*>(&movie);
	if (ReleaseDate > movie2->ReleaseDate) {
		return true;
	}
	else {
		if (ReleaseDate == movie2->ReleaseDate) {
			if (MajorActor > movie2->MajorActor) {
				return true;
			}
		}
	}
	return false;
}

/*
Operator < overlaod meant to be used to compare classic movies together
based upon release date then by major actor
*/
bool Classic::operator<(const Movie& movie) const {
	if (this == &movie) {
		return false;
	}
	if (this > &movie) {
		return false;
	}
	return true;
}