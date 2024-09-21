select 
        -- department,
        -- joining_date,
        -- only select what you are printing in the final df
        count(*) as no_of_employees


from worker

where department = 'Admin' and MONTH(joining_date)>=4