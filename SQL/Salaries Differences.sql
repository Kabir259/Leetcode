-- first find marketing max salary
with container1 as (
    select d.department, 
            max(e.salary) as max_mark -- using agg fx always means you will use group by in the end
    
    from db_employee e
    
    inner join db_dept d on d.id = e.department_id
    
    where d.department = 'marketing'
    
    group by d.department
), -- dont forget the , while using multiple with as


-- now find engg max salary
container2 as (
    select d.department, 
            max(e.salary) as max_engg
    
    from db_employee e
    
    inner join db_dept d on d.id = e.department_id
    
    where d.department = 'engineering'
    
    group by d.department
)

select ABS(container1.max_mark - container2.max_engg) as salary_diff

from container1,
        container2