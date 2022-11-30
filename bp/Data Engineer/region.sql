select *
from region
where datediff(day, date_column, GETDATE()) < 28
order by revenue desc limit 4, 1;

--assumption: the region table has columns date_column and region_name
