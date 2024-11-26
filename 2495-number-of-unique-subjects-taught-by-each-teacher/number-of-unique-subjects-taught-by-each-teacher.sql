# Write your MySQL query statement below
select a.teacher_id , count(DISTINCT(b.subject_id)) as cnt
from Teacher a 
join Teacher b
on a.teacher_id = b.teacher_id
group by a.teacher_id