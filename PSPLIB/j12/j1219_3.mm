************************************************************************
file with basedata            : md83_.bas
initial value random generator: 1313832464
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  14
horizon                       :  102
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     12      0       19        3       19
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           6   7   9
   3        3          3           5   6   9
   4        3          3           8   9  10
   5        3          3           7  10  13
   6        3          2          11  13
   7        3          1          12
   8        3          2          11  13
   9        3          2          11  12
  10        3          1          12
  11        3          1          14
  12        3          1          14
  13        3          1          14
  14        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     6       8    0    0    7
         2     7       8    0    0    2
         3     7       0    6    8    0
  3      1     2       6    0    6    0
         2     2       0    6    7    0
         3    10       0    5    0    3
  4      1     2       8    0    3    0
         2    10       0    1    0    5
         3    10       4    0    0    6
  5      1     6       0    7    1    0
         2     7      10    0    0    8
         3     9       0    6    0    8
  6      1     3       7    0    9    0
         2     5       0    5    5    0
         3     8       7    0    0    2
  7      1     1       6    0    9    0
         2     5       0    6    4    0
         3     5       0    5    0    3
  8      1     4       0    8    0    6
         2     6       0    8    3    0
         3    10       0    7    0    3
  9      1     1      10    0   10    0
         2     5       0    7    5    0
         3     6       8    0    5    0
 10      1     6       0    6    0    4
         2     8       2    0    0    3
         3    10       1    0    8    0
 11      1     5       7    0    0    9
         2     7       0    4    0    8
         3    10       7    0    0    8
 12      1     5       0    8    8    0
         2     6       4    0    0    3
         3     7       0    6    7    0
 13      1     1       8    0    0    4
         2     4       4    0    7    0
         3    10       4    0    5    0
 14      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   21   26   56   43
************************************************************************
