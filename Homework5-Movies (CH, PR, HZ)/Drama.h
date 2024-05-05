//Drama header file
#ifndef _DRAMA_H_
#define _DRAMA_H_
#include <iostream>
#include "Movie.h"

class Drama : public Movie {
public:
    Drama();
    ~Drama();
    std::string getKey() const;
    char getMovieType() const ;
    
    bool operator==(const Movie& movie) const;
	bool operator!=(const Movie& movie) const;
	bool operator>(const Movie& movie) const;
	bool operator<(const Movie& movie) const;
};
#endif
