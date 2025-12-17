# Philosophers

A pthreads-based solution to the Dining Philosophers problem. Each philosopher is a thread; each fork is protected by a `pthread_mutex_t`. Philosophers are arranged in a circular list.

## Requirements

- POSIX system (macOS/Linux)
- `make`, `gcc` (or compatible), pthreads

## Build

```sh
make
make clean
make re
```

The binary is produced as `./philo`.

## Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- All times are in milliseconds.
- `number_of_philosophers`: 1..200
- `number_of_times_each_philosopher_must_eat`: optional (> 0). If provided, the simulation stops when everyone has eaten this many times.

Examples:
```sh
./philo 5 800 200 200
./philo 5 800 200 200 7
```

Output format:
`<ms_since_start> <philo_id> <action>`

Example actions: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`.

## Implementation notes

- Each philosopher owns one fork (a `pthread_mutex_t`). The left fork is the neighbor’s fork in a circular arrangement.
- Lock order: right then left. Even-indexed philosophers may delay at start to reduce contention.
- Termination:
  - A philosopher “dies” if time since last meal exceeds `time_to_die`.
  - If the optional meals target is provided, the simulation ends once everyone reaches it.
- Single philosopher case: picks one fork, then waits until death (no second fork available).

## Notes

- Use high-resolution sleeps (e.g., `usleep` with periodic checks) to keep timing accurate.
- Avoid deadlocks via consistent fork ordering and slight start-time staggering.