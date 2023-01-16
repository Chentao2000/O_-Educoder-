-- 首先，基于雇员表创建一个名为 vps 的视图，以显示工作头衔为副总裁的雇员，例如销售副总裁、营销副总裁 (VP e.g., VP Sales, VP Marketing）。
CREATE OR REPLACE VIEW vps AS
    SELECT 
        employeeNumber,
        lastname,
        firstname,
        jobtitle,
        extension,
        email,
        officeCode,
        reportsTo
    FROM
        employees
    WHERE
        jobTitle LIKE '%VP%';
        
  -- 现在要求创建一个可更新视图 v_teachers，只允许查看和插入年龄小于 30 岁的教师信息，请编写 SQL 语句实现。
  -- Write your SQL here --
CREATE OR REPLACE VIEW v_teachers AS
SELECT *
FROM teachers
WHERE age < 30
   
