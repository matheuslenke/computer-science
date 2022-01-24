SELECT A.customer_name
FROM customer as A JOIN customer as B ON (A.customer_street = B.customer_street AND A.customer_city != B.customer_city)