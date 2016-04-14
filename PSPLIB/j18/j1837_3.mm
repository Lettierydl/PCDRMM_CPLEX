************************************************************************
file with basedata            : md293_.bas
initial value random generator: 2012955713
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  20
horizon                       :  150
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     18      0       24        1       24
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          1           6
   3        3          3           5   9  11
   4        3          1           5
   5        3          3          10  15  18
   6        3          3           7   8  13
   7        3          3          10  11  12
   8        3          3          10  11  15
   9        3          1          13
  10        3          1          14
  11        3          2          17  18
  12        3          3          14  15  18
  13        3          2          16  17
  14        3          1          16
  15        3          2          16  17
  16        3          1          19
  17        3          1          20
  18        3          1          20
  19        3          1          20
  20        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     2      10    5    4   10
         2     8       9    3    3   10
         3    10       8    2    2    9
  3      1     4       8    7    7    7
         2     6       8    6    6    5
         3     8       7    3    5    1
  4      1     4       9    9    8    9
         2    10       6    4    8    9
         3    10       7    6    7    9
  5      1     4       5    4    5    5
         2     9       5    1    5    5
         3     9       5    2    5    4
  6      1     2       3    6    4    4
         2     5       2    5    3    3
         3     7       2    4    2    3
  7      1    10       7    9    9    6
         2    10       6   10    9    5
         3    10       9    9    8    1
  8      1     1       5   10    6    7
         2     5       3    9    3    7
         3    10       2    9    2    6
  9      1     1       8    5    6   10
         2     5       6    4    5    4
         3     7       5    4    2    4
 10      1     2       8    9    5    8
         2     5       8    8    4    6
         3    10       7    8    4    5
 11      1     2       5    6   10    4
         2     4       4    4    8    4
         3    10       4    1    6    3
 12      1     3       4    9    8    5
         2     6       4    4    7    5
         3     8       3    2    5    5
 13      1     7       9    8    6    8
         2     7       8    9    9    9
         3     8       8    7    5    8
 14      1     4       4    5   10    5
         2     4       4    5    9    6
         3     7       3    1    8    4
 15      1     2       8    2    5    5
         2     4       8    1    4    5
         3     6       7    1    4    4
 16      1     1       6   10   10    5
         2     2       4    8   10    2
         3     6       2    7   10    2
 17      1     2       7   10    8    7
         2     3       6   10    5    5
         3     6       6    9    3    4
 18      1     5       7    6    5    8
         2     5       8    5    3    9
         3     9       5    5    1    7
 19      1     2       4    6    8    6
         2     8       4    5    7    6
         3     9       4    3    6    5
 20      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   13   14   96   94
************************************************************************
