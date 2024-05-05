//Comedy class header
#ifndef _COMEDY_H_
#define _COMEDY_H_
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <string>
#include "Movie.h"

class Comedy : public Movie {
public:
    Comedy();
    ~Comedy();
    char getMovieType() const ;
    std::string getKey() const;
   
	bool operator==(const Movie& movie) const;
	bool operator!=(const Movie& movie) const;
	bool operator>(const Movie& movie) const;
	bool operator<(const Movie& movie) const;
};
#endif
