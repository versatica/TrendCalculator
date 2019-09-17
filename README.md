# TrendCalculator

An algorithm to ease off decreasing values based on a constant factor, an elapsed time and (probably) also on currently highest value seen.


## Overview

The `TrendCalculator` is provided with an initial value and later new input values are given (via the `update()` method). Upon updated values, the `TrendCalculator` computes the new "current value".

* If the new given value is higher or equal than the current value, the current value must be set to it. This is, higher values must automatically update the current value to them.
* Otherwise, if the new given value is less than the current value, the algorithm must ease it off to produce a value slightly lower than the current value. And such a relaxed value must depend on the elapsed time.


## Expected Results

Let's assume we have `trendA` which is a `TrendCalculator` with initial value of 1000.

* The current value of `trendA` must be 1000.
* After 1 second, `trendA.update(500)` is called.
* The new current value (`trendA.value`) must be something lower than 1000. Let's say 990.
* After another second, `trendA.update(500)` is called again.
* The new current value (`trendA.value`) must be something lower than 990. Let's say 980.

Let's assume we have `trendB` which is a `TrendCalculator` with initial value of 1000.

* The current value of `trendB` must be 1000.
* After 2 second, `trendB.update(500)` is called.
* The new current value (`trendB.value`) must be something lower than 1000. Let's say 980.

This is, in both cases the initial values were the same (1000) and we have then called `update(500)` in both. In the former, 2 times in 2 seconds. In the latter, 1 time in 2 seconds.

The algorithm is supposed to produce the same current value in both cases. This is, it should not matter that `update(X)` is called multiple times with the same `X` value or just once.


## Usage

Just run:

```bash
$ node index.js
```

It will run two tests (see [index.js](./index.js) file) that will produce the following results (which obviously show that the algorithm does not work as expected yet):

```
$ node index.js

>>> running test 1:
--- initial trend value: 1000
--- trend.update(500) [total elapsed ms:500, trend value:974]
--- trend.update(500) [total elapsed ms:1000, trend value:936]
--- trend.update(500) [total elapsed ms:1500, trend value:898]
--- trend.update(500) [total elapsed ms:2000, trend value:860]
--- trend.update(500) [total elapsed ms:2500, trend value:822]
--- trend.update(500) [total elapsed ms:3000, trend value:785]
--- trend.update(500) [total elapsed ms:3500, trend value:747]
--- trend.update(500) [total elapsed ms:4000, trend value:709]
--- trend.update(500) [total elapsed ms:4500, trend value:671]
--- trend.update(500) [total elapsed ms:5000, trend value:632]
--- trend.update(1000) [total elapsed ms:5500, trend value:1000]

>>> running test 2:
--- initial trend value: 1000
--- trend.update(500) [total elapsed ms:1000, trend value:949]
--- trend.update(500) [total elapsed ms:2000, trend value:886]
--- trend.update(500) [total elapsed ms:3000, trend value:824]
--- trend.update(500) [total elapsed ms:4000, trend value:761]
--- trend.update(500) [total elapsed ms:5000, trend value:698]
--- trend.update(1000) [total elapsed ms:6000, trend value:1000]

>>> done
```

Once the algorithm is fixed, trend values in both tests should be the same for the same total elapsed time.
