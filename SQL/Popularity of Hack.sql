select e.location,
        avg(cast(h.popularity as float)) as avg_popularity

from facebook_employees e

inner join facebook_hack_survey h on h.employee_id= e.id

group by e.location