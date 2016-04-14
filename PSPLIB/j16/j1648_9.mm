************************************************************************
file with basedata            : md240_.bas
initial value random generator: 22256476
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  121
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       21       11       21
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           8  11  14
   3        3          3           5   6  10
   4        3          3           5   7  15
   5        3          1           9
   6        3          3           7   9  13
   7        3          1          12
   8        3          3           9  15  16
   9        3          1          12
  10        3          3          11  14  16
  11        3          1          12
  12        3          1          17
  13        3          3          14  16  17
  14        3          1          15
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1       3    6    5    6
         2     2       2    4    4    5
         3     3       2    4    2    5
  3      1     1       3    8    4    7
         2     3       2    7    2    6
         3     4       2    6    1    6
  4      1     2       4    3   10    9
         2     5       2    3    9    8
         3     7       1    3    9    5
  5      1     4       7    9    7    4
         2     6       7    8    6    3
         3     7       6    6    6    3
  6      1     1       3    2    7    3
         2     6       2    2    5    3
         3     7       2    2    3    2
  7      1     7      10    6    5    8
         2     7       8    7    4    8
         3     8       5    5    3    8
  8      1     4       8   10    2    8
         2     8       6    7    2    5
         3     9       3    5    2    3
  9      1     2      10    7    9    6
         2     2      10    4    7    8
         3     9       6    3    4    5
 10      1     1      10    3    7    9
         2     4       8    2    5    8
         3     9       8    1    3    7
 11      1     1       3    8    4    2
         2     6       3    8    3    2
         3     7       3    7    3    2
 12      1     9       6    1    8    3
         2    10       6    1    6    3
         3    10       2    1    7    2
 13      1     5       3    2    4    4
         2     6       2    2    4    3
         3    10       2    2    4    2
 14      1     5       9    9    4   10
         2     6       4    7    2   10
         3     6       6    5    4   10
 15      1     6       8    9    7    7
         2     7       5    7    7    6
         3     9       2    4    6    1
 16      1     3       9    5    4    2
         2     5       8    3    4    1
         3    10       7    2    3    1
 17      1     3      10    7    6    8
         2     5       9    3    6    8
         3     6       7    1    5    7
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   38   36   78   84
************************************************************************
