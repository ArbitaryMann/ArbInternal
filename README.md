# arbinternal-1.40
Latest Update Signed --> 3.59<br />
Author --> Me<br />
# Special Thanks to
#### Arbitary#1234 (Development)
#### iProgramInCpp#0001 (some tips on reversal)
<br />
# Licensed
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![License](https://img.shields.io/badge/License-EPL%201.0-red.svg)](https://opensource.org/licenses/EPL-1.0)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)




# Strings to find offsets
 
 ```
 SendPacket IDA (Pseudocode)
 sub_1400132E0(v36, "action|quit_to_exit", 0x13ui64);
 v20 = sub_1400E1D20(v19);
 0x41C620 -->sub_14041C620(3i64, v36, *(_QWORD *)(*(_QWORD *)(v20 + 3784) + 168i64));```
 
 LogToConsole IDA (Pseudocode)<br />
 
```v42 = "Located `wserver``, connecting...``";
 0x37DCD0 -->  sub_14037DCD0(v42); (v42 -> fmt --> aka the msg to send)
```
# Libs
MinHook<br />
IMGui<br />
Proton (not much but using it)

# Screenshots
<details>
![Alt Text](https://github.com/ArbitaryMann/ArbInternal/blob/main/resources/peery.gif?raw=true)
</details>
