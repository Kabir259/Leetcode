-- with t1 as (

-- select date, action

-- from fb_friend_requests

-- where action='accepted'
-- )

-- , t2 as (
-- alter table t1
-- add bool_accepted BIT 

-- case
--     when action='accepted' then bool_accepted=1

-- )



with t1 as (
select user_id_sender, 
        user_id_receiver,
        max(case when action='accepted' then date end) as accepted_date, --just use max here so that later you are able to use group by 
        max(case when action='sent' then date end) as sent_date

from fb_friend_requests

group by user_id_sender,user_id_receiver

-- order by sent_date
)

-- , t2 as (

-- select sent_date, count(user_id_sender) as senders,

-- from t1

-- group by sent_date
-- )

-- , t3 as (

-- select accepted_date, count(user_id_receiver) as accepters

-- from t1

-- group by accepted_date
-- )

-- select t2.sent_date, 
--         (1.00*t3.accepters/(t3.accepters+t2.senders)) as percentage_acceptance

-- -- from t2, t3

-- -- -- group by t2.sent_date

-- from t2 join t3 on t2.sent_date = t3.accepted_date

select sent_date, 1.0*count(accepted_date)/count(sent_date)

from t1

group by sent_date