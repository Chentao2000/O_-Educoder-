-- 张三最近对 MySQL 数据库感兴趣，决定要好好学习数据库，但...学习的道路总是充满艰辛的。
-- 张三今天遇到了一个难题，他左思右想、苦思冥想、茶不思饭不想也没能想出解决办法。

-- 情况是这样的，现有 teachers 表中记录着离职的教师信息，id 的值即是教师离职的顺序，
-- 在 courses 表中记录着每个教师教授的课程信息，关联 id 为 teacher_id。现在知道教师是以国籍来分团队的，
-- 且每个团队的成立至少有 3 个教师，若是一个教师团队集体离职，则在 teachers 表中信息记录为连续且国籍相同，
-- 现在需要统计每一个教师团队集体离职会有多少学生需要等待新的教师，
-- 结果按团队国籍排序。他需要创建一个视图 v_courses_teachers 来解决这个问题，同学们快来帮帮张三小伙子吧 ~


-- Write your SQL here --
-- 思路：
-- 找出teachers表中信息记录为连续的，两个teachers表join到一起，t1.id=t2.id-1 or t1.id=t2.id+1
-- 以上再与课程表join，id去重
-- 按照国家分组，计算出每个组的学生总数
create view v_courses_teachers as (
    select tt.country,sum(tt.student_count) student_count 
    from (
        select distinct t1.id,t1.country,c.student_count
        from teachers t1 left join teachers t2
        on t1.id=t2.id-1 or t1.id=t2.id+1
        left join courses c on t1.id=c.teacher_id
        where t1.country=t2.country
    ) tt
    group by tt.country
    having count(*)>2
)

