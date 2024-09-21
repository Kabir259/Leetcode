-- with t1 as (
--     select p.id, p.title, p.budget, 
--             DATEDIFF(day, p.start_date, p.end_date) as duration_in_days
    
--     from linkedin_projects p
-- )

-- , t2 as (
--     select t1.id as project_id, t1.title, t1.budget, t1.duration_in_days,
--             ep.emp_id
    
--     from t1 inner join linkedin_emp_projects ep 
--     on ep.project_id = t1.id

-- )

-- , t3 as (
--     select t2.project_id, t2.title, t2.budget,
--             t2.emp_id, e.id, (e.salary/365)*t2.duration_in_days*1.00 as costOfEmp_projectDuration
    
--     from t2 inner join linkedin_employees e
--     on t2.emp_id = e.id

-- )


-- select t3.title, t3.budget, 
--         ROUND(sum(t3.costOfEmp_projectDuration),0) as prorated_employee_expense


-- from t3

-- GROUP BY t3.title, t3.budget

-- having sum(t3.costOfEmp_projectDuration)>t3.budget








with t1 as (
    select p.id, p.title, avg(p.budget) as budget, 
            DATEDIFF(day, max(p.start_date), min(p.end_date)) as duration_in_days,
            sum(e.salary) as sal
    
    from linkedin_projects p 
    join linkedin_emp_projects ep on ep.project_id = p.id
    join linkedin_employees e on e.id = ep.emp_id
    
    group by p.id, p.title
)

, t2 as (

    select t1.title, t1.budget, 
            ROUND((1.00*t1.sal/365)*t1.duration_in_days, 0) as prorated_employee_expense
    
    from t1 

)

select t2.title,t2.budget,t2.prorated_employee_expense

from t2

where t2.budget < t2.prorated_employee_expense



