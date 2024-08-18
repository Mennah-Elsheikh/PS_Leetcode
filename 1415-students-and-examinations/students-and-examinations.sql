/* Write your T-SQL query statement below */
SELECT 
    s.student_id, 
    s.student_name, 
    sb.subject_name, 
    COUNT(e.subject_name) AS attended_exams
FROM 
    Students as s 
CROSS JOIN 
    Subjects as sb 
LEFT JOIN 
    Examinations as e ON s.student_id = e.student_id and e.subject_name = sb.subject_name 
GROUP BY 
    s.student_id, 
    s.student_name, 
    sb.subject_name
ORDER BY --- it is required in the question :) 
    s.student_id, 
    sb.subject_name;
