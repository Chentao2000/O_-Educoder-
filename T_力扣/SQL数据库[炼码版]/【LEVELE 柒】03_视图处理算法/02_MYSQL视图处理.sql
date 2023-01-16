-- Write your SQL here --


-- Write your SQL here --

CREATE ALGORITHM = TEMPTABLE VIEW v_teachers
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
    WHERE country = 'CN';
