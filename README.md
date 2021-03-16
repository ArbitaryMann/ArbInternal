# arbinternal-1.40
## ArbInternal is an open sourced project which offers you an ability to control all over the ENet Packets on official growtopia client.
### Special Thanks to
#### Arbitary#1234 (Development)
#### iProgramInCpp#0001 (some tips on reversal)

# Licensed

<img src="https://camo.githubusercontent.com/400c4e52df43f6a0ab8a89b74b1a78d1a64da56a7848b9110c9d2991bb7c3105/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4c6963656e73652d47504c76332d626c75652e737667">


### Strings to find offsets
 
 ```
 SendPacket IDA (Pseudocode)
 sub_1400132E0(v36, "action|quit_to_exit", 0x13ui64);
 v20 = sub_1400E1D20(v19);
 0x41C620 -->sub_14041C620(3i64, v36, *(_QWORD *)(*(_QWORD *)(v20 + 3784) + 168i64));```
 
 LogToConsole IDA (Pseudocode)<br />
 
 v42 = "Located `wserver``, connecting...``";
 0x37DCD0 -->  sub_14037DCD0(v42); (v42 -> fmt --> aka the msg to send)
```
### Libs
MinHook<br />
IMGui<br />
Proton (not much but using it)

### Screenshots
<details>
<img src="https://github.com/ArbitaryMann/ArbInternal/blob/main/resources/peery.gif?raw=true">
</details>
