//#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include<fstream>
#include<iostream>
using namespace std;
	int
main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    std::fstream fs2(argv[1]);
    int line_num = 0;
    string line;
    while (getline(fs2, line)) {
        line_num++;
    }
    cout<<"num = "<<line_num<<endl;
    return 0;
}
