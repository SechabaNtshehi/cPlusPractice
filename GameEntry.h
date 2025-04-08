//Code taken from book

#include <string>

#ifndef GAMEENTRY_H

class GameEntry{
    public:
        GameEntry(const std::string& n ="", int s = 0);
        std::string getName() const;
        int getScore() const;

    private:
        std::string name;
        int score;
};

#endif

