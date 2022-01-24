SELECT B.branch_name
FROM branch as B JOIN branch as C ON B.assets > C.assets
WHERE	C.branch_city = 'Brooklyn'