# arbinternal-1.40
Supported on 3.59<br />

# Strings to find offsets
 
 ```SendPacket IDA (Pseudocode)<br />
 sub_1400132E0(v36, "action|quit_to_exit", 0x13ui64);
 v20 = sub_1400E1D20(v19);
 0x41C620 -->sub_14041C620(3i64, v36, *(_QWORD *)(*(_QWORD *)(v20 + 3784) + 168i64));```

 // LogToConsole IDA (Pseudocode)<br />
 v42 = "Located `wserver``, connecting...``";<br />
 0x37DCD0 -->  sub_14037DCD0(v42); (v42 -> fmt --> aka the msg to send)
```
# Libs
MinHook<br />
IMGui<br />
Proton (not much but using it)
