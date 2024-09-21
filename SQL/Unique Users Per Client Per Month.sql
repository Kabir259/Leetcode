select client_id, 
        -- user_id, 
        -- you will already import user_id while counting distinct users 
        -- no need to double import
        -- substring(time_id,6,8) as month, 
        MONTH(time_id) as month,
        count(distinct user_id) as users_num
        
from fact_events

group by client_id, 
        MONTH(time_id)