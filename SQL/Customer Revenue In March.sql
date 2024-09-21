SELECT cust_id, SUM(total_order_cost)
FROM orders
WHERE EXTRACT(MONTH FROM order_date) = 3 -- dont use datepart(,pnth,order_date)
  AND EXTRACT(YEAR FROM order_date) = 2019
GROUP BY cust_id;
