************************************************************************
file with basedata            : mm35_.bas
initial value random generator: 317177163
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  12
horizon                       :  90
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     10      0       20        4       20
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          1           7
   3        3          3           5   9  10
   4        3          3           6   7   9
   5        3          1           8
   6        3          1          10
   7        3          2           8  10
   8        3          1          11
   9        3          1          12
  10        3          1          12
  11        3          1          12
  12        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1       9    9    0   10
         2     9       4    7    0   10
         3    10       2    7    3    0
  3      1     1       7    8    0    3
         2     4       3    5    0    2
         3    10       1    5    5    0
  4      1     6       6    6    2    0
         2     6       6    8    0    5
         3     9       3    4    0    4
  5      1     3       8    5   10    0
         2     6       8    5    8    0
         3    10       7    4    7    0
  6      1     8       5    7    0    3
         2     8       6    7    0    2
         3     8       8    7    0    1
  7      1     3       7    9    7    0
         2     5       6    5    0    6
         3     9       6    3    6    0
  8      1     9       9    9    0    6
         2     9       6    6    7    0
         3    10       3    5    0    7
  9      1     2       6   10    0    9
         2     7       5    9    0    6
         3    10       4    7    3    0
 10      1     2      10    6    7    0
         2     3       9    6    6    0
         3     9       7    5    0    3
 11      1     2       6    8    0    6
         2     2       8    7    9    0
         3     5       4    4    3    0
 12      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   10   11   39   37
************************************************************************
