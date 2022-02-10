# VaccineRegist
## High Level Test Plan
|  ID NUM  | Description | Input | Expected output | Actual Output |
| --- | --- | --- | --- | --- |
| 01 | patient registration status | 123 (aadhar no) | {-1} |  (not found) |
| 02 | patient registration status | 123 (aadhar no) | {0,1} |  (found) |
| 03 | patient vaccination status | 3 (patient id) | {>0} | (vaccinated) |
## Low Level Test Plan
| Test ID | Description | Input | Expected output | Actual Output |
| --- | --- | --- | --- | --- |
| 01 | registration status | 125 (aadhar no) | 0 | 0 (registered, not vaccinated) |
| 02 | registration status | 130 (aadhar no) | 1 | 1 (registered, vaccinated) |
| 03 | vaccination status | 3 (patient id) | 1 | 1 (first dose) |
| 04 | vaccination status | 3 (patient id) | 2 | 2 (second dose) |
| 05 | vaccination status | 3 (patient id) | 3 | 3 (already vaccinated) |