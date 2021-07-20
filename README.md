# push_swap

TODO: this readme...

42's project push_swap.

Final grade: 125/100

### Results:
| list size | n operations |
|-----      |-----         |
| 5 | 9 (max) |
| 100 | ~ 650 |
| 500 | ~ 5050 |

### Usage:
`make` will compile __push_swap__ and __checker__ programs

Example usage:
```
ARG="5 4 3 2 1"
./push_swap $ARG
./push_swap $ARG | ./checker $ARG
```

### The algos:  
(adaptations of...)
- merge sort
- quick sort
- insertion sort
- an algo that mixes quick sort and insertion sort

\+ hard-coded optimal solutions to lists of size up to 4 (base case for the recursive algos)
