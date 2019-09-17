const DecreaseFactorPerSecond = 0.05;

class TrendCalculator
{
	constructor(value = undefined)
	{
		// Current calculated value.
		// @type {Number}
		this._value = value;

		// Highest seen value.
		// @type {Number}
		this._highestValue = value;

		// NOTE: Not used for now since, somehow (idea feliz), we are using
		// this._highestValueAt instead.
		// Last time update() was called (in ms).
		// @type {Number}
		// this._lastUpdateAt = Date.now();

		// Time in which highest value was set.
		// @type {Number}
		this._highestValueAt = Date.now();
	}

	get value()
	{
		return this._value;
	}

	update(value)
	{
		const now = Date.now();
		// const elapsedMs = now - this._lastUpdateAt;
		const elapsedMs = now - this._highestValueAt;
		const elapsedSeconds = elapsedMs / 1000.0;

		// NOTE: Not used for now.
		// this._lastUpdateAt = now;

		// If new value is bigger or equal than current, use it.
		if (value >= this._value)
		{
			this._value = value;
			this._highestValue = value;
			this._highestValueAt = now;
		}
		// Otherwise decrease current value.
		else
		{
			this._value = Math.max(
				value,
				this._highestValue - (this._highestValue * elapsedSeconds * DecreaseFactorPerSecond)
			);
		}
	}
}

module.exports = TrendCalculator;
