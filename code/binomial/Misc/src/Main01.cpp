//Include io -> from terminal
#include <iostream>

using namespace std;

int main() {

    std::cout << "Hello, World!" << std::endl;

    string x;
    cin >> x;

    string place_holder = "You said....";
    std::cout << place_holder.append(x) << std::endl;

    return 0;
}
