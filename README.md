# TrendCalculator

An algorithm to ease off decreasing values based on a constant factor, an elapsed time and (probably) also on currently highest value seen.


## Overview

The `TrendCalculator` is provided with input values (via the `update()` method). Upon updated values, the `TrendCalculator` computes its new "current value".

* If the new given value is higher or equal than the current value, the current value must be set to it. This is, higher values must automatically update the current value.
* Otherwise, if the new given value is less than the current value, the algorithm must ease it off to produce a value slightly lower than the current value. And such a relaxed value must depend on the given "now" (in ms).


## Expected Results

Let's assume we have `trendA`.

* Initially it's provided with a value of 1000.
* The current value of `trendA` must be 1000.
* After 1 second, `trendA.Update()` is called with value 500.
* The new current value (`trendA.GetValue()`) must be something lower than 1000. Let's say 950.
* After another second, `trendA.Update()` is called with value 500 again.
* The new current value (`trendA.GetValue()`) must be something lower than 950. Let's say 900.

Let's assume we have `trendB`.

* Initially it's provided with a value of 1000.
* The current value of `trendB` must be 1000.
* After 2 seconds, `trendB.Update()` is called with value 500.
* The new current value (`trendB.GetValue()`) must be something lower than 1000. Let's say 980.

This is, in both cases the initial values were the same (1000) and we have then called `Update()` on both with value 500. In the former, twice in 2 seconds. In the latter, once in 2 seconds.

The algorithm is supposed to produce the same current value in both cases. This is, it should not matter that `Update()` is called multiple times with the same value or just once.


## Usage

Just run:

```bash
$ ./run.sh
```

It will run some tests (see [src/main.cpp](./src/main.cpp) file) that will produce the following results:

```
$ ./run.sh

>>> running test 1:
    trend.update(value:1000, now:0) [trend value: 1000]
    trend.update(value:500, now:500) [trend value: 975]
    trend.update(value:500, now:1000) [trend value: 950]
    trend.update(value:500, now:1500) [trend value: 925]
    trend.update(value:500, now:2000) [trend value: 900]
    trend.update(value:500, now:2500) [trend value: 875]
    trend.update(value:500, now:3000) [trend value: 850]
    trend.update(value:500, now:3500) [trend value: 825]
    trend.update(value:500, now:4000) [trend value: 800]
    trend.update(value:500, now:4500) [trend value: 775]
    trend.update(value:1000, now:5000) [trend value: 1000]

>>> running test 2:
    trend.update(value:1000, now:0) [trend value: 1000]
    trend.update(value:500, now:1000) [trend value: 950]
    trend.update(value:500, now:2000) [trend value: 900]
    trend.update(value:500, now:3000) [trend value: 850]
    trend.update(value:500, now:4000) [trend value: 800]
    trend.update(value:1000, now:5000) [trend value: 1000]

>>> running test 3:
    trend.update(value:1000, now:0) [trend value: 1000]
    trend.update(value:900, now:1000) [trend value: 950]
    trend.update(value:800, now:2000) [trend value: 900]
    trend.update(value:700, now:3000) [trend value: 850]
    trend.update(value:600, now:4000) [trend value: 800]
    trend.update(value:500, now:5000) [trend value: 750]
    trend.update(value:400, now:6000) [trend value: 700]
    trend.update(value:300, now:7000) [trend value: 650]
    trend.update(value:200, now:8000) [trend value: 600]
    trend.update(value:100, now:9000) [trend value: 550]
    trend.update(value:100, now:10000) [trend value: 500]
    trend.update(value:100, now:11000) [trend value: 450]
    trend.update(value:100, now:12000) [trend value: 400]
    trend.update(value:100, now:13000) [trend value: 350]
    trend.update(value:100, now:14000) [trend value: 300]
    trend.update(value:100, now:15000) [trend value: 250]
    trend.update(value:100, now:16000) [trend value: 200]
    trend.update(value:100, now:17000) [trend value: 150]
    trend.update(value:100, now:18000) [trend value: 100]
    trend.update(value:100, now:19000) [trend value: 100]
    trend.update(value:100, now:20000) [trend value: 100]

>>> done
```
