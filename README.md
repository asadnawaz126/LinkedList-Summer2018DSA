# LinkedList-Summer2018DSA
Linked List Implementation in C++ for the Data Structures and Algorithms Course in Summer 2018

Lab Task 1:

Write a program that creates a linked list of bunny objects.
Each bunny object must have
Sex: Male, Female (random at creation 50/50)
color: white, brown, black, spotted
age : 0-5 (years old)
Name : randomly chosen at creation from a list of bunny names.
There is a 80% chance that the new bunny born is a male


At program initialization 5 bunnies must be created taken from input file.
Each turn afterwards the bunnies age 1 year.
So long as there is at least one male age 2 or older, for each female bunny in the list age 2 or older;
a new bunny is created each turn. (i.e. if there was 1 adult male and 3 adult female bunnies, three new bunnies would be born each turn)
New bunnies born should be the same color as their mother.
If a bunny becomes older than 5 years old, it dies.
The program should print a list of all the bunnies in the colony each turn along w/ all the bunnies details, sorted by age.
The program should also output each turns events such as
"Bunny Thumper was born!
Bunny Fufu was born!
Bunny Julius Caesar died!
The program should write all screen output to a file.

Resource regarding filing in C++: 
https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
http://www.cplusplus.com/doc/tutorial/files/

Output pattern

Cycle 1

Total bunnies 7
Roger M Black 4
Dumper M White 4
Peter M Brown 2
Daisy F Black 4
Ariel F White 5
Thumper M Black 0
Fufu M White 0

"Bunny Thumper was born!
Bunny Fufu was born!

Cycle 2

..

..

..
