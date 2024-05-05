# Self-Evaluation

## Name(s): Cesar H, Pablo R, Humamah Z.

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*
Clang-tidy ommited for this assignment. Ok for other hws


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: -8

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code:
store.cpp executeCommands
switch case defaults invalid commands as errors and prints message

invalid movie type:
store.cpp findMovie()
if statment checks if nullptr

invalid customer ID:
store.cpp executeCommands
customerDatabase.getACustomer(#)
if statement checks if nullptr
 
invalid movie:
store.cpp executeCommands
findMovie()
if statement checks if nullptr

factory classes: MediaFactory.h and .cpp

hashtable:
Hashtable.h is used in Customerdb.h and .cpp to store customer id as a key and a customer object as its value. Each function in customerdb makes use of the hashtable

container used for comedy movies:
std::map<std::string, std::vector<Movie*>> catalog

function for sorting comedy movies: 
store.cpp less_than()

function where comedy movies are sorted:
comedy.cpp operator <

functions called when retrieving a comedy movie based on title and year:
findMovie()
comedy.getTitle()

functions called for retrieving and printing customer history:
customerDatabase.getACustomer(#)
customer->showHistory()

container used for customer history:
In customer.cpp and .h we use a vector of strings (named history) that pushes new history to the front

functions called when borrowing a movie:
customerdb.getACustomer(#)
findMovie()
movie->getStock()
customer->borrowMovie(movie)

explain borrowing a movie that does not exist:
using our findMovie() function it'll return a nullptr if the movie doesn't exist
We have an if statement that checks for this and will print out the message that the movie isn't found. No movie is borrowed as a result

explain borrowing a movie that has 0 stock: In store.cpp's executeCommands function
in the function if the movie does exist then there is an if statement that checks that movie's stock. If there's 0 stock then 

explain returning a movie that customer has not checked out:
each customer has a vector containing movies they are currently borrowing, if the
movie being returned isn't in this vector then nothing is changed. No return, history update, etc

any static_cast or dynamic_cast used:
store.cpp less_than

Q: Total points: -8