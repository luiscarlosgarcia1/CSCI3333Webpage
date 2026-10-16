#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

void showStats(const unordered_map<string, double>& M)
{
    // n: stored pairs; table's current data size.
    cout << "\nn (number of items): " << M.size() << endl;
    // H: available buckets; more buckets means less crowding.
    cout << "H (bucket count): " << M.bucket_count() << endl;
    // n/H: average pairs per bucket; high means more collisions.
    cout << "load factor (n/H): " << M.load_factor() << endl;
    // Resize threshold; table rehashes past this to stay near O(1).
    cout << "max load factor before resizing: " << M.max_load_factor() << endl;
}

int main()
{
    // An unordered_map is a hash table of key-value pairs.
    unordered_map<string, double> gpas;

    gpas.insert({"viviana", 3.9});
    gpas["george"] = 4.0;
    gpas["rob"] = 5.0;
    gpas["will"] = 2.7;
    gpas["santiago"] = 0.5;
    gpas["sean"] = 0.1;

    cout << "Will's GPA is: " << gpas.at("will") << endl;

    cout << "\nUnordered-map items (order and bucket numbers can vary):\n";
    for (const auto& entry : gpas)
        cout << entry.first << " : " << entry.second
             << " : bucket " << gpas.bucket(entry.first) << endl;

    showStats(gpas);

    // std::map has the same key-value idea, but iterates in sorted-key order.
    map<string, double> sortedGpas(gpas.begin(), gpas.end());
    cout << "\nSame items in std::map order:\n";
    for (const auto& entry : sortedGpas)
        cout << entry.first << " : " << entry.second << endl;
}
