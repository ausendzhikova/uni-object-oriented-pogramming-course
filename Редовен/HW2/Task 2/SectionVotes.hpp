#pragma once
#include <iostream>
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes {
private:
    int party1Votes, party2Votes, party3Votes;
public:
    SectionVotes() = default;
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);
    SectionVotes(const SectionVotes&);

    int votesForParty(Party) const;
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& obj);
    friend std::istream& operator>>(std::istream& in, SectionVotes& obj);
};