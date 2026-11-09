# Green Efficiency Analysis

## Measurement Methodology

All three programs were compiled and executed on the same machine, one after
another, with no source changes except the timing code added to
`instrumentation_lab.c`. Each program was run three consecutive times and the
full output of every run was recorded. Timing uses `clock()` from `<time.h>`:
the clock value is read immediately before and after the measured region, and
the difference is divided by `CLOCKS_PER_SEC` to obtain seconds. `clock()`
measures processor time used by the program, not wall-clock time, so waiting
on other processes is mostly excluded.

In `instrumentation_lab.c`, each phase is timed around its single function
call (`build_dataset`, `process_dataset`, `reduce_checksum`). `TOTAL` starts
before the first phase and ends after the last one, so it always covers every
sub-measurement. Printing happens outside all measured regions so that output
cost does not distort the results.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) produced 0.920000 s, 0.921000 s and
0.924000 s. The spread is only 0.004 s, about 0.4%, which shows that repeated
runs of identical work are close but never perfectly identical.

The algorithm comparison showed a very large difference. The naive algorithm
took 1.863000 s, 1.855000 s and 1.859000 s, for an average of 1.859000 s. The
single-pass algorithm reported 0.000000 s in all three runs, meaning it
finished faster than the timer could resolve. The two functions return
different counts: the naive version counted 625,025,000 matches because
it re-scans the prefix of the array for every index, while the single-pass
version counted 25,000. Based on the measurements, the naive implementation is
more than ~1859 times slower than the single-pass one. Counting the work done
explains why: the naive version performs 1,250,025,000 checks (O(n^2)), while
the single-pass version performs 50,000 checks (O(n)), a ratio of about 25,000.

The instrumentation lab reported 0.000000 s for `TOTAL` and every phase on
this machine. With 50,000 elements, each phase is a single linear pass, so the
whole program completes in less than one clock tick. This is itself a result:
linear work on this data size is far below the cost of the quadratic
algorithm.

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts. Runtime is used as a proxy:
while a program runs, the CPU stays busy and draws more power than when idle.
The naive algorithm kept the CPU active for about 1.86 s to answer a question
that the single-pass algorithm answered in under a millisecond. If that code
ran millions of times on a server fleet, the extra CPU time would translate
directly into extra energy use, cooling and cost. Choosing the O(n) solution
removes almost all of that work rather than making the same work slightly
faster.

## Limitations of the Experiment

- `clock()` on this system has a resolution of about 1 ms, so very short
  phases (single-pass counting and all instrumentation phases) were measured
  as 0.000000 s. Their real duration is unknown, only bounded.
- Three runs per program is a small sample; it shows variability but is not
  enough for strong statistics.
- The programs were built with Microsoft's C compiler without optimisation
  because `gcc` was not installed on the test machine. Times with `gcc` and its
  required flags on Linux would differ.
- Runtime is only a proxy for energy; real consumption also depends on CPU
  frequency, power states and other hardware factors that were not measured.

## Practical Engineering Takeaway

Measure before drawing conclusions, and repeat measurements, because single
runs vary. The largest gain in these experiments came from algorithmic
complexity, not from small code tweaks: replacing an O(n^2) loop with an O(n)
loop reduced runtime from about 1.86 s to below the timer resolution. For
efficient and sustainable software, the first question should be how much
work the algorithm performs, and the second should be how to measure it
reliably.
