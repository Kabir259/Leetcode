select top 5
    product_id,
        -- cost_in_dollars*units_sold as revenue
        -- i know that i will ret the max revunue generating items
        -- so i know i need to do a group by for the porduct_id
        -- for the derived value, i wiil do a summation first
        sum(cost_in_dollars*units_sold) as revenue

from online_orders

where date <= '2022-06-30' and date >= '2022-01-01' 

group by product_id

order by revenue desc