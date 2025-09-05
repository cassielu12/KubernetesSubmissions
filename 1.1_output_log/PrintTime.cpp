// random string generation reference ：
// https://medium.com/@ryan_forrester_/c-random-string-generation-practical-guide-e7e789b348d4
// time generation reference : C++ Annontation book by Frank Brokken 6.4.4
// sleep reference : https://stackoverflow.com/questions/10807681/loop-every-10-second
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <string>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

string generate_random_string(size_t length) {
    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    string random_string;
    for (size_t i = 0; i < length; ++i) {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}


int main() {
    const string random_str = generate_random_string(10);
    while (true) {
        this_thread::sleep_for(chrono::seconds(5));
        time_t secs = system_clock::to_time_t(system_clock::now());
        cout << put_time(localtime(&secs), "%c") << " " << random_str << endl;
        //endl forces the output to be flushed immediately; if not use endl but use /n, 
        // the program can work well in local machine, but just print the
        //first timestamp in kubernetes logs
    }
}
