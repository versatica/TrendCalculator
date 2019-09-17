const TrendCalculator = require('./TrendCalculator');

const tests =
[
	{
		id          : '1',
		value       : 1000,
		updates     :
		[
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 500 },
			{ elapsedMs: 500, value: 1000 }
		]
	},
	{
		id          : '2',
		value       : 1000,
		updates     :
		[
			{ elapsedMs: 1000, value: 500 },
			{ elapsedMs: 1000, value: 500 },
			{ elapsedMs: 1000, value: 500 },
			{ elapsedMs: 1000, value: 500 },
			{ elapsedMs: 1000, value: 500 },
			{ elapsedMs: 1000, value: 1000 }
		]
	}
];

async function runTests()
{
	for (const test of tests)
	{
		console.log('>>> running test %s:', test.id);

		const trend = new TrendCalculator(test.value);
		const startedAt = Date.now();
		let totalElapsedMs = 0;

		console.log('--- initial trend value: %s', toInteger(trend.value));

		for (const update of test.updates)
		{
			// Wait for given elapsed time.
			await new Promise((resolve) => setTimeout(resolve, update.elapsedMs));

			totalElapsedMs += update.elapsedMs;

			trend.update(update.value);

			console.log(
				'--- trend.update(%s) [total elapsed ms:%s, trend value:%s]',
				update.value, totalElapsedMs, toInteger(trend.value));

			// Cosmetic wait.
			await new Promise((resolve) => setTimeout(resolve, 250));
		}

		console.log('');
	}

	console.log('>>> done');

}

function toInteger(value)
{
	return Number.parseInt(value);
}

runTests();
