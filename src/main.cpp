#include "TrendCalculator.hpp"
#include <string>
#include <vector>
#include <cstdint>   // uint32_t, etc
#include <cinttypes> // PRIu32, etc
#include <cstdio>

struct TestUpdate
{
	TestUpdate(uint32_t value, uint64_t now) :
		value(value), now(now)
	{

	}

	uint32_t value{ 0u };
	uint64_t now{ 0u };
};

struct Test
{
	Test(std::string name, std::vector<TestUpdate> updates) :
		name(name), updates(updates)
	{

	}

	std::string name;
	std::vector<TestUpdate> updates;
};

int main(int argc, char* argv[])
{
	std::vector<Test> tests {
		{
			"1", // name
			{    // updates
				// value, now
				{ 1000,    0 },
				{  500,  500 },
				{  500, 1000 },
				{  500, 1500 },
				{  500, 2000 },
				{  500, 2500 },
				{  500, 3000 },
				{  500, 3500 },
				{  500, 4000 },
				{  500, 4500 },
				{ 1000, 5000 }
			}
		},
		{
			"2", // name
			{    // updates
				// value, now
				{ 1000,    0 },
				{  500, 1000 },
				{  500, 2000 },
				{  500, 3000 },
				{  500, 4000 },
				{ 1000, 5000 }
			}
		},
		{
			"3", // name
			{    // updates
				// value, now
				{ 1000,     0 },
				{  900,  1000 },
				{  800,  2000 },
				{  700,  3000 },
				{  600,  4000 },
				{  500,  5000 },
				{  400,  6000 },
				{  300,  7000 },
				{  200,  8000 },
				{  100,  9000 },
				{  100, 10000 },
				{  100, 11000 },
				{  100, 12000 },
				{  100, 13000 },
				{  100, 14000 },
				{  100, 15000 },
				{  100, 16000 },
				{  100, 17000 },
				{  100, 18000 },
				{  100, 19000 },
				{  100, 20000 }
			}
		}
	};

	for (auto& test : tests)
	{
		printf(">>> test %s:\n", test.name.c_str());

		TrendCalculator trend;

		for (auto& update : test.updates)
		{
			trend.Update(update.value, update.now);

			printf(
				"    trend.Update(value:%" PRIu32 ", now:%" PRIu64 ") [trend value: %" PRIu32 "]\n",
				update.value,
				update.now,
				trend.GetValue());
		}

		printf("\n");
	}

	printf(">>> done\n");

	return 0;
}
