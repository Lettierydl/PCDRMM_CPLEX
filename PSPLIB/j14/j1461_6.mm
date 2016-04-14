************************************************************************
file with basedata            : md189_.bas
initial value random generator: 759847470
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  16
horizon                       :  107
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     14      0       13        5       13
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           5   6
   3        3          3           5   6  10
   4        3          3           7   8  11
   5        3          3           8   9  12
   6        3          3           8  11  14
   7        3          1           9
   8        3          2          13  15
   9        3          3          13  14  15
  10        3          1          12
  11        3          1          15
  12        3          1          13
  13        3          1          16
  14        3          1          16
  15        3          1          16
  16        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     3       9   10    3    8
         2     4       5    6    3    6
         3     6       3    2    2    6
  3      1     2       6    4    7    6
         2     8       5    4    4    5
         3    10       2    3    4    3
  4      1     4       6    9    9    4
         2     5       6    7    7    4
         3     8       5    7    4    4
  5      1     1       8    7    9    8
         2     5       6    7    7    8
         3    10       2    6    3    7
  6      1     6       5    7    9    7
         2     6       5    6    6    8
         3    10       3    5    4    3
  7      1     1      10    4    9    4
         2     2       9    4    8    4
         3     9       9    4    7    3
  8      1     1       3    8    7    9
         2     3       3    7    5    7
         3     7       3    3    3    3
  9      1     1       6    8    9   10
         2     3       6    6    9    9
         3     3       5    8    9    9
 10      1     2       7    4    7    8
         2     3       5    3    7    7
         3     7       3    2    6    6
 11      1     3       8    7    9    7
         2     3       7    7   10    7
         3     7       5    5    7    6
 12      1     3       5    5    7    2
         2     4       5    3    3    2
         3     5       4    1    1    1
 13      1     1       9    9    2    7
         2     9       8    8    2    6
         3    10       5    7    1    6
 14      1     3      10   10    6    5
         2     6      10    9    4    5
         3    10       9    9    4    2
 15      1     1       8    7    4    8
         2     2       8    4    4    6
         3     5       8    2    3    6
 16      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   14   14   98   94
************************************************************************
