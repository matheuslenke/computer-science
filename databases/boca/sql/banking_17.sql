SELECT branch_name, branch_city
FROM branch NATURAL JOIN loan NATURAL JOIN borrower
WHERE borrower.customer_name = 'Smith'