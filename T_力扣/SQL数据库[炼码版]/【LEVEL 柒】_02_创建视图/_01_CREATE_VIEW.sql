-- Write your SQL here --
CREATE VIEW v_courses_teachers 
AS
    SELECT c.*,t.name as teacher_name,t.email as teacher_email
    -- 潜在bug 命名重复问题
    FROM courses AS c
    LEFT JOIN teachers AS t
    ON t.id = c.teacher_id;
