#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	std::ifstream inFile(filename);
	SectionVotes line(0,0,0);
	if (inFile.is_open()) {
		inFile >> *this;
		inFile.close();
	}
	return;
}

int ElectionResultsDatabase::numberOfSections() const {
	return sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const {
	int votes = 0;
	for (size_t i = 0; i < sections.size(); i++) {
		votes += sections[i].votesForParty(party);
	}
	return votes;
}

Party ElectionResultsDatabase::winningParty() const {
	int votes[3] = { votesForParty(PARTY1),votesForParty(PARTY2),votesForParty(PARTY3) };
	int max = votes[0];
	for (size_t i = 1; i < 3; i++) {
		if (max < votes[i]) {
			max = votes[i];
		}
	}
	if (max == votes[0]) {
		return Party(PARTY1);
	}
	if (max == votes[1]) {
		return Party(PARTY2);
	}
	return Party(PARTY3);
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& obj) {
	for (int i = 0; i < obj.sections.size(); i++) {
		out << obj.sections[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& obj) {
	SectionVotes s;
	while (in >> s) {
		obj.sections.push_back(s);
	}
	
	return in;
}
