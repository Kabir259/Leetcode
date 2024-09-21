select department,
        count(worker_id) as no_of_workers

from worker

where MONTH(joining_date) >= 4

group by department

order by no_of_workers desc