/* Latice paths
This problem does not require any programing
It is sloved by the non-negative stars
and bars theorem. There are 20 down and 20 right
moves to take in some order. The down moves can 
be viewed as bars | and right moves as stars *.
20 bars gives 21 partitions to house the 20 items.
binom((20 + 21 -1), 20) gives the answer to the problem. 
*/