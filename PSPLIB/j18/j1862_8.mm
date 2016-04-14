************************************************************************
file with basedata            : md318_.bas
initial value random generator: 1390442957
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  20
horizon                       :  141
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     18      0       18        9       18
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           5   6
   3        3          3           9  12  16
   4        3          3           5   6   7
   5        3          2          14  17
   6        3          3           8  10  15
   7        3          2          16  18
   8        3          2          11  12
   9        3          3          13  17  19
  10        3          1          12
  11        3          2          16  19
  12        3          2          14  19
  13        3          2          14  15
  14        3          1          18
  15        3          1          18
  16        3          1          17
  17        3          1          20
  18        3          1          20
  19        3          1          20
  20        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     2       5    6    7    7
         2     3       3    4    6    5
         3     4       2    1    5    3
  3      1     1       6    9    6    7
         2     3       4    8    6    6
         3     6       1    7    1    5
  4      1     2       8    4    7    8
         2     2       7    6    7    8
         3     8       6    3    7    8
  5      1     4       7    8    9    8
         2     9       6    7    7    6
         3    10       6    7    6    6
  6      1     1       6    8    8    5
         2     4       5    7    8    4
         3     7       4    6    7    4
  7      1     6       6    8    8    9
         2     6       6    7    8   10
         3     9       5    4    8    8
  8      1     2       7    5    7    8
         2     6       6    4    7    5
         3     8       5    3    7    4
  9      1     1       9    6   10    7
         2     8       9    6    7    7
         3    10       9    6    5    5
 10      1     4       9    9    5    9
         2     6       7    7    5    6
         3     7       6    7    2    5
 11      1     1       5    3    5    3
         2     7       3    2    5    3
         3     9       3    2    4    2
 12      1     4       6    8    4    5
         2     6       6    5    3    4
         3    10       5    4    3    4
 13      1     7       7   10    5    7
         2    10       6    9    4    4
         3    10       4   10    5    2
 14      1     2       3   10    9    7
         2     5       2   10    7    7
         3     7       2   10    5    4
 15      1     7       8    5    9    9
         2     7       7    6   10    9
         3     8       6    5    8    6
 16      1     1       4    9    7    8
         2     6       4    7    5    7
         3     8       4    6    5    6
 17      1     3       9    9    9    5
         2     3       9   10    8    6
         3     7       8    8    7    1
 18      1     2       3    7    4    8
         2     3       2    4    4    5
         3     8       2    4    3    2
 19      1     3       7    6    7    5
         2     5       6    4    5    4
         3     5       4    5    6    5
 20      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   23   25  127  127
************************************************************************
