/****************************************
 * Name: Module 12 Learn Maps
 * Author: Tanner Babcock
 * Created: November 11, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
****************************************/
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class Map {
private:
    map<string, string> m;
    unsigned int keys;
public:
    Map(void) : keys(0) { }
    Map(map<string, string> ma) : m(ma), keys(1) { }
    Map(string e, string n) : keys(1) {
        m.insert(pair<string, string>(e, n));
    }
    Map(pair<string, string> p) : keys(1) {
        m.insert(pair<string, string>(p));
    }

    void insert(string e, string n) {
        m.insert(pair<string, string>(e, n));
        keys++;
    }
    void insert(pair<string, string> p) {
        m.insert(pair<string, string>(p));
        keys++;
    }

    void remove(string e) {
        m.erase(e);
        keys--;
    }
    void remove(int key) {
        int x = 0;
        for (auto ii = m.begin(); ii != m.end(); ++ii) {
            if (x == key) {
                m.erase(ii->first);
                break;
            }
            x++;
        }
        keys--;
    }

    map<string, string>::iterator search(string e) {
        return m.find(e);
    }

    bool hasKey(string e) {
        for (auto ii = m.begin(); ii != m.end(); ++ii) {
            if (ii->first == e)
                return true;
        }
        return false;
    }
    bool hasValue(string n) {
        for (auto ii = m.begin(); ii != m.end(); ++ii) {
            if (ii->second == n)
                return true;
        }
        return false;
    }

    void print(void) {
        cout << "Email\t\t\tName\t\t" << keys << " entries" << endl;
        int x = 1;
        for (auto ii = m.begin(); ii != m.end(); ++ii, x++) {
            cout << x << ". " << ii->first << "\t\t" << ii->second << endl;
        }
    }

    unsigned int getKeys(void) {
        return keys;
    }
};

int main(void) {
    Map *m = new Map("johnsmith@example.com", "John Smith");
    m->insert("stevejobs@apple.com", "Steve Jobs");
    m->insert("earl@sweatshirt.com", "Earl Sweatshirt");
    m->insert("babkock@protonmail.com", "Tanner Babcock");
    m->insert("newtgrundyie@gmail.com", "Newt Grundy");

    cout << "Email stevejobs@apple.com " << ((m->hasKey("stevejobs@apple.com")) ? "was " : "was not ") << "found" << endl;
    cout << "Email earl@sweatshirt.com " << ((m->hasKey("earl@sweatshirt.com")) ? "was " : "was not ") << "found" << endl;
    cout << "Name John Smith " << ((m->hasValue("John Smith")) ? "was " : "was not ") << "found" << endl;
    cout << "Email tababcock@dmacc.edu " << ((m->hasKey("tababcock@dmacc.edu")) ? "was " : "was not ") << "found" << endl;
    cout << "Name Tanner Babcock " << ((m->hasValue("Tanner Babcock")) ? "was " : "was not ") << "found" << endl << endl;

    unsigned int k = m->getKeys();
    m->print();

    for (int x = 0; x < k; x++) {
        m->remove(0);
    }

    cout << endl;
    m->print();
    delete m;
    return 0;
}
