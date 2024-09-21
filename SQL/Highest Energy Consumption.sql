with t1 as (
    select * 
    from fb_eu_energy
    
    union
    
    select *
    from fb_asia_energy
    
    union
    
    select * 
    from fb_na_energy
)

, t2 as (
    select date,
            -- max(sum(consumption)) as total
            -- DONT DO AGG(AGG)
            sum(consumption) as total_energy
    from t1
    group by date
)

, t3 as (
    select date,
            total_energy,
            rank() over (order by total_energy desc) as r
    
    from t2
)

select date,
        total_energy

from t3

where r=1