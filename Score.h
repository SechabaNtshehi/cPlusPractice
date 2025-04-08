//Code taken from book

#include <string>
#include <stdexcept>
#include <cmath>
#include "GameEntry.h"

#ifndef SCORE_H

class Score{
    public:
        Score(int maxEnt = 0);
        ~Score();
        void add(const GameEntry& e);
        GameEntry remove(int i) noexcept(false);
    private:
        int maxEntries;
        int numEntries;
        GameEntry* entries;

};

#endif

Score::Score(int maxEnt){
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Score::~Score(){
    delete[] entries;
}

void Score::add(const GameEntry& e){

    GameEntry* players = new GameEntry[numEntries];

    int newScore = e.getScore();
    int name_count = 0;

    if(numEntries == maxEntries){
        if(newScore <= entries[maxEntries - 1].getScore()){
            return;
        }
    }
    else numEntries++;

    int i = numEntries - 2;
    while( i >= 0 && newScore > entries[i].getScore()){
        if(entries[i].getName() == e.getName()) name_count++;

        if(name_count >= std::ceil(maxEntries/2)){
            numEntries--;
            return;
        } 

        entries[i + 1] = entries[i];
        i--;
    }

    entries[i + 1] = e;
    return;
}

GameEntry Score::remove(int i){
    if((i < 0) || (i > maxEntries)){
        throw std::out_of_range("Invalid index");
    }

    GameEntry tmp = entries[i];

    for(int j = i + 1; j < maxEntries; j++){
        entries[j - 1] = entries[j];
    }

    numEntries--;
    return tmp;
}