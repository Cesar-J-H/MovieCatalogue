//Movie Header file
#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
#include <ostream>

class Movie {
	friend std::ostream& operator<<(std::ostream& ostream, const Movie& movie);
public:
	virtual ~Movie();
    virtual std::string getDirector() const;
	virtual std::string getTitle() const;
	virtual std::string getYear() const;
	int getStock() const;
    virtual char getMovieType() const=0;
	virtual std::string getKey() const = 0;
	virtual void setDirector(std::string d);
	virtual void setTitle(std::string t);
	virtual void setYear(std::string y);
	virtual void setStock(int x);

	virtual bool operator==(const Movie& movie) const = 0;
	virtual bool operator!=(const Movie& movie) const = 0;
	virtual bool operator>(const Movie& movie) const = 0;
	virtual bool operator<(const Movie& movie) const = 0;

protected:
    std::string director;
	std::string title;
	std::string year;
	int stock;
};
#endif
