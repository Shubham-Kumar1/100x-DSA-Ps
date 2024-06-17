#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random integer between min and max (inclusive)
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a test case with random nums array and k value
pair<vector<int>, int> generateTestCase() {
    srand(time(0)); // Seed the random number generator with current time
    
    int size = randomInt(1, 10); // Generate random size for nums array
    vector<int> nums(size);
    
    for (int i = 0; i < size; ++i) {
        nums[i] = randomInt(0, 100); // Generate random integers between 0 and 100
    }
    
    int k = randomInt(0, 100); // Generate random k value
    
    return {nums, k};
}

int main() {
    // Generate a test case
    auto testCase = generateTestCase();
    vector<int> nums = testCase.first;
    int k = testCase.second;
    
    // Print the generated test case
    cout << "Generated testcase:" << endl;
    cout << "nums = {";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
    cout << "k = " << k << endl;
    
    return 0;
}

