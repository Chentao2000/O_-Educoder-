-- Write your SQL here --
CREATE VIEW v_teachers AS
(
	SELECT c.teacher_id,t.name,t.email,t.age,
	t.country, SUM(c.student_count) AS student_count
	FROM courses c
	LEFT JOIN teachers t 
	ON c.teacher_id = t.id 
	GROUP BY (c.teacher_id)
)
