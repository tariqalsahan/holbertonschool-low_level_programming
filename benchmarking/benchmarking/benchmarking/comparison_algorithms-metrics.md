# Comparison Algorithms Metrics

## Raw Output

### Run 1

```
Naive algorithm result: 625025000
Naive algorithm time: 1.863000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

### Run 2

```
Naive algorithm result: 625025000
Naive algorithm time: 1.855000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

### Run 3

```
Naive algorithm result: 625025000
Naive algorithm time: 1.859000 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000000 seconds
```

## Execution Times

| Run | Naive (A) | Single-pass (B) |
|-----|-----------|-----------------|
| 1 | 1.863000 s | 0.000000 s |
| 2 | 1.855000 s | 0.000000 s |
| 3 | 1.859000 s | 0.000000 s |

## Averages

* Naive algorithm (A): (1.863000 + 1.855000 + 1.859000) / 3 = **1.859000 seconds**
* Single-pass algorithm (B): (0.000000 + 0.000000 + 0.000000) / 3 = **0.000000 seconds**

## Relative Difference

The single-pass time is below the resolution of `clock()` (under 0.001 s),
so it is measured as 0.000000 seconds and a direct division is not possible.

* Measured: Implementation A is **more than ~1859 times slower** than B
  (1.859 s / less than 0.001 s).
* Expected from the work done: A performs 50000 x 50001 / 2 = 1,250,025,000
  checks, while B performs 50,000 checks, so A is **~25000 times slower** than B.

## Observations

* The naive algorithm is O(n^2): it re-scans the array from the start for every index.
* The single-pass algorithm is O(n): it visits each element exactly once.
* The naive times are close but not identical across runs (system timing variability).
