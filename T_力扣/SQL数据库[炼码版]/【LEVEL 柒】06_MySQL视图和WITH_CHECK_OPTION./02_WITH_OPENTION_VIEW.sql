-- Write your SQL here --
CREATE OR REPLACE VIEW v_CN_teachers AS
SELECT *
FROM teachers
WHERE country = 'CN'
