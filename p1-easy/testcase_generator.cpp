#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random string of given length
string randomString(int length) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    for (int i = 0; i < length; ++i) {
        result += characters[rand() % characters.size()];
    }
    return result;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Constraints
    int t = 1; // Number of test cases
    int N = 1000; // Number of girlfriends
    int Q = 1000; // Number of queries
    int maxGifts = 20; // Maximum number of gifts per girlfriend
    int maxPrice = 100; // Maximum price per gift

    ofstream outfile("random_test_case.txt");

    // Generate test case
    outfile << t << endl;
    for (int testCase = 0; testCase < t; ++testCase) {
        outfile << N << " " << Q << endl;
        for (int i = 0; i < N; ++i) {
            string name = "Girlfriend" + to_string(i); // Unique girlfriend name
            int numGifts = rand() % maxGifts + 1; // Random number of gifts (1 to maxGifts)
            outfile << name << endl;
            outfile << numGifts << endl;
            for (int j = 0; j < numGifts; ++j) {
                int price = rand() % maxPrice + 1; // Random price (1 to maxPrice)
                outfile << price << " ";
            }
            outfile << endl;
        }
        for (int i = 0; i < Q; ++i) {
            string queryName = "QueryGirl" + to_string(rand() % N); // Random query about a girlfriend
            outfile << queryName << endl;
        }
    }

    outfile.close();
    cout << "Random test case generated in 'random_test_case.txt'" << endl;

    return 0;
}

