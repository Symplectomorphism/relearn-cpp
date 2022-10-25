#include "../text_lib/std_lib_facilities.h"

int main()
{
    // Accept name value pairs, store them in vectors, print them in the end.
    
    vector<string> names;
    vector<int> scores;

    string name = "";

    int score = 0;

    bool end = false;
    bool repeat = false;

    while (!end) {
        cout << "Enter a name and a value:\n";
        cin >> name >> score;

        if (name == "NoName" && score == 0)
            end = true;
        else {
            for (string n : names)
                if (n == name)
                    repeat = true;
            
            if (repeat) {
                cout << "Error: duplicate name\n";
                repeat = false;
            } else {
                names.push_back(name);
                scores.push_back(score);
            }
        }
    }

    int query = 0;
    cout << "Which score would you like to look up?\n";
    cin >> query;

    vector<string> matches;

    for (int i = 0; i < names.size(); ++i)
        if (scores[i] == query)
            matches.push_back(names[i]);

    if (matches.size() > 0)
        for (string m : matches)
            cout << m << '\n';
    else
        cout << "score not found\n";
}
