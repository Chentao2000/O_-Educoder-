-- Write your SQL here --
CREATE OR REPLACE VIEW v_teachers_1
AS 
    SELECT *
    FROM v_teachers
    WHERE age <20 ;
