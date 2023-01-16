-- Write your SQL here --

CREATE  ALGORITHM = MERGE VIEW v_teachers
    (
        id,
        name,
        email,
        age,
        country
    )AS
    SELECT 
            id,
        name,
        email,
        age,
        country
    FROM teachers
    WHERE age > 25;
