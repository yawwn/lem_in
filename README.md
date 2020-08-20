# lem_in
### Score 100/100
##### Mandatory
100/100

### Challenge
A path finding algorithm.  
Move ants from start to end inside a colony comprised of rooms and tunnels.
The goal is to find the quickest way to move ants between the start and end.
In each room can be only 1 ant (except start and end).

###  How to run
```console
git clone https://github.com/yawwn/lem_in lem_in
cd lem_in
make
./lem_in < map
```
### The algortihm

The search for the optimal (for a given number of ants) flow is performed using the Edmonds-Karp algorithm.
We find shortest ways from start to end, mark them as visited and save them.
We then used another algorithm to take the valid paths from smallest to largest and determine how many of them we should use to get all the ants to the end of the map as quickly as possible.
