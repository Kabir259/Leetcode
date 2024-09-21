-- select emp.employee_title,
--         emp.sex,
--         avg(emp.salary+bon.bonus) as avg_compensation

-- from sf_employee emp right join sf_bonus bon 
-- on emp.id = bon.worker_ref_id

-- where bon.bonus>0

-- group by emp.employee_title,emp.sex

--  this is wrong as bonus table includes non distinct employees getting bonuses
-- over their lifetime. so you would need to sum and group by employee first the 
-- sf_bonus table and then link it. this can be done by t1 t2 with as condins


with t1 as (
    select emp.id,
            emp.sex,
            emp.employee_title,
            sum(emp.salary) as sal
    
    from sf_employee emp
    
    group by emp.id,
            emp.sex,
            emp.employee_title
)
, t2 as (
    select bon.worker_ref_id,
            sum(bon.bonus) as bonny
    
    from sf_bonus as bon
    
    group by bon.worker_ref_id
)

select t1.employee_title,
        t1.sex,
        avg(t1.sal+t2.bonny) as avg_compensation

from t1 inner join t2 on t1.id = t2.worker_ref_id

where t2.bonny>0

group by t1.employee_title,
            t1.sex


