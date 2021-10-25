# gcc profile guided optimizations in g++

Created: 2021-10-25 09:36:19 +0200

Modified: 2021-10-25 09:36:23 +0200

---


After the program exits, it will dump all this data into *.gcda files, which are essentially log data for a test run. After rebuilding the application with **-fprofile-use**flag, GCC will take the *.gcda log data into account when doing its optimizations, usually increasing the performance significantly. Of course, this depends on many factors.



Relevant für die Stadtauswertung, der Rest der Jobs sollte schon „schlank" sein.



Nachtrag: die beiden entstehenden Dateien liegen bei den erzeugten Object-Dateien


