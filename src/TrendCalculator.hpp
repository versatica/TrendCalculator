#ifndef TREND_CALCULATOR_HPP
#define TREND_CALCULATOR_HPP

#include <cstdint> // uint32_t, etc

class TrendCalculator
{
public:
	TrendCalculator();

public:
	uint32_t GetValue() const;
	void Update(uint32_t value, uint64_t now);

private:
	bool started{ false };
	uint32_t value{ 0u };
	uint32_t highestValue{ 0u };
	uint64_t highestValueUpdatedAt{ 0u };
};

#endif
