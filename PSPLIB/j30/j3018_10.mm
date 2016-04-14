************************************************************************
file with basedata            : mf18_.bas
initial value random generator: 1055887768
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  32
horizon                       :  229
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     30      0       33        4       33
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2          12  28
   3        3          3           5   6  17
   4        3          2           7  13
   5        3          3           8   9  11
   6        3          3          13  24  26
   7        3          1          21
   8        3          2          18  20
   9        3          3          10  14  27
  10        3          1          12
  11        3          2          13  16
  12        3          3          15  16  30
  13        3          1          23
  14        3          3          15  16  30
  15        3          2          24  26
  16        3          1          19
  17        3          3          22  25  29
  18        3          2          19  25
  19        3          2          22  26
  20        3          3          28  29  31
  21        3          3          22  23  24
  22        3          1          31
  23        3          1          25
  24        3          1          29
  25        3          1          27
  26        3          1          31
  27        3          1          28
  28        3          1          30
  29        3          1          32
  30        3          1          32
  31        3          1          32
  32        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     7       8    0    0   10
         2     7       0    6   10    0
         3     8       0    3   10    0
  3      1     6       5    0    0    6
         2     7       3    0    1    0
         3     8       1    0    0    6
  4      1     2       0    6    5    0
         2     7       0    6    0    3
         3     9       0    5    0    3
  5      1     4       0    4    0    9
         2     8       1    0    5    0
         3    10       0    2    0    9
  6      1     4       0   10    8    0
         2     7       0    6    0    7
         3     9       0    2    0    2
  7      1     4       0    5    9    0
         2     6       0    4    0    4
         3     8       0    2    8    0
  8      1     5       0    4    0    8
         2     7       0    3    0    7
         3     9       0    2    0    5
  9      1     4       0    6    0    4
         2     5      10    0    0    3
         3     8       0    5    0    1
 10      1     6       0    2    4    0
         2     6       3    0    4    0
         3     7       3    0    0    7
 11      1     2       0    7    6    0
         2     8       5    0    5    0
         3     8       0    7    0    9
 12      1     1       0    4    0    7
         2     2       5    0    9    0
         3     4       0    3    9    0
 13      1     1       0    9    5    0
         2     1       3    0    0    7
         3     1       5    0    5    0
 14      1     3       0    6    9    0
         2     7       0    5    7    0
         3     9       0    5    0    2
 15      1     3       9    0    5    0
         2     5       0    8    0   10
         3     7       8    0    5    0
 16      1     2       0    8    0   10
         2     4       0    7    9    0
         3     5       1    0    9    0
 17      1     5       0    9    0    5
         2     5       4    0    9    0
         3     9       0   10    0    4
 18      1     2       6    0    0   10
         2     3       5    0    4    0
         3     7       4    0    0    9
 19      1     2       6    0    2    0
         2     5       6    0    1    0
         3     8       0    1    0    6
 20      1     5       7    0    0    7
         2     7       6    0    8    0
         3     8       5    0    6    0
 21      1     1      10    0    0    9
         2     4       5    0    0    9
         3     4       5    0    7    0
 22      1     1       6    0    0    6
         2     4       6    0    0    5
         3    10       0    2    0    3
 23      1     6       5    0    0    2
         2     8       0    6    0    2
         3     9       0    3    9    0
 24      1     1       0    5    0    8
         2     3       0    4    0    6
         3     9       5    0    0    3
 25      1     5       4    0    0    9
         2     5       2    0    9    0
         3     9       0    8    0   10
 26      1     3       8    0    0    2
         2     3       0   10    8    0
         3     5       7    0    7    0
 27      1     3       0    6    0    7
         2     9       4    0    0    4
         3    10       0    5    0    3
 28      1     1       2    0    4    0
         2     7       0    4    0    5
         3    10       0    3    1    0
 29      1     1       0    9    6    0
         2     2       3    0    0   10
         3     8       0    2    0    8
 30      1     5       0    2    6    0
         2     5       8    0    6    0
         3     5       0    2    0    4
 31      1     1      10    0    0    5
         2     6       9    0    0    3
         3     8       9    0    4    0
 32      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   16   18  121  153
************************************************************************
