with t1 as (

select host_id, nationality, gender

from airbnb_hosts as hosts

)

, t2 as (
select guest_id, nationality, gender

from airbnb_guests as guests

)

select distinct t1.host_id as h, t2.guest_id as g
        -- t1.nationality as host_nat, t2.nationality as guest_nat, 
        -- t1.gender as host_gen, t2.gender as guest_gen

from t1 inner join t2 
on t1.gender = t2.gender and t1.nationality = t2.nationality

-- where t1.gender = t2.gender and t1.nationality = t2.nationality