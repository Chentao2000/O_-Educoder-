
-- 张三在宿舍里打游戏，今天运气不太好，总是被匹配的队友坑，气得张三直接就把游戏给卸载了。没心情去吃饭的张三打开 QQ，
-- 发现有 999+ 的信息，原来是学校的老师给他发来的消息，
-- 想要他帮忙创建一个 SQL 视图 v_best_teachers，要他赶紧写好发过去。张三看了看需求，边看要求边写 SQL，结果发现...不对！
-- 学校的要求是查出每个国家最受欢迎的老师信息（听课学生数越多越受欢迎），并按国籍升序排序。
-- 现在张三在知识分享过程中，拿这道题来考你，并嘲讽你不能做出来……小伙子，打脸张三的时候到了，还在等什么 ？冲

-- Write your SQL here --
create or replace view v_best_teachers  as 
select id as teacher_id, student_count,country,email
    from (
        select a.id, email,country,sum(student_count) as student_count
        from teachers a
        inner  join courses b 
        on a.id = b.teacher_id 
        group by a.id, email,country
        ) 
        tt1 -- 数据汇总，处理一个老师教授两种课程情况
where tt1.student_count in  
    (select  max(student_count) as student_count
    from  
        (select a.id , email,country,sum(student_count) as student_count
        from teachers a
        inner  join courses b 
        on a.id = b.teacher_id 
        group by a.id , email,country 
        )tt2
    where tt1.country = tt2.country 
    ) --关联子查询，查一个国家哪个教课听课最多的学生数
order by country;
