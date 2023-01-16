-- Write your SQL here --
create or replace view v_mydream as 
select teacher_name,course_name,student_count
from 
(  select a.name as teacher_name,b.name as course_name,
    student_count,
    rank() over(partition by a.id order by student_count desc) as rnum
    from teachers a 
    left join  courses b 
    on a.id =b.teacher_id 
) t 
where t.rnum = 1
order by teacher_name;
