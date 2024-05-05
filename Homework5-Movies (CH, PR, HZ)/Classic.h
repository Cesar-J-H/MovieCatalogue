//Classic class header
#ifndef _CLASSIC_H_
#define _CLASSIC_H_
#include <iostream>
#include <sstream>
#include "Movie.h"

class Classic : public Movie {
public:
    Classic();
    ~Classic();
    char getMovieType() const ;
    std::string getKey() const;
   
    void setYear(std::string y);
    bool operator==(const Movie& movie) const;
	bool operator!=(const Movie& movie) const;
	bool operator>(const Movie& movie) const;
	bool operator<(const Movie& movie) const;
    
private:
    std::string MajorActor;
	std::string ReleaseDate;
    void setActorAndDate();
};
#endif
