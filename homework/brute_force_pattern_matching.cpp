/*Brute force of pattern matching*/

#include<bits/stdc++.h> /*work with strings*/
#include <stack>
#include <iostream> 
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
// #include <chrono>  // for high_resolution_clock

// Usign namespace
using namespace std; 

// Function for resolve pattern matching
// stack<int> locate(char *text, int n, char *pattern, int m){
// stack<int> locate(string text, int n, char *pattern, int m){
stack<int> locate(string text, int n, string pattern, int m){

    /*Ocurrence stack*/
    stack <int> occ_stack;

    /*Iterate over each character in text*/
    for(int i = 0; i <= (n - m); ++i){

        /*Occurrence flag*/
        int occ = 1;

        /*Iterate over each character in patternt*/
        for(int j = 0; j < m and occ; ++j){

            /*if there is not an occurrence*/
            if(text[i + j] != pattern[j]){

                /* Change flag*/
                occ = 0;

            }                

        }

        /* If there is occurrence for that i*/
        if(occ){

            // printf("there is an occurrence in: %i\n", i);
            occ_stack.push(i);
        }

    }

    return occ_stack;
}

// Main function
int main(int argc, char *argv[]){

    if(argc != 2){

        printf("run as ./prog_name num_repeats \n");
        exit(EXIT_FAILURE);

    }
    // Get text
    // Read file
    // Store text in str (type = string)
    // std::ifstream t("fib41_10MB");
    std::ifstream t("english.10MB");
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    // pattern
    string pattern;

    /*Lenght of text and pattern*/
    int n = str.length();
    // int m = strlen(pattern); 
    int m;

    // printf("%i\n", n);

    // Stack for store ocurreces
    stack<int> occurrences;

    // Repetitions
    // int rep = 1000;
    int rep = atoi(argv[1]);

    // Array for store times
    float times [rep];

    // store time
    clock_t t_start;
    float time;

    // Random number
    int ran;

    // Number of experiments
    int exp_num = 5;

    // For each size of pattern
    int patterns_sizes [exp_num] = {2, 4, 8, 16, 32, 64};

    // printf("pattern size: %i\n", patterns_sizes[1]);
    // Iterate over each pattern size
    for(int pat_size = 0; pat_size < exp_num; ++pat_size ){

        // pattern size
        m = patterns_sizes[pat_size];

        // printf("pat_size: %i\n", pat_size);

        // printf("pattern size : %i\n", patterns_sizes[pat_size]);

        // Random number
        ran = rand() % (n-m);

        // printf("%i\n", ran);
        // get pattern
        // char pattern [m] = str[ran::ran + m - 1];
        pattern = str.substr(ran, m); 

        // cout << "pattern: " << pattern << endl;
        // cout << "pattern length: " << pattern.length() << " pattern : " << pattern << "----" << endl;
        // printf("Pattern length: %i\n", pattern.length());

        // Repeat algorithm rep times
        for(int i = 0; i < rep; ++i){

            // printf("Repetition %i\n", i);

            // get start time
            // clock_t time;
            t_start = clock();

            // Get ocurrences
            occurrences = locate(str, n, pattern, m);

            // Get taken time
            time = (float)(clock() - t_start)/CLOCKS_PER_SEC;
            // time = (float)time_req/CLOCKS_PER_SEC

            // printf("Time taken: %.9fs\n", time);
            // cout << time << endl;

            // Add time to array
            times[i] = time;

            // If there is not ocurrences
            if(occurrences.empty()){

                // print user message
                printf("There aren't ocurrences!\n");

            }

            // If there is ocurrences
            else{

                cout << "Pattern size: " << m << " Ocurrences : " << occurrences.size() << endl;

                // // Print all elemnts from stack
                // while (!occurrences.empty()) {

                //   printf("ocurrence in: %i\n", occurrences.top());

                //   // Drop ocurrence from stack
                //   occurrences.pop();

                // }

            }
        }

        // for(int i = 0; i < rep; ++i){

        //     printf("times: %f\n", times[i]);
        // }

        // Create file with times
        ofstream myfile ("times.csv");

        // If file is open
        if (myfile.is_open()){

            // Iterate over each element in times matrix
            for(int count = 0; count < rep; count ++){

                // add matrix elemento to file
                myfile << times[count] << ";" ;

            }

            // Close file
            myfile.close();

        }

    }



    return 0;

}
