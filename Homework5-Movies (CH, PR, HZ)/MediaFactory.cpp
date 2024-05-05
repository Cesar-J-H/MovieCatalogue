//MediaFactory class meant to help produce other movie objects
#include "MediaFactory.h"
#include <iostream>
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"

/*
Method that returns a movie object using an ifstream 
Will create either a drama, classic, or comedy
*/
Movie *MediaFactory::buildMovie(std::ifstream &stream) {
	std::string read_input;
  	getline(stream, read_input);
	std::stringstream line_input(read_input);
	getline(line_input, read_input, ','); // read the character
	char type = read_input[0];
	// create a movie using the static movie factory
	Movie *temp_movie = nullptr;
	//create movie if input is correct
	switch (type) {
	case COMEDY:
		temp_movie = new Comedy;
		break;
  	case CLASSIC:
		temp_movie = new Classic;
		break;
  	case DRAMA:
    	temp_movie = new Drama;
    	break;
  	default:
    	temp_movie = nullptr;
    	break;
	}
  	if (temp_movie) { // if not NULL
		// read the stock and cast to an int
		getline(line_input, read_input, ',');
		int stock = atoi(read_input.c_str());
		// initialize the movie stock
		temp_movie->setStock(stock);
		// read the white space
		line_input.get();
		// read the director
		getline(line_input, read_input, ',');
		std::string director = read_input;
		// initialize the movie director
		temp_movie->setDirector(director);
		// read the white space
		line_input.get();
		getline(line_input, read_input, ',');
		std::string title = read_input;
		// initialize the movie title
		temp_movie->setTitle(title);
		// read the white space
		line_input.get();
		getline(line_input, read_input, ',');
		std::string year = read_input;
		// initialize the movie Year
		temp_movie->setYear(year); 
  	}
 	return temp_movie;
}
