# Test Plan:

TestID|	Description	                                |ExpI/P |Exp O/P |	Actual Out |	Type Of Test
------|---------------------------------------------|-------|--------|-------------|-------------
  H_01|	 Check if the name is added in record	      |-1     |  	FAIL |  FAIL       |	Technical based
  H_02|	Check if the name is added more than 1      |	2	    |    PASS|	PASS       |	Scenario/Technical
  H_03|	Check for view record	                      |-1	    |    FAIL|	FAIL       |	Technical based
  H_04|	Check if the name matches in record	        |1	    |   PASS |	PASS       |	Scenario/Technical
  H_05|	Check if the name don't matches the record	|-1	    |    PASS|	FAIL       |	Scenario/Technical
  H_06|	exit if the record is completed	            |1	    |    PASS|	PASS       |	Technical based
