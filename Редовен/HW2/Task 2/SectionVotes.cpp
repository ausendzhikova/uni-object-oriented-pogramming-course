#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
	this->party1Votes = party1Votes;
	this->party2Votes= party2Votes;
	this->party3Votes = party3Votes;

}

SectionVotes::SectionVotes(const SectionVotes& other) {
	party1Votes = other.party1Votes;
	party2Votes = other.party2Votes;
	party3Votes = other.party3Votes;
}

int SectionVotes::votesForParty(Party party) const {
	if (party == Party::PARTY1) {
		return party1Votes;
	}
	if (party == Party::PARTY2) {
		return party2Votes;
	}
	return party3Votes;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& obj) {
	out << obj.party1Votes << ' ' << obj.party2Votes << ' ' << obj.party3Votes << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, SectionVotes& obj) {
	in >> obj.party1Votes>> obj.party2Votes >> obj.party3Votes;
	return in;
}
