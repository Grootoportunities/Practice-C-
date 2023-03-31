#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream file1("file1.txt");
    ofstream file2("file2.txt");

    int count = 0;
    while (true)
    {
        int random_number = rand();
        file1 << random_number << endl;

        auto current_time = chrono::system_clock::now();
        auto current_time_seconds = chrono::time_point_cast<chrono::seconds>(current_time);

        if (current_time_seconds.time_since_epoch().count() % 2 == 0 && current_time_seconds.time_since_epoch().count() % 4 == 0)
        {
            file2 << random_number << endl;
        }

        ++count;

        if (count >= 10)
        {
            file2.close();
            remove("file2.txt");
            file2.open("file2.txt");
            count = 0;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
