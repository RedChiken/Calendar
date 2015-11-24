[time.cpp]
class about time table.
it always save time as hour(int), min(int), and sec(double).
it can make you make time to string form
(HH:MM:SS. this is standard form in this project).

and it need to implements operator overide.


[Schedule.cpp]
this class is form of schedule.
this class save title, time that schedule starts and ends, and context as a string.
also it can have that schedule is end or not(bool).

but save end(bool) and some operate overiding is not implemented yet.


[FileLibrarian.cpp]
this class is called singleton.
it mean it can be instancalize once in code.
FileLibrarian.cpp has all of code about schedule.
you just call code that you need in that class.

write schedule need to call 	addSchedule(Schedule, string).
delete Schedule need to call 	deleteSchedule(Schedule, string).

repeated schedule writing need to call		recursiveWrite(String, int)
set Schedule in some range need to call		rangeWrite(Schedule, Schedule)
if you add some condition about it, then call	rangeWrite(Schedule, Schedule, bool)


------------------------------------------------------------------------------------

also, i will use test Program personally. 
it can tell you how to use function, but please don't touch that.

SearchSchedule.cpp is like a additional class.
if i have time, then i will add so much conditions to add Schedule.

