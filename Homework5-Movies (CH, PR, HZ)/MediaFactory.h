//MediaFactory header file
#ifndef _MEDIA_Factory_H_
#define _MEDIA_Factory_H_
#include <iostream>
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"

const char COMEDY = 'F';
const char CLASSIC = 'C';
const char DRAMA = 'D';

class MediaFactory {
public:
	static Movie* buildMovie(std::ifstream& stream);
  
};
#endif
