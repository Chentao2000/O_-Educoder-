-- Write your SQL here --
CREATE VIEW v_courses
AS 
    SELECT courses.id,courses.name,courses.student_count
    FROM courses
    LEFT JOIN teachers 
    ON courses.teacher_id = teachers.id
    WHERE teachers.country NOT IN('USA','JP')OR teachers.country IS NULL
