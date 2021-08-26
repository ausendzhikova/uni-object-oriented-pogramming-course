#pragma once
class Counter {
protected:
	int initial;
	unsigned step;
public:
	Counter(const Counter& other);
	Counter(int initial=0, unsigned step=1);
	void increment();
	int getTotal() const;
	unsigned getStep() const;
};

