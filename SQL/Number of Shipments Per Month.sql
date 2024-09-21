select substring(shipment_date,0,8) as year_month, count(*) as no_of_ships

from amazon_shipment

-- ret {no of ships in a month}

-- The reason you didn't write GROUP BY year_month directly in that query is likely because SQL doesn’t automatically recognize aliases in the GROUP BY clause. In SQL, aliasing (such as substring(shipment_date,0,8) as year_month) is only valid for the SELECT clause and not for the GROUP BY clause.

-- Since year_month is an alias defined in the SELECT statement, it can't be referenced directly in the GROUP BY clause. Instead, you need to repeat the expression (substring(shipment_date, 0, 8)) in the GROUP BY statement.

group by substring(shipment_date,0,8)