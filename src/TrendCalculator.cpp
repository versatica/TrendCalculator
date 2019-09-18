#include "TrendCalculator.hpp"
#include <algorithm> // std::min(), std::max()

static constexpr float DecreaseFactorPerSecond{ 0.05f };

TrendCalculator::TrendCalculator()
{

}

uint32_t TrendCalculator::GetValue() const
{
	return this->value;
}

void TrendCalculator::Update(uint32_t value, uint64_t now)
{
	if (this->value == 0u)
	{
		this->value                 = value;
		this->highestValue          = value;
		this->highestValueUpdatedAt = now;

		return;
	}

	// If new value is bigger or equal than current one, use it.
	if (value >= this->value)
	{
		this->value                 = value;
		this->highestValue          = value;
		this->highestValueUpdatedAt = now;
	}
	// Otherwise decrease current value.
	else
	{
		uint64_t elapsedTime = now - this->highestValueUpdatedAt;

		this->value = std::max<uint32_t>(
			value,
			this->highestValue - (this->highestValue * DecreaseFactorPerSecond * (elapsedTime / 1000.0))
		);
	}
}
