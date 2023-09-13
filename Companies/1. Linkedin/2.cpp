//circular alphabets and pointer problem, time taken to travel a distance in it

#include <iostream>
#include <string>

using namespace std;

int getTime(string s) {
    char current = 'A';
    int time = 0;
    for (int i = 0; i < s.length(); ++i) {
        char next = s[i];
        int clockwise = abs(next - current);
        int anticlockwise = 26 - clockwise;
        time += min(clockwise, anticlockwise);
        current = next;
    }
    return time;
}

int main() {
    string input = "your_input_string_here";
    int result = getTime(input);
    cout << "Time taken: " << result << std::endl;
    return 0;
}